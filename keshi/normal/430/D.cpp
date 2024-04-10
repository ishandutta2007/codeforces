#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, a[MAXN][MAXN], dp[4][MAXN][MAXN];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
		}
	}
	
	for(ll i = n; i > 0; i--){
		for(ll j = m; j > 0; j--){
			dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j + 1]) + a[i][j];
		}
	}
	
	for(ll i = n; i > 0; i--){
		for(ll j = 1; j <= m; j++){
			dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j - 1]) + a[i][j];
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = m; j > 0; j--){
			dp[3][i][j] = max(dp[3][i - 1][j], dp[3][i][j + 1]) + a[i][j];
		}
	}
	
	for(ll i = 2; i < n; i++){
		for(ll j = 2; j < m; j++){
			ans = max(ans, max(dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1], dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j]));
		}
	}
	
	cout << ans;
	
	return 0;
}