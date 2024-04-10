#include <bits/stdc++.h>
using namespace std;

int n, m, K;
bool g[15][15];
int dp[1 << 10][1 << 10];

int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 0; i < m; ++ i) {
		int u, v; scanf("%d%d", &u, &v);
		-- u, -- v;
		g[u][v] = g[v][u] = 1;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			dp[1 << i | 1 << j][1 << i | 1 << j] = g[i][j];
		}
	}
	for (int msk = 1; msk < (1 << n); ++ msk) {
		for (int S = msk; S; S = (S - 1) & msk) {
			for (int u = 0; u < n; ++ u) if (S >> u & 1) {
				for (int v = 0; v < n; ++ v) if (g[u][v] && ((msk ^ S) >> v & 1)) {
					dp[msk][S] += dp[msk ^ 1 << u][S ^ 1 << u];
					if (!(S >> v & 1)) dp[msk][S] += dp[msk ^ 1 << u][(S ^ 1 << u) | 1 << v];
				}
				break;
			}
			// printf("dp[%d][%d] = %d\n", msk, S, dp[msk][S]);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++ i) {
		if (__builtin_popcount(i) == K)
			ans += dp[(1 << n) - 1][i];
	}
	printf("%d\n", ans);
	return 0;
}