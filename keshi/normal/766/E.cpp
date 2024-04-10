//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll maxm = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], par[maxn], b[maxn][maxm][2], c[maxn][maxm][2], ans, d[maxn][maxm][2];

vector<ll> g[maxn];

void dfs(ll v){
	for(ll j = 0; j < maxm; j++){
		if((a[v] >> j) & 1){
			d[v][j][1] = 1;
		}
		else{
			d[v][j][0] = 1;
		}
		b[v][j][0] = d[v][j][0];
		b[v][j][1] = d[v][j][1];
	}
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(u == par[v]) continue;
		par[u] = v;
		dfs(u);
		for(ll j = 0; j < maxm; j++){
			if((a[v] >> j) & 1){
				c[u][j][0] = b[u][j][1];
				c[u][j][1] = b[u][j][0];
			}
			else{
				c[u][j][0] = b[u][j][0];
				c[u][j][1] = b[u][j][1];
			}
			b[v][j][0] += c[u][j][0];
			b[v][j][1] += c[u][j][1];
		}
	}
	for(ll j = 0; j < maxm; j++){
		ans += b[v][j][1] * (1 << (j + 1));
	}
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(u == par[v]) continue;
		for(ll j = 0; j < maxm; j++){
			ans += ((b[v][j][1] - c[u][j][1] - d[v][j][1]) * b[u][j][0] + (b[v][j][0] - c[u][j][0] - d[v][j][0]) * b[u][j][1]) * (1 << j);
		}
	}
	
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1);
	
	cout << ans / 2;
	
	return 0;
}