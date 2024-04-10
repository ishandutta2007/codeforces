#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const ll MOD = 1000000007;
ll dp[10][300020];

ll calc(int n, int m) {
	if(m <= 0) return 1;
	if(dp[n][m] > 0) return dp[n][m];
	if(n == 9) return dp[n][m] = (calc(9, m-9) + calc(9, m-10))%MOD;
	return dp[n][m] = calc(n+1, m-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		ll ans = 0;
		while(n) {
			ans += calc(n%10, m);
			ans %= MOD;
			n /= 10;
		}
		cout << ans << '\n';
	}
}