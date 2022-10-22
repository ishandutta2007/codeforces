#include <bits/stdc++.h>
using namespace std;

int n, h, m;
int dp[55][55][55];
int cost[55][55][55][55];
int l[55], r[55], x[55], c[55];

int main() {
	scanf("%d %d %d", &n, &h, &m);
	for (int i = 0; i < m; ++ i) {
		scanf("%d %d %d %d", &l[i], &r[i], &x[i], &c[i]);
		-- l[i], -- r[i];
		for (int a = l[i]; ~a; -- a) for (int b = r[i]; b < n; ++ b) {
			for (int j = l[i]; j <= r[i]; ++ j) {
				for (int k = x[i] + 1; k <= h; ++ k) {
					cost[a][b][j][k] += c[i];
				}
			}
		}
	}
	// for (int i = 0; i < n; ++ i) {
	// 	for (int j = i; j < n; ++ j) {
	// 		for (int k = i; k <= j; ++ k) {
	// 			for (int l = 0; l <= h; ++ l) {
	// 				printf("cost %d %d %d %d = %d\n", i, j, k, l, cost[i][j][k][l]);
	// 			}
	// 		}
	// 	}
	// }
	for (int l = n - 1; ~l; -- l) {
		for (int r = l; r < n; ++ r) {
			for (int a = 0; a <= h; ++ a) {
				for (int i = l; i <= r; ++ i) {
					for (int b = 0; b <= a; ++ b) {
						dp[l][r][a] = max(dp[l][r][a], (i == l ? 0 : dp[l][i - 1][b]) + (i == r ? 0 : dp[i + 1][r][b]) + b * b - cost[l][r][i][b]);
					}
				}
				// printf("dp %d %d %d = %d\n", l, r, a, dp[l][r][a]);
			}
		}
	}
	printf("%d\n", dp[0][n - 1][h]);
	return 0;
}