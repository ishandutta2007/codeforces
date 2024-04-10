#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;

std::mt19937 rng;

struct node {
	long long ky;
	int va, mx;
	node *ls, *rs;
	unsigned fix;

	node(long long k, int v): ky(k), va(v), mx(v), ls(), rs(), fix(rng()) {}
};

inline void pushup(node *x) {
	x->mx = x->va;
	if (x->ls) x->mx = std::max(x->mx, x->ls->mx);
	if (x->rs) x->mx = std::max(x->mx, x->rs->mx);
}

inline void split(node *x, long long v, node *&a, node *&b) {
	if (!x) return a = b = nullptr, void();
	if (x->ky < v) a = x, split(x->rs, v, a->rs, b), pushup(a);
	else b = x, split(x->ls, v, a, b->ls), pushup(b);
}

inline node *join(node *a, node *b) {
	if (!a || !b) return a ? a : b;
	if (a->fix < b->fix) return a->rs = join(a->rs, b), pushup(a), a;
	else return b->ls = join(a, b->ls), pushup(b), b;
}

inline int query(node *x, long long v) {
	if (!x) return 0;
	if (x->ky > v) return std::max(x->va, std::max(query(x->ls, v), x->rs ? x->rs->mx : 0));
	else return query(x->rs, v);
}

inline void insert(node *&x, node *y) {
	node *a, *b;
	split(x, y->ky, a, b);
	x = join(join(a, y), b);
}

int n;
int ax, ay, bx, by;
int x[mxn], y[mxn];
int dp[mxn];

long long V1[mxn], V2[mxn];

int main() {
	scanf("%d", &n);
	scanf("%d/%d %d/%d", &ax, &ay, &bx, &by);
	rep(i, n) scanf("%d %d", &x[i], &y[i]);
	x[n] = 0, y[n] = 0;
	++ n;
	rep(i, n) {
		V1[i] = 1LL * y[i] * by - 1LL * x[i] * bx;
		V2[i] = 1LL * y[i] * ay - 1LL * x[i] * ax;
	}
	std::vector <int> id(n);
	std::iota(id.begin(), id.end(), 0);
	std::sort(id.begin(), id.end(), [&] (int i, int j) {
		return V1[i] < V1[j];
	});
	/*
	for (int i : id) {
		dp[i] = 0;
		for (int j : id) {
			if (j == i) break;
			bool ok = true;
			ok &= 1LL * y[j] * by - 1LL * x[j] * bx < 1LL * y[i] * by - 1LL * x[i] * bx;
			ok &= 1LL * y[j] * ay - 1LL * x[j] * ax > 1LL * y[i] * ay - 1LL * x[i] * ax;
			if (ok) dp[i] = std::max(dp[i], dp[j]);
		}
		dp[i] ++;
	}
	*/
	node *rt = nullptr;
	int j = 0;
	rep(i, n) {
		while (j < i && V1[id[j]] < V1[id[i]]) {
			insert(rt, new node(V2[id[j]], dp[id[j]]));
			++ j;
		}
		dp[id[i]] = query(rt, V2[id[i]]) + 1;
	}
	printf("%d\n", dp[n - 1] - 1);
	return 0;
}