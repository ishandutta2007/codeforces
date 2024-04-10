//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 510;
const ll maxm = maxn * maxn;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, dp[maxn][maxn], p[maxm];

int main(){
    fast_io;
    
    p[0] = 1, p[1] = (mod + 1) / 2;
    for(ll i = 2; i < maxm; i++){
    	p[i] = p[i - 1] * p[1] % mod;
	}
	
	cin >> n >> k;
	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		dp[i][0] = p[i * (i + 1) / 2];
		for(ll j = 1; j <= i; j++){
			for(ll l = 1; l <= i; l++){
				dp[i][j] += dp[i - l][j - 1] * (p[l * (l - 1) / 2] - p[l * (l + 1) / 2]);
				dp[i][j] %= mod;
			}
			ll x = (dp[i][j] + mod) % mod;
			for(ll o = 0; o < i * (i + 1) / 2; o++){
				x = (x * 2) % mod;
			}
		}
	}
	ll ans = (dp[n][k] + mod) % mod;
	for(ll i = 0; i < n * (n + 1) / 2; i++){
		ans = (ans * 2) % mod;
	}
	cout << ans;
 
    return 0;
}