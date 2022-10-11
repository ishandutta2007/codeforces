//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll maxm = 1e6 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, d[maxn], par[maxn][level], a[maxn], b[maxn], s[maxm], ans;

bool vis[maxn];

vector<pll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
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
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			dfs2(u, g[v][i].S);
			a[v] += a[u];
			b[v] += b[u];
		}
	}
	if(p == 1) ans = (ans + s[a[v]]) % mod;
	if(p == -1) ans = (ans + s[b[v]]) % mod;
}

int main(){
	ll v, u, c, p;
	fast_io;
	
	for(ll i = 1; i < maxm; i++){
		s[i] = (s[i - 1] * 2 + 1) % mod;
	}
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u >> c;
		if(c){
			g[v].pb({u, 1});
			g[u].pb({v, -1});
		}
		else{
			g[v].pb({u, 0});
			g[u].pb({v, 0});
		}
	}
	
	dfs(1);
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1 << j)) par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	cin >> k;
	
	v = 1;
	
	for(ll i = 0; i < k; i++){
		cin >> u;
		p = lca(v, u);
		a[v]++;
		a[p]--;
		b[p]--;
		b[u]++;
		v = u;
	}
	
	fill(vis, vis + maxn, 0);
	
	dfs2(1, 0);
	
	cout << ans;
	
	return 0;
}