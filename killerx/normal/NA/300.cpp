#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5, mxlg = 17, mod = 1e9 + 9;
int _n, n, x[mxn], y[mxn], A, B, C, D;
int p[mxn];

int mx[mxlg][mxn], lg[mxn];

inline void init() {
	rep(i, n) mx[0][i] = i;
	rep(j, mxlg - 1) rep(i, n - (1 << (j + 1)) + 1)
		mx[j + 1][i] = p[mx[j][i]] > p[mx[j][i + (1 << j)]] ? mx[j][i] : mx[j][i + (1 << j)];
	rep(i, n + 1) lg[i] = i >= 2 ? lg[i >> 1] + 1 : 0;
}

inline int querymax(int l, int r) {
	int k = lg[r - l];
	return p[mx[k][l]] > p[mx[k][r - (1 << k)]] ? mx[k][l] : mx[k][r - (1 << k)];
}

int ls[mxn], rs[mxn], L[mxn], R[mxn];
int rt;

inline int build(int l, int r) {
	if (l == r) return -1;
	int m = querymax(l, r);
	L[m] = l, R[m] = r;
	ls[m] = build(l, m), rs[m] = build(m + 1, r);
	return m;
}

struct dpval {
	int f0, f1;
};

dpval dp[mxn];

inline void dfs0(int x) {
	if (!~x) return ;
	dfs0(ls[x]), dfs0(rs[x]);
	if (~ls[x] && ~rs[x]) {
		int F0 = std::max(dp[ls[x]].f0, dp[ls[x]].f1) + std::max(dp[rs[x]].f0, dp[rs[x]].f1);
		int F10 = dp[ls[x]].f0 + std::max(dp[rs[x]].f0, dp[rs[x]].f1) + 1;
		int F11 = dp[rs[x]].f0 + std::max(dp[ls[x]].f0, dp[ls[x]].f1) + 1;
		dp[x] = {F0, std::max(F10, F11)};
	} else if (~ls[x]) {
		dp[x] = {std::max(dp[ls[x]].f0, dp[ls[x]].f1), dp[ls[x]].f0 + 1};
	} else if (~rs[x]) {
		dp[x] = {std::max(dp[rs[x]].f0, dp[rs[x]].f1), dp[rs[x]].f0 + 1};
	} else dp[x] = {0, -0x3f3f3f3f};
}

inline dpval query(int x, int l, int r) {
	if (!~x) return {-0x3f3f3f3f, -0x3f3f3f3f};
	if (l == L[x] && r == R[x] - 1) return dp[x];
	if (r < x) return query(ls[x], l, r);
	if (l > x) return query(rs[x], l, r);
	if (l < x && r > x) {
		dpval vl = query(ls[x], l, x - 1), vr = query(rs[x], x + 1, r);
		int F0 = std::max(vl.f0, vl.f1) + std::max(vr.f0, vr.f1);
		int F10 = vl.f0 + std::max(vr.f0, vr.f1) + 1;
		int F11 = vr.f0 + std::max(vl.f0, vl.f1) + 1;
		return {F0, std::max(F10, F11)};
	} else if (l < x && r == x) {
		dpval vl = query(ls[x], l, x - 1);
		return {std::max(vl.f0, vl.f1), vl.f0 + 1};
	} else if (l == x && r > x) {
		dpval vr = query(rs[x], x + 1, r);
		return {std::max(vr.f0, vr.f1), vr.f0 + 1};
	} else return {0, -0x3f3f3f3f};
}

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	scanf("%d %d", &n, &_n);
	rep(i, _n) scanf("%d %d", &x[i], &y[i]);
	scanf("%d %d %d %d", &A, &B, &C, &D);
	for (int i = _n; i < n; ++ i) {
		x[i] = (1LL * A * x[i - 1] + B) % mod;
		y[i] = (1LL * C * y[i - 1] + D) % mod;
	}
	std::vector <int> vx, vy;
	rep(i, n) vx.push_back(x[i]), vy.push_back(y[i]);
	std::sort(vx.begin(), vx.end()), std::sort(vy.begin(), vy.end());
	rep(i, n) p[std::lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin()] =
		std::lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
	init();
	rt = build(0, n);
	dfs0(rt);
	int q; scanf("%d", &q);
	while (q --) {
		int l, r;
		scanf("%d %d", &l, &r);
		l = std::lower_bound(vx.begin(), vx.end(), l) - vx.begin();
		r = std::upper_bound(vx.begin(), vx.end(), r) - vx.begin() - 1;
		if (l > r) printf("0\n");
		else {
			dpval v = query(rt, l, r);
			printf("%d\n", std::max(v.f0, v.f1));
		}
	}
	return 0;
}