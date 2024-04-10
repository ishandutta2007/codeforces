#include <iostream>
#include <algorithm>
using namespace std;

int a[1000009];
long long c[1000009][2], dp[1000009][3], mdp[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, r1, r2, r3, d; cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i][0] = 1LL * a[i] * r1 + 1LL * r3;
		c[i][1] = min(1LL * (a[i] + 2) * r1, 1LL * r2 + 1LL * r1);
	}
	mdp[0] = dp[0][0] = -d; dp[0][1] = dp[0][2] = 1e18;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(mdp[i - 1] + c[i][0] + 1LL * d, dp[0][1]);
		dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][2]) + c[i][1] + 3LL * d, dp[0][1]);
		dp[i][2] = min(dp[i - 1][1] + 1LL * d + c[i][1], dp[0][1]);
		mdp[i] = min(min(dp[i][0], dp[i][1]), dp[i][2]);
	}
	long long ans = mdp[n], s = min(c[n][0], c[n][1] + 2LL * d) + 1LL * d;
	for (int i = n - 1; i >= 1; i--) {
		s += min(c[i][0], c[i][1]) + 2LL * d;
		ans = min(ans, s + mdp[i - 1]);
	}
	cout << ans << '\n';
	return 0;
}