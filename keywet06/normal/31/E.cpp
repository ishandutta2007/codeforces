#include <bits/stdc++.h>

const int N = 32 + 1;
const int L = 64 + 1;

char num[L], ans[L];

bool path[N][N];

int n;

long long dp[N][N], power[N];

int main() {
	power[0] = 1;
	for (int i = 1; i < N; ++i) power[i] = power[i - 1] * 10;
	memset(dp, 0xFF, sizeof(dp));
	scanf("%d%s", &n, num);
	dp[n][n] = 0;
	for (int o = 0; o < n << 1; ++o) {
		for (int i = 0; i <= n; ++i) {
			int j = (n << 1) - o - i;
			if (j < 0 || j > n) continue;
			if (i && dp[i - 1][j] < dp[i][j] + (num[o] - '0') * power[i - 1]) {
				dp[i - 1][j] = dp[i][j] + (num[o] - '0') * power[i - 1];
				path[i - 1][j] = true;
			}
			if (j && dp[i][j - 1] < dp[i][j] + (num[o] - '0') * power[j - 1]) {
				dp[i][j - 1] = dp[i][j] + (num[o] - '0') * power[j - 1];
				path[i][j - 1] = false;
			}
		}
	}
	ans[n << 1] = '\0';
	int x = 0, y = 0;
	while (x != n || y != n) {
		if (path[x][y]) {
			ans[(n << 1) - x++ - y - 1] = 'H';
		} else {
			ans[(n << 1) - x - y++ - 1] = 'M';
		}
	}
	puts(ans);
	return 0;
}