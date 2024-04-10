#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int64_t inf = 1e18;

int phi[N];
int64_t p[N], dp[18][N];

inline void __calc__() {
	for (int i = 1; i < N; i++) phi[i] = i;
	for (int i = 2; i < N; i++)
		if (phi[i] == i) {
			for (int j = i; j < N; j += i)
				phi[j] -= phi[j] / i;
		}
	for (int i = 1; i < N; i++)
		p[i] = p[i - 1] + phi[i];
}

inline bool chkmin(int64_t &a, int64_t b) { return a > b ? a = b, 1 : 0; }

inline int64_t cost(int l, int r) {
	if (l > r) return inf;
	int64_t res = 0;
	for (int i = l, j; i <= r; i = j + 1) {
		j = r / (r / i);
		if (j > r) j = r;
		res += (j - i + 1) * p[r / i];
	}
	return res;
}

void solve(int k, int l, int r, int opt_l, int opt_r) {
	if (l > r) return ;
	int m = l + r >> 1, opt_m = opt_l;
	int64_t cst = cost(opt_m, m);
	for (int i = opt_l; i <= opt_r && i <= m; i++) {
		if (chkmin(dp[k][m], dp[k - 1][i - 1] + cst)) opt_m = i;
		cst -= p[m / i];
	}
	solve(k, l, m - 1, opt_l, opt_m);
	solve(k, m + 1, r, opt_m, opt_r);
}

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	__calc__();
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= N - 5; i++)
		dp[1][i] = 1ll * i * (i + 1) / 2;
	for (int i = 2; i < 18; i++)
		solve(i, 1, N - 5, 1, N - 5);
	int q; cin >> q;
	for (int n, k; q --; ) {
		cin >> n >> k;
		cout << (k > 18 || (1 << k) > n ? n : dp[k][n]) << '\n';
	}
}