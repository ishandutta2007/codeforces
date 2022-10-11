// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, k, dp[MAXN][MAXN], ans;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		dp[i][1] = 1;
	}
	
	for(ll o = 1; o < k; o++){
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; i * j <= n; j++){
				dp[i * j][o + 1] += dp[i][o];
				dp[i * j][o + 1] %= MOD;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		ans += dp[i][k];
		ans %= MOD;
	}
	
	cout << ans;
	
	return 0;
}