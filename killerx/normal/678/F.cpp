#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

struct frac {
	int a, b;

	frac(): a(), b(1) {}
	frac(int _x): a(_x), b(1) {}
	frac(int _a, int _b): a(_a), b(_b) {}

	inline frac operator - () const { return {-a, b}; }
	inline frac operator + () const { return {+a, b}; }

	inline bool operator < (const frac &oth) const { return 1LL * a * oth.b < 1LL * oth.a * b; }
};

const frac inf = {2000000007, 1};

struct line {
	int k, b;

	line(): k(), b() {}
	line(int _k, int _b): k(_k), b(_b) {}

	inline i64 operator () (int x) const { return 1LL * k * x + b; }

	inline frac intersect(const line &oth) const {
		if (k == oth.k) return b < oth.b ? -inf : inf;
		return {b - oth.b, oth.k - k};
	}
};

std::mt19937 rng;

struct node {
	line v;
	frac pl, pr;
	int sz;
	unsigned fix;
	node *ls, *rs;

	node(line _v, frac _pl, frac _pr): v(_v), pl(_pl), pr(_pr), sz(1), fix(rng()), ls(), rs() {}

	~node() {
		if (ls) delete ls;
		if (rs) delete rs;
	}
};

inline void pushup(node *x) {
	x->sz = 1 + (x->ls ? x->ls->sz : 0) + (x->rs ? x->rs->sz : 0);
}

inline node *get(node *x, int k) {
	if (!x) return nullptr;
	int lsz = x->ls ? x->ls->sz : 0;
	if (k == lsz + 1) return x;
	else if (k <= lsz) return get(x->ls, k);
	else return get(x->rs, k - lsz - 1);
}

inline node *merge(node *a, node *b) {
	if (!a || !b) return a ? a : b;
	if (a->fix < b->fix) return a->rs = merge(a->rs, b), pushup(a), a;
	else return b->ls = merge(a, b->ls), pushup(b), b;
}

inline void splitk(node *x, int k, node *&a, node *&b) {
	if (!x) return a = b = nullptr, void();
	int lsz = x->ls ? x->ls->sz : 0;
	if (lsz + 1 <= k) a = x, splitk(x->rs, k - lsz - 1, a->rs, b), pushup(a);
	else b = x, splitk(x->ls, k, a, b->ls), pushup(b);
}

inline void splitc(node *x, int c, node *&a, node *&b) {
	if (!x) return a = b = nullptr, void();
	if (x->v.k < c) a = x, splitc(x->rs, c, a->rs, b), pushup(a);
	else b = x, splitc(x->ls, c, a, b->ls), pushup(b);
}

node *rt;

inline int search_r(node *x, line l) {
	if (!x) return 0;
	int lsz = x->ls ? x->ls->sz : 0;
	if (!(x->pr < x->v.intersect(l))) return std::min(search_r(x->ls, l), lsz);
	else return lsz + 1 + search_r(x->rs, l);
}

inline int search_l(node *x, line l) {
	if (!x) return 0;
	int lsz = x->ls ? x->ls->sz : 0;
	if (!(l.intersect(x->v) < x->pl)) return std::max(lsz + 1 + search_l(x->rs, l), lsz + 1);
	else return search_l(x->ls, l);
}

inline void __debug(node *x) {
	if (!x) return ;
	__debug(x->ls);
	eprintf("{[%d/%d, %d/%d]: (%dx+%d)} ", x->pl.a, x->pl.b, x->pr.a, x->pr.b, x->v.k, x->v.b);
	__debug(x->rs);
}

inline void debug(node *x) { __debug(x); eprintf("\n"); fflush(stderr); }

struct evt {
	int l, len;
	node *ori;
};

std::vector <evt> stk;

inline void add(line x) {
	// eprintf("+ %dx+%d\n", x.k, x.b);
	if (rt == nullptr) {
		rt = new node(x, -inf, +inf);
		stk.push_back({0, 1, nullptr});
	} else {
		node *A, *B;
		splitc(rt, x.k, A, B);
		int pA = search_r(A, x);
		int pB = search_l(B, x);
		if ((A && pA == A->sz) || (B && pB == 0)) {
			rt = merge(A, B);
			stk.push_back({0, 0, nullptr});
		} else {
			node *A0, *A1, *B0, *B1;
			splitk(A, pA, A0, A1);
			splitk(B, pB, B0, B1);
			node *M = nullptr;
			node *N = new node(x, 0, 0);
			node *A10 = nullptr;
			if (A1) {
				A10 = get(A1, 1);
				N->pl = A10->v.intersect(x);
				A10 = new node(A10->v, A10->pl, N->pl);
			} else {
				N->pl = -inf;
			}
			node *B01 = nullptr;
			if (B0) {
				B01 = get(B0, B0->sz);
				N->pr = x.intersect(B01->v);
				B01 = new node(B01->v, N->pr, B01->pr);
			} else {
				N->pr = +inf;
			}
			M = merge(M, A10);
			M = merge(M, N);
			M = merge(M, B01);
			stk.push_back({A0 ? A0->sz : 0, M->sz, merge(A1, B0)});
			rt = merge(merge(A0, M), B1);
		}
	}
	// debug(rt);
}

inline void undo() {
	// eprintf("-\n");
	node *A, *B, *C;
	splitk(rt, stk.back().l, A, B);
	splitk(B, stk.back().len, B, C);
	delete B;
	rt = merge(merge(A, stk.back().ori), C);
	stk.pop_back();
	// debug(rt);
}

inline i64 query(int v) {
	node *x = rt;
	while (x) {
		if (frac(v) < x->pl) x = x->ls;
		else if (x->pr < frac(v)) x = x->rs;
		else return 1LL * x->v.k * v + x->v.b;
	}
	assert(false);
}

const int mxn = 1 << 19;

int q;
int tp[mxn];
line l[mxn];
int x[mxn];
bool vis[mxn];
std::vector <line> vec[mxn << 1];

inline void update(int l, int r, line v) {
	for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
		if (l & 1) vec[l ++].push_back(v);
		if (r & 1) vec[-- r].push_back(v);
	}
}

inline void traverse(int i, int a, int b) {
	for (line l : vec[i]) add(l);
	if (a + 1 == b) {
		if (tp[a] == 3) {
			if (rt) printf("%lld\n", query(x[a]));
			else puts("EMPTY SET");
		}
	} else {
		int m = (a + b) >> 1;
		traverse(i << 1, a, m);
		traverse(i << 1 | 1, m, b);
	}
	for (line l : vec[i]) undo();
}

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &q);
	rep(i, q) {
		scanf("%d", &tp[i]);
		if (tp[i] == 1) scanf("%d %d", &l[i].k, &l[i].b);
		else if (tp[i] == 2) {
			int j;
			scanf("%d", &j);
			-- j;
			update(j, i, l[j]);
			vis[j] = 1;
		} else {
			scanf("%d", &x[i]);
		}
	}
	rep(i, q) if (tp[i] == 1 && !vis[i]) {
		update(i, q, l[i]);
	}
	traverse(1, 0, mxn);
	return 0;
}