#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD;

ll dp[501][501][2];
vector<int> bugs;

int main() {
	int n, m, b;
	cin >> n >> m >> b >> MOD;
	bugs.resize(n);
	for(int i = 0; i < n; i++) cin >> bugs[i];
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= b; k++) {
				if(dp[j][k][0] == 0) continue;
				dp[j][k][1] += dp[j][k][0];
				if(k + bugs[i] <= b && j + 1 <= m) {
					dp[j+1][k + bugs[i]][0] += dp[j][k][0];
				}
			}
		}
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= b; k++) {
				dp[j][k][0] = dp[j][k][1]%MOD;
				dp[j][k][1] = 0;
			}
		}
	}
	ll ans = 0;
	for(int k = 0; k <= b; k++) {
		ans += dp[m][k][0];
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}