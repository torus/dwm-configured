void
elit(Monitor *m)
{
	unsigned int i, n, h, mw, my, ty, bw;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	if (n == 1)
		bw = 0;
	else
		bw = borderpx;
	if (n > m->nmaster)
		mw = m->nmaster ? m->ww * m->mfact : 0;
	else
		mw = m->ww;
	for (i = my = ty = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++)
		if (i < m->nmaster) {
			h = (m->wh - my) / (MIN(n, m->nmaster) - i);
			resize(c, m->wx + m->ww - mw, m->wy + my, mw - 2*bw, h - 2*bw, bw, 0);
			if (my + HEIGHT(c) < m->wh)
				my += HEIGHT(c);
		} else {
			h = (m->wh - ty) / (n - i);
			resize(c, m->wx, m->wy + ty, m->ww - mw - 2*bw, h - 2*bw, bw, 0);
			if (ty + HEIGHT(c) < m->wh)
				ty += HEIGHT(c);
		}
}
