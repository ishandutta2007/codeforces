
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, r[maxn], c[maxn], d[maxn], h[maxn], s[maxn], sz[maxn], b[maxn], ans, x;

bool vis[maxn], val[maxn];

vector<pll> g[maxn];
vector<ll> g2[maxn];

void dfs1(ll v, ll e){
	ll u, w;
	vis[v] = 1;
	h[v] = inf;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S;
		if(w == e) continue;
		if(vis[u]) h[v] = min(h[v], d[u]), val[w] = 1;
		else{
			d[u] = d[v] + 1;
			dfs1(u, w);
			if(h[u] <= d[v]) val[w] = 1;
			h[v] = min(h[v], h[u]);
		}
	}
	return;
}

void dfs2(ll v){
	ll u, w;
	vis[v] = 1;
	c[v] = t;
	sz[t]++;
	s[t] += r[v];
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S;
		if(val[w] && !vis[u]) dfs2(u);
	}
	return;
}

void dfs3(ll v){
	ll u;
	vis[v] = 1;
	if(sz[v] > 1) val[v] = 1;
	for(ll i = 0; i < g2[v].size(); i++){
		u = g2[v][i];
		if(!vis[u]){
			dfs3(u);
			b[v] = max(b[v], b[u]);
			if(val[u]) val[v] = 1;
		}
	}
	b[v] += s[v];
	if(val[v]) ans += s[v];
	else x = max(x, b[v]);
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> r[i];
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb({u, i + 1});
		g[u].pb({v, i + 1});
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) dfs1(i, 0);
	}
	
	fill(vis, vis + maxn, 0);
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			t++;
			dfs2(i);
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < g[i].size(); j++){
			v = g[i][j].F;
			u = g[i][j].S;
			if(!val[u]) g2[c[i]].pb(c[v]);
		}
	}
	
	fill(vis, vis + maxn, 0);
	fill(val, val + maxn, 0);
	
	cin >> v;
	v = c[v];
	
	dfs3(v);
	
	cout << ans + x;
	
	return 0;
}