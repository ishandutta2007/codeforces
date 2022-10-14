#include <bits/stdc++.h>
using namespace std;
int n, t;
double p, dp[2005][2005];

int main() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> p >> t;
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < t; j++) {
			if(i != n) {
				dp[i + 1][j + 1] += dp[i][j] * p;
				dp[i][j + 1] += (1.0 - p) * dp[i][j];
			}	else {
				dp[i][j + 1] += dp[i][j];
			}
		}
	}
	double ans = 0.0;
	for(int i = 0; i <= n; i++) {
		ans += dp[i][t]*i;
	}
	printf("%lf", ans);
	return 0;
}