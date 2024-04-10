#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
int dp[55][55][55][55], g[55][55];
char s[55];

int solve(int l, int r, int u, int d) {
	int &answer = dp[l][r][u][d];
	if (answer != -1) {
		return answer;
	}
	int cnt = g[r][d] - g[l - 1][d] - g[r][u - 1] + g[l - 1][u - 1];
	if (cnt == 0) {
		return answer = 0;
	}
	answer = max(r - l + 1, d - u + 1);
	for (int c = l; c < r; c++) {
		answer = min(answer, solve(l, c, u, d) + solve(c + 1, r, u, d));
	}
	for (int c = u; c < d; c++) {
		answer = min(answer, solve(l, r, u, c) + solve(l, r, c + 1, d));
	}
	return answer;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++)
			if (s[j] == '#')
				g[i][j] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] += g[i][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] += g[i - 1][j];
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(1, n, 1, n));
}