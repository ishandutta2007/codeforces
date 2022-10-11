//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, dp[maxn], ans, x, p[maxn];

vector<ll> g[maxn];

long long pw(ll a, ll b){
	if(b == 0) return 1;
	long long c = pw(a, b / 2);
	c = (c * c) % mod;
	if(b % 2) c = (a * c) % mod;
	return c;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 2; i * j < maxn; j++){
			g[i * j].pb(i);
		}
		p[i] = pw(i, n);
	}
	
	for(ll i = 1; i <= k; i++){
		dp[i] = p[i] - p[i - 1];
		for(ll j = 0; j < g[i].size(); j++){
			dp[i] = (dp[i] - dp[g[i][j]]) % mod;
		}
		dp[i] = (dp[i] + mod) % mod;
		x = (x + dp[i]) % mod;
		ans = (ans + (x ^ i)) % mod;
	}
	
	cout << ans;
	
	return 0;
}