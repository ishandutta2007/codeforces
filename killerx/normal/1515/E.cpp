#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, mod;
int dp[405][405];
int comb[405][405];
int f[405];

int main() {
	scanf("%d %d", &n, &mod);
	rep(i, n + 1) rep(j, i + 1) comb[i][j] = j ? (comb[i - 1][j - 1] + comb[i - 1][j]) % mod : 1;
	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= i; ++ j) { int l = j - 1, r = i - j; (f[i] += comb[l + r][l]) %= mod; }
	dp[0][0] = 1;
	rep(i, n) rep(j, i + 1) {
		for (int k = 1; i + k <= n; ++ k) {
			(dp[i + k + 1][j + k] += 1LL * dp[i][j] * f[k] % mod * comb[j + k][k] % mod) %= mod;
		}
	}
	int ans = 0;
	rep(i, n + 1) (ans += dp[n + 1][i]) %= mod;
	printf("%d\n", ans);
	return 0;
}