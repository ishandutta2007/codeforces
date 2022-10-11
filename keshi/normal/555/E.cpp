//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, d[maxn], par[maxn][level], a[maxn], b[maxn], c[maxn], e[maxn], t;

bool vis[maxn], f;

vector<pll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	e[v] = t;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			d[u] = d[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
	return;
}

ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	ll h = d[v] - d[u];
	for(ll i = 0; i < level; i++){
		if((h >> i) & 1) v = par[v][i];
	}
	for(ll i = level - 1; i--;){
		if(d[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	if(v != u) v = par[v][0];
	return v;
}

void dfs2(ll v, ll p){
	ll u;
	vis[v] = 1;
	c[v] = inf;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			dfs2(u, g[v][i].S);
			if(c[u] >= d[u] && a[u] && b[u]) f = 1;
			a[v] += a[u];
			b[v] += b[u];
			c[v] = min(c[v], c[u]);
		}
		else if(p != g[v][i].S){
			c[v] = min(c[v], d[u]);
		}
	}
	return;
}

int main(){
	ll v, u, p;
	fast_io;
	
	cin >> n >> m >> q;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			t++;
		}
	}
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1 << j)) par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	for(ll i = 0; i < q; i++){
		cin >> v >> u;
		if(e[v] != e[u]){
			cout << "No\n";
			return 0;
		}
		p = lca(v, u);
		a[v]++;
		a[p]--;
		b[p]--;
		b[u]++;
	}
	
	fill(vis, vis + maxn, 0);
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) dfs2(i, -1);
	}
	
	cout << (f ? "No" : "Yes");
	
	return 0;
}