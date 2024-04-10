//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxm = 320;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second


ll n, m, x, dp[2][maxm][maxm];

int main(){
    fast_io;

	cin >> n >> m >> x;
	if(n > m){
		cout << 0;
		return 0;
	}
	dp[0][0][0] = 1;
	for(ll i = 1; i <= m; i++){
		for(ll j = 0; j <= n; j++){
			for(ll k = 0; k <= n; k++){
				ll& ans = dp[i & 1][j][k];
				ans = 0;
				if(j < k) continue;
				if(j && k) ans += dp[i - 1 & 1][j - 1][k - 1]; // (
				if(x != i) ans += dp[i - 1 & 1][j][k + 1]; // )
				if(x != i) ans += dp[i - 1 & 1][j][k]; // 0
				if(j) ans += dp[i - 1 & 1][j - 1][k]; // ()
				while(ans >= mod) ans -= mod;
			}
		}
	}
	ll ans = dp[m & 1][n][0];
	for(ll i = 1; i <= n; i++){
		ans = ans * i % mod;
	}
	cout << ans;

    return 0;
}