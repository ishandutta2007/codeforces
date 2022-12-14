#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int t, n;
int a[104], b[104];
int dp[104][20004];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i < 20004; ++i){
		dp[0][i] = (int)1e18;
	}
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		for(int i = 1; i <= n; ++i){
			cin >> b[i];
		}
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= sum + a[i] + b[i]; ++j){
				dp[i][j] = (int)1e18;
			}
			for(int j = 0; j <= sum; ++j){
				mi(dp[i][j + a[i]], dp[i - 1][j] + j * a[i] + (sum - j) * b[i]);
				mi(dp[i][j + b[i]], dp[i - 1][j] + j * b[i] + (sum - j) * a[i]);
			}
			sum += a[i] + b[i];
		}
		int ans = (int)1e18;
		for(int i = 0; i <= sum; ++i){
			mi(ans, dp[n][i]);
		}
		ans *= 2;
		for(int i = 1; i <= n; ++i){
			ans += (a[i] * a[i] + b[i] * b[i]) * (n - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}