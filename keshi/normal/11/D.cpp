//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 20;
const ll maxm = 6e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[maxn][maxm], s[maxn], ans;

bool g[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		v--;
		u--;
		g[v][u] = 1;
		g[u][v] = 1;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(g[i][j]) dp[i][(1 << j)] = 1;
		}
	}
	
	for(ll i = 1; i < (1ll << n); i++){
		for(ll v = 0; v < n; v++){
			bool c = 0;
			for(ll j = 0; j < n; j++){
				if(c && ((i >> j) & 1) && g[v][j]){
					dp[v][i] += dp[j][i - (1ll << j)];
				}
				c |= (i >> j) & 1;
			}
		}
		if(__builtin_popcount(i) > 2) ans += dp[__builtin_ctz(i)][i] / 2;
	}
	
	cout << ans;
	
	return 0;
}