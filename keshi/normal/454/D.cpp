//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll maxm = 7e4;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], x, b[maxn], dp[maxn][maxm], p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}, par[maxn][maxm];

vector<ll> g[maxm];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < 60; i++){
		for(ll j = 0; j < 16; j++){
			if(i % p[j] == 0) b[i] += (1ll << j);
		}
		for(ll j = 0; j < (1ll << 16); j++){
			if((b[i] & j) == b[i]) g[j].pb(i);
		}
	}
	
	fill(dp[0] + 1, dp[0] + maxm, inf);
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		for(ll j = 0; j < (1ll << 16); j++){
			dp[i][j] = inf;
			for(ll k = 0; k < g[j].size(); k++){
				if(dp[i][j] > dp[i - 1][j - b[g[j][k]]] + abs(a[i] - g[j][k])){
					dp[i][j] = dp[i - 1][j - b[g[j][k]]] + abs(a[i] - g[j][k]);
					par[i][j] = g[j][k];
				}
			}
		}
	}
	
	for(ll i = 0; i < (1ll << 16); i++){
		if(dp[n][i] < dp[n][x]) x = i;
	}
	
	for(ll i = n; i > 0; i--){
		a[i] = par[i][x];
		x = x - b[par[i][x]];
	}
	
	for(ll i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}