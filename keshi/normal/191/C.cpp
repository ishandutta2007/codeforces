//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 18;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[maxn], par[level][maxn], d[maxn], ans[maxn];

bool vis[maxn];

vector<pll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			par[0][u] = v;
			d[u] = d[v] + 1;
			dfs(u);
		}
	}
	return;
}

ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	ll x = d[v] - d[u];
	for(ll i = 0; i < level; i++){
		if((x >> i) & 1){
			v = par[i][v];
		}
	}
	for(ll i = level - 1; i > -1; i--){
		if(d[v] >= (1 << i) && par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	if(v != u) v = par[0][v];
	return v;
}

void solve(ll v, ll p){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			solve(u, g[v][i].S);
			dp[v] += dp[u];
		}
	}
	ans[p] = dp[v];
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	
	dfs(1);
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] < (1 << j)) continue;
			par[j][i] = par[j - 1][par[j - 1][i]];
		}
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		dp[v]++;
		dp[u]++;
		dp[lca(v, u)] -= 2;
	}
	
	fill(vis, vis + maxn, 0);
	
	solve(1, 0);
	
	for(ll i = 1; i < n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}