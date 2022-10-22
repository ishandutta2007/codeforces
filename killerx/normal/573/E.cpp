#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

std::mt19937 rng(19260817);

struct node {
	i64 tag;
	i64 v, s;
	int sz;
	unsigned fix;
	node *ls, *rs;

	node(i64 _v): tag(0), v(_v), s(_v), sz(1), fix(rng()), ls(), rs() {}
};

inline void push(node *x, i64 v) {
	x->tag += v;
	x->v += v;
	x->s += v * x->sz;
}

inline void pushdown(node *x) {
	if (x->tag) {
		if (x->ls) push(x->ls, x->tag);
		if (x->rs) push(x->rs, x->tag);
		x->tag = 0;
	}
}

inline void pushup(node *x) {
	x->s = x->v + (x->ls ? x->ls->s : 0) + (x->rs ? x->rs->s : 0);
	x->sz = 1 + (x->ls ? x->ls->sz : 0) + (x->rs ? x->rs->sz : 0);
}

inline node *merge(node *a, node *b) {
	if (!a || !b) return a ? a : b;
	pushdown(a), pushdown(b);
	if (a->fix < b->fix) return a->rs = merge(a->rs, b), pushup(a), a;
	else return b->ls = merge(a, b->ls), pushup(b), b;
}

inline void split(node *x, int k, node *&a, node *&b) {
	if (!x) return a = b = nullptr, void();
	pushdown(x);
	int lsz = x->ls ? x->ls->sz : 0;
	if (lsz + 1 <= k) a = x, split(x->rs, k - lsz - 1, a->rs, b), pushup(a);
	else b = x, split(x->ls, k, a, b->ls), pushup(b);
}

inline int search(node *x, int va, int base = 0, i64 base_res = 0) {
	if (!x) return 0x3f3f3f3f;
	pushdown(x);
	i64 ls = x->ls ? x->ls->s : 0;
	int lsz = x->ls ? x->ls->sz : 0;
	if ((base + ls) + 1LL * va * (base + lsz + 1) >= (base + ls + x->v))
		return std::min(base + lsz + 1, search(x->ls, va, base, base_res));
	else
		return search(x->rs, va, base + lsz + 1, base_res + ls + x->v);
}

inline i64 print(node *x, int base = 0, i64 base_res = 0) {
	if (!x) return base_res;
	pushdown(x);
	i64 ls = x->ls ? x->ls->s : 0;
	int lsz = x->ls ? x->ls->sz : 0;
	i64 ans = 0;
	ans = std::max(ans, print(x->ls, base, base_res));
	ans = std::max(ans, print(x->rs, base + lsz + 1, base_res + ls + x->v));
	return ans;
}

inline void debug(node *x) {
	if (!x) return ;
	pushdown(x);
	debug(x->ls);
	eprintf("%lld ", x->v);
	debug(x->rs);
}

const int mxn = 1e6 + 5;
int n, a[mxn];

int main() {
	// freopen("opt.in", "r", stdin);
	// freopen("opt.out", "w", stdout);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	node *rt = nullptr;
	rep(i, n) {
		int p = std::min((rt ? rt->sz : 0) + 1, search(rt, a[i], 0, 0));
		node *ls, *rs;
		split(rt, p - 1, ls, rs);
		if (rs) push(rs, a[i]);
		rt = merge(merge(ls, new node(1LL * a[i] * p)), rs);
		// debug(rt); eprintf("\n");
	}
	i64 ans = print(rt);
	printf("%lld\n", ans);
	return 0;
}