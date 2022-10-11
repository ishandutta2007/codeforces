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

ll n, m, d[maxn], f[maxn], e[maxn], par[maxn][level], ans, cnt;

pll a[maxn], b[maxn];

bool vis[maxn], val[maxn];

vector<pll> g[maxn];

void dfs1(ll v){
	ll u, c;
	vis[v] = 1;
	vector<pll> vec;
	if(val[v]) vec.pb({0, v});
	else vec.pb({-inf, v});
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(!vis[u]){
			d[u] = d[v] + 1;
			par[u][0] = v;
			dfs1(u);
			vec.pb({a[u].F + c, a[u].S});
		}
	}
	sort(vec.begin(), vec.end(), greater<pll>());
	if(vec.size() == 1) a[v] = vec[0];
	else if(vec[0].F == vec[1].F) a[v] = {vec[0].F, v};
	else a[v] = vec[0];
	return;
}

void dfs2(ll v){
	ll u, c;
	vis[v] = 1;
	vector<pll> vec;
	vec.pb(b[v]);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(!vis[u]){
			vec.pb({a[u].F + c, a[u].S});
		}
	}
	sort(vec.begin(), vec.end(), greater<pll>());
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(vis[u]) continue;
		if(a[u].S == vec[0].S){
			if(vec.size() < 3) b[u] = vec[1];
			else{
				if(vec[1].F == vec[2].F) b[u] = {vec[1].F, v};
				else b[u] = vec[1];
			}
		}
		else if(a[u].S == vec[1].S){
			if(vec.size() < 3) b[u] = vec[0];
			else{
				if(vec[0].F == vec[2].F) b[u] = {vec[0].F, v};
				else b[u] = vec[0];
			}
		}
		else{
			if(vec[0].F == vec[1].F) b[u] = {vec[0].F, v};
			else b[u] = vec[0];
		}
		b[u].F += c;
	}
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]) dfs2(u);
	}
	return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]){
			dfs(u);
			f[v] += f[u];
		}
	}
	if(!val[v]){
		if(f[v] + e[v] > ans) ans = f[v] + e[v], cnt = 0;
		if(f[v] + e[v] == ans) cnt++;
	}
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

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v;
		val[v] = 1;
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u >> c;
		g[v].pb({u, c});
		g[u].pb({v, c});
	}
	
	dfs1(1);
	
	fill(vis, vis + maxn, 0);
	
	if(!val[1]) b[1] = {-inf, 1};
	else b[1] = {0, 1};
	
	dfs2(1);
	
	for(ll i = 1; i <= n; i++){
		if(a[i].F == b[i].F) a[i].S = i;
		else a[i] = max(a[i], b[i]);
	}
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1 << j)) par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(!val[i]) continue;
		v = i;
		u = a[i].S;
		c = lca(v, u);
		f[v]++;
		f[u]++;
		f[c] -= 2;
		e[c]++;
	}
	
	fill(vis, vis + maxn, 0);
	
	dfs(1);
	
	cout << ans << " " << cnt;
	
	return 0;
}