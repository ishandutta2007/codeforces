#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

std::mt19937 rng;

struct Node {
	int l, r;
	int v, tag;
	unsigned fix;
	Node *ls, *rs;

	Node(int _l, int _r, int _v): l(_l), r(_r), v(_v), tag(0), fix(rng()), ls(), rs() {}
	~Node() { if (ls) delete ls; if (rs) delete rs; }
};

inline void push(Node *x, int t) {
	x->v += t;
	x->tag += t;
}

inline void pushdown(Node *x) {
	if (x->tag) {
		if (x->ls) push(x->ls, x->tag);
		if (x->rs) push(x->rs, x->tag);
		x->tag = 0;
	}
}

inline void pushup(Node *x) {
}

Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ? a : b;
	pushdown(a), pushdown(b);
	if (a->fix < b->fix) return a->rs = merge(a->rs, b), pushup(a), a;
	else return b->ls = merge(a, b->ls), pushup(b), b;
}

void split(Node *x, int v, Node *&a, Node *&b) {
	if (!x) return a = b = nullptr, void();
	pushdown(x);
	if (v <= x->v) b = x, split(x->ls, v, a, b->ls), pushup(b);
	else if (x->v + (x->r - x->l) <= v) a = x, split(x->rs, v, a->rs, b), pushup(a);
	else {
		Node *ls = x->ls, *rs = x->rs;
		int p = v - x->v + x->l;
		Node *ra = new Node(x->l, p, x->v);
		Node *lb = new Node(p, x->r, x->v + (p - x->l));
		x->ls = x->rs = nullptr;
		delete x;
		a = merge(ls, ra), b = merge(lb, rs);
	}
}

int query(Node *x, int p) {
	pushdown(x);
	if (x->l <= p && p < x->r) return x->v + (p - x->l);
	else if (p < x->l) return query(x->ls, p);
	else return query(x->rs, p);
}

void print(Node *x) {
	if (!x) return ;
	pushdown(x);
	print(x->ls);
	eprintf("{[%d, %d), %d}", x->l, x->r, x->v);
	print(x->rs);
}

inline void debug(Node *x) {
	print(x); eprintf("\n");
}

Node *root;

int main() {
	int last = 0;
	root = new Node(0, 1e9 + 7, 0);
	int q; scanf("%d", &q);
	while (q --) {
		int T; scanf("%d", &T);
		Node *A, *B, *C;
		split(root, T + 1, B, C);
		split(B, T, A, B);
		if (A) push(A, +1);
		if (C) push(C, -1);
		// debug(A), debug(B), debug(C);
		root = merge(merge(A, B), C);
		int k; scanf("%d", &k);
		while (k --) {
			int x; scanf("%d", &x);
			x = (x + last) % ((int) (1e9 + 1));
			printf("%d\n", last = query(root, x));
		}
	}
	return 0;
}