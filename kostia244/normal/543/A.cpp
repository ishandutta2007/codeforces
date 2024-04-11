#include <bits/stdc++.h>
using namespace std;
#define MOD(ARG) while(ARG >= mod) ARG -= mod

long long n, m, b, i, cost[502], dp[2][502][502];
long long mod;

int main() {
	cin >> n >> m >> b >> mod;
	memset(cost, 0, sizeof(cost));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	dp[0][0][0] = 1;
	for (int it = 1; it <= n; it++) {
		i = it & 1;
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= b; k++) {
				dp[i][j][k] = dp[i ^ 1][j][k];
				if (k >= cost[it] && j > 0)
					dp[i][j][k] += dp[i][j - 1][k - cost[it]];
				MOD(dp[i][j][k]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= b; i++) {
		ans += dp[n & 1][m][i];
		MOD(ans);
	}
	cout << ans;
	return 0;
}