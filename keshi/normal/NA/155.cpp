#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, k, d, dp[MAXN], ans;

int main(){
	fast_io;
	
	cin >> n >> k >> d;
	d--;
	
	for(ll i = 1; i <= k; i++){
		dp[i] = 1;
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k && i - j > 0; j++){
			dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}
	
	ans = dp[n];
	
	fill(dp, dp + n + 1, 0);
	
	for(ll i = 1; i <= d; i++){
		dp[i] = 1;
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= d && i - j > 0; j++){
			dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}
	
	ans = (ans - dp[n] + MOD * 10) % MOD;
	cout << ans;
	
	return 0;
}