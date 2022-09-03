#include <cstdio>

struct node {
	int x, y;
	node *l, *r, *p;
} *T, a[300003];
int an;

inline void Lazy(node *x) {
	if (x->y) {
		if (x->l) x->l->y += x->y;
		if (x->r) x->r->y += x->y;
		x->x += x->y;
		x->y = 0;
	}
}

inline void Rotate(node *x) {
	node *p = x->p;
	node *b;
	if (x == p->l) {
		p->l = b = x->r;
		x->r = p;
	}
	else {
		p->r = b = x->l;
		x->l = p;
	}
	x->p = p->p;
	p->p = x;
	if (b) b->p = p;
	(x->p ? p == x->p->l ? x->p->l : x->p->r : T) = x;
}

inline void Splay(node *x) {
	while (x->p) {
		node *p = x->p;
		node *g = p->p;
		if (g) Rotate((x == p->l) == (p == g->l) ? p : x);
		Rotate(x);
	}
}

node *lower_bound(int x) {
	node *p, *z;
	p = T;
	z = NULL;
	while (p) {
		Lazy(p);
		if (p->x < x) p = p->r;
		else {
			z = p;
			p = p->l;
		}
	}
	return z;
}

node *upper_bound_m1(int x) {
	node *p, *z;
	p = T;
	z = NULL;
	while (p) {
		Lazy(p);
		if (p->x < x) {
			z = p;
			p = p->r;
		}
		else p = p->l;
	}
	return z;
}

int main() {
	node *p, *z, **w;
	int i, n, x, y, r = 0;
	scanf("%d", &n);
	T = a;
	while (n--) {
		scanf("%d%d", &x, &y);

		z = lower_bound(y);
		if (z) {
			r--;
			Splay(z);
			if (z->l) {
				if (z->r) {
					p = z->l;
					T = p;
					T->p = NULL;
					while (p->r) p = p->r;
					Splay(p);
					p->r = z->r;
					p->r->p = p;
				}
				else {
					T = z->l;
					T->p = NULL;
				}
			}
			else if (z->r) {
				T = z->r;
				T->p = NULL;
			}
			else T = NULL;
		}

		z = upper_bound_m1(y);
		Splay(z);
		if (z->r) z->r->y--;

		z = upper_bound_m1(x);
		Splay(z);
		if (z->r) z->r->y++;

		p = T;
		while (p) {
			Lazy(p);
			z = p;
			if (p->x < x) {
				w = &p->r;
				p = p->r;
			}
			else {
				w = &p->l;
				p = p->l;
			}
		}
		*w = a + ++an;
		a[an].x = x;
		a[an].p = z;
		Splay(a + an);
		r++;
	}
	printf("%d", r);
}