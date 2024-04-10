//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll lg = 20;
const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, c[maxn][2], dp[maxn][2], p[maxn];

int main(){
	fast_io;
	
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = (p[i - 1] * 2) % mod;
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		c[a][0]++;
	}
	
	for(ll j = 1; j <= lg; j++){
		for(ll i = 0; i < (1ll << lg); i++){
			c[i][j % 2] = c[i][1 - j % 2];
			if(!((i >> (j - 1)) & 1)) c[i][j % 2] += c[i + (1ll << (j - 1))][1 - j % 2];
			c[i][j % 2] %= mod;
		}
	}
	
	for(ll i = 0; i < (1ll << lg); i++){
		dp[i][0] = p[c[i][lg % 2]] - 1;
		if(__builtin_popcount(i) % 2) dp[i][0] *= -1;
	}
	
	
	for(ll j = 1; j <= lg; j++){
		for(ll i = 0; i < (1ll << lg); i++){
			dp[i][j % 2] = dp[i][1 - j % 2];
			if(!((i >> (j - 1)) & 1)) dp[i][j % 2] += dp[i + (1ll << (j - 1))][1 - j % 2];
			dp[i][j % 2] %= mod;
		}
	}
	
	cout << (dp[0][lg % 2] + mod) % mod;
	
	return 0;
}