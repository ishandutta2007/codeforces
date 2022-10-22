#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
const int mod = 1e9 + 7;

inline void uadd(int &x, int y) {
	x += y - mod;
	x += x >> 31 & mod;
}

struct fenwick_tree {
	int n, s[mxn];

	inline void init(int _n) {
		n = _n;
		rep(i, n + 1) s[i] = 0;
	}

	inline void update(int x, int v) {
		for (++ x; x <= n; x += x & -x) uadd(s[x], v);
	}

	inline int query(int x) {
		int ans = 0;
		for (++ x; x; x -= x & -x) uadd(ans, s[x]);
		return ans;
	}
} bit;

int n, a[mxn];
int vec[mxn], m;

void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	m = 0;
	rep(i, n) vec[m ++] = a[i];
	std::sort(vec, vec + m);
	m = std::unique(vec, vec + m) - vec;
	rep(i, n) a[i] = std::lower_bound(vec, vec + m, a[i]) - vec;
	static int f[mxn];
	bit.init(m);
	for (int i = 0; i < n; ++ i) {
		f[i] = (bit.query(a[i] - 1) + 1) % mod;
		bit.update(a[i], f[i]);
	}
	static int g[mxn];
	bit.init(m);
	for (int i = n - 1; ~i; -- i) {
		g[i] = (bit.query(m - 1) + mod - bit.query(a[i]) + 1) % mod;
		bit.update(a[i], g[i]);
	}
	static int stk[mxn];
	int top = 0;
	rep(i, n) {
		while (top && a[stk[top - 1]] < a[i]) -- top;
		stk[top ++] = i;
	}
	std::reverse(stk, stk + top);
	static bool in_stk[mxn];
	rep(i, n) in_stk[i] = false;
	rep(i, top) in_stk[stk[i]] = true;
	auto gg = [&] (int v) -> int {
		int lb = 0, rb = top;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (a[stk[md]] <= v) lb = md + 1;
			else rb = md;
		}
		return lb;
	};
	static int h[mxn];
	bit.init(m);
	for (int i = n - 1; ~i; -- i) if (in_stk[i]) h[i] = 1;
	else {
		int p = gg(a[i]);
		int ub = p < top ? a[stk[p]] : m;
		h[i] = (bit.query(ub - 1) + mod - bit.query(a[i])) % mod;
		if (p < top) uadd(h[i], h[stk[p]]);
		bit.update(a[i], h[i]);
	}
	// rep(i, n) eprintf("%d: %d %d %d\n", i + 1, f[i], g[i], h[i]);
	int ans = 0;
	rep(i, n) uadd(ans, 1LL * f[i] * (g[i] + mod - h[i]) % mod);
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}