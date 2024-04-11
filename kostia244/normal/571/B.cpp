#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<19, maxk = 5050, mod = 1e9 + 7;
ll n, k, dp[maxk][maxk];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	ll l = n/k;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < k; i++) {
		for(int j = 0; j <= i; j++) {
			int p = i*l + j;
			if(p+l <= n) {
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[p+l-1] - a[p]);
			}
			if(p+l < n) {
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + a[p+l] - a[p]);
			}
		}
	}
	cout << dp[k][n%k] << endl;
}