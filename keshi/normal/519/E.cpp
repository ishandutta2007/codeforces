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

ll n, m, t, st[maxn], ft[maxn], par[maxn][level], d[maxn], sz[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	st[v] = t++;
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			par[u][0] = v;
			d[u] = d[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
	}
	ft[v] = t;
	return;
}

ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	ll h = d[v] - d[u], x = 0;
	for(ll i = 0; i < level; i++){
		if((h >> i) & 1){
			v = par[v][i];
			x += (1 << i);
		}
	}
	for(ll i = level - 1; i--;){
		if(d[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
			x += 2 * (1 << i);
		}
	}
	if(v != u) x += 2;
	return x;
}

int main(){
	ll v, u, h, p;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1 << j)) par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		if(d[v] < d[u]) swap(v, u);
		h = lca(v, u);
		if(h % 2){
			cout << "0\n";
			continue;
		}
		p = v;
		for(ll i = 1; i < level; i++){
			if((h >> i) & 1){
				p = par[p][i - 1];
			}
		}
		if(st[u] >= st[p] && st[u] < ft[p]){
			h = h / 2 - 1;
			for(ll i = 0; i < level; i++){
				if((h >> i) & 1){
					v = par[v][i];
					u = par[u][i];
				}
			}
			cout << n - sz[u] - sz[v] << '\n';
		}
		else{
			h = h / 2 - 1;
			for(ll i = 0; i < level; i++){
				if((h >> i) & 1){
					v = par[v][i];
				}
			}
			cout << sz[p] - sz[v] << '\n';
		}
	}
	
	return 0;
}