//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll maxm = 2e6;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, c[maxn], d[maxn], h[maxn], s[maxn], sz[maxn], ans, x;

bool vis[maxn], val[maxm];

bitset<maxn> b;

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
	s[t]++;
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
	x += s[v] * (s[v] + d[v]);
	sz[v] = s[v];
	for(ll i = 0; i < g2[v].size(); i++){
		u = g2[v][i];
		if(!vis[u]){
			d[u] = d[v] + s[v];
			dfs3(u);
			sz[v] += sz[u];
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb({u, i + 1});
		g[u].pb({v, i + 1});
	}
	
	dfs1(1, 0);
	
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
	
	for(ll i = 1; i <= t; i++){
		fill(vis, vis + maxn, 0);
		d[i] = 0;
		x = 0;
		dfs3(i);
		b.reset();
		b[0] = 1;
		for(ll j = 0; j < g2[i].size(); j++){
			v = g2[i][j];
			b |= (b << sz[v]);
		}
		for(ll j = 0; j < n; j++){
			if(b[j]) ans = max(ans, x + j * (n - s[i] - j));
		}
	}
	
	cout << ans;
	
	return 0;
}