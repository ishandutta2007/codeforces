#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 55;
using ll = long long;
ll n, k, dp[maxn][maxn], a[maxn], x = 0;
bool can(int i, int j) {
	if(i == 0) return j==0;
	if(j == 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	ll cs = 0;
	for(int p = i; p; p--) {
		cs += a[p];
		if((cs&x) == x) dp[i][j] |= can(p-1, j-1);
	} 
	return dp[i][j];
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for(ll z = 1ll<<60; z>>=1;) {
		memset(dp, -1, sizeof dp);
		x = ans+z;
		ans += z*can(n, k);
	}
	cout << ans << '\n';
}