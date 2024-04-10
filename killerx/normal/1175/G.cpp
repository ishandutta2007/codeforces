#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 2e4 + 5, mxk = 105;
const i64 inf = 1LL << 60;

struct line {
	int k;
	i64 b;

	line(int _k, i64 _b): k(_k), b(_b) {}
};

inline bool cross(line a, line b, line c) {
	return (b.b - a.b) * (c.k - b.k) < (c.b - b.b) * (b.k - a.k);
}

int n, a[mxn];

inline void solve(int l, int r, i64 f[], i64 nf[]) {
	if (l + 1 == r) return ;
	int m = (l + r) >> 1;
	static int suf[mxn];
	suf[m] = 0;
	for (int i = m - 1; i >= l; -- i)
		suf[i] = std::max(suf[i + 1], a[i]);
	static int pre[mxn];
	pre[m] = 0;
	for (int i = m; i < r; ++ i)
		pre[i + 1] = std::max(pre[i], a[i]);
	std::vector <line> conv;
	auto add = [&] (line x) {
		if (!conv.empty() && conv[conv.size() - 1].k == x.k && conv[conv.size() - 1].b <= x.b) return ;
		while ((int) conv.size() > 1 && !cross(conv[conv.size() - 2], conv[conv.size() - 1], x)) conv.pop_back();
		conv.push_back(x);
	};
	auto query = [&] (int x) {
		int lb = 0, rb = conv.size() - 1;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (conv[md + 1].b - conv[md].b > -1LL * x * (conv[md + 1].k - conv[md].k))
				rb = md;
			else
				lb = md + 1;
		}
		return 1LL * conv[lb].k * x + conv[lb].b;
	};
	conv.clear();
	for (int i = m, j = m; i < r; ++ i) {
		while (j > l && suf[j - 1] < pre[i]) {
			-- j;
			if (f[j] < inf) add(line(-j, f[j]));
		}
		if (!conv.empty()) nf[i] = std::min(nf[i], 1LL * i * pre[i] + query(pre[i]));
	}
	conv.clear();
	for (int i = r - 1, j = l; i >= m; -- i) {
		while (j < m && suf[j] >= pre[i]) {
			if (f[j] < inf) add(line(-suf[j], -1LL * j * suf[j] + f[j]));
			++ j;
		}
		if (!conv.empty()) nf[i] = std::min(nf[i], query(-i));
	}
	solve(l, m, f, nf);
	solve(m, r, f, nf);
}

int main() {
	int k;
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	static i64 f[mxn];
	rep(i, n + 1) f[i] = inf;
	f[0] = 0;
	rep(_, k) {
		// eprintf("! %d\n", _);
		static i64 nf[mxn];
		rep(i, n + 1) nf[i] = inf;
		solve(0, n + 1, f, nf);
		rep(i, n + 1) f[i] = nf[i];
		// rep(i, n + 1) eprintf("%lld ", f[i]);
		// eprintf("\n");
	}
	printf("%lld\n", f[n]);
	return 0;
}