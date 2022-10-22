#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2005, mod = 998244353;

int n, k;
int b[mxn];
int comb[mxn][mxn];
int dp[2][mxn][mxn];

int main() {
	rep(i, mxn) rep(j, i + 1)
		comb[i][j] = j ? (comb[i - 1][j - 1] + comb[i - 1][j]) % mod : 1;
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &b[i]);
	for (int mex = 0; mex <= n; ++ mex)
		for (int s = mex; s <= n; ++ s)
			dp[n & 1][mex][s] = comb[n + 1 - mex - 1][s - mex];
	for (int i = n - 1; ~i; -- i) {
		for (int mex = 0; mex <= i; ++ mex) {
			if (i && std::abs(mex - b[i - 1]) > k) continue;
			for (int s = mex; s <= i; ++ s) dp[i & 1][mex][s] = 0;
		}
		static int sum[mxn];
		for (int s = 0; s <= i + 1; ++ s) sum[s] = 0;
		for (int mex = i + 1; ~mex; -- mex) {
			if (!i || std::abs(mex - b[i - 1]) <= k) {
				for (int s = mex; s <= i; ++ s) if (sum[s + 1]) {
					dp[i & 1][mex][s] = (dp[i & 1][mex][s] + sum[s + 1]) % mod;
				}
			}
			if (std::abs(mex - b[i]) > k) continue;
			for (int s = mex; s <= i + 1; ++ s) {
				if (s && dp[(i + 1) & 1][mex][s]) {
					dp[i & 1][mex][s] = (dp[i & 1][mex][s] + 1LL * s * dp[(i + 1) & 1][mex][s]) % mod;
					dp[i & 1][mex][s - 1] = (dp[i & 1][mex][s - 1] + 1LL * (s - mex) * dp[(i + 1) & 1][mex][s]) % mod;
					sum[s] = (sum[s] + dp[(i + 1) & 1][mex][s]) % mod;
					// for (int x = 0; x < mex; ++ x) dp[i & 1][x][s - 1] = (dp[i & 1][x][s - 1] + dp[(i + 1) & 1][mex][s]) % mod;
				}
			}
		}
	}
	printf("%d\n", dp[0 & 1][0][0]);
	return 0;
}