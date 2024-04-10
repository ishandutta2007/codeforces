//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll lg = 18;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dsu[maxn], sz[maxn], ans[maxn], par[lg][maxn], mx[lg][maxn], d[maxn];
bool vis[maxn], val[maxn];
vector<pll> g[maxn], q1[maxn], q2[maxn];
set<pll> s[maxn];

pair<pll, pll> e[maxn];

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	return;
}

ll root(ll v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}

bool Union(ll v, ll u){
	v = root(v);
	u = root(u);
	if(v == u) return 0;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += u;
	return 1;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(vis[u]) continue;
		par[0][u] = v;
		mx[0][u] = e[g[v][i].S].F.F;
		d[u] = d[v] + 1;
		dfs(u);
	}
	return;
}

pll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	ll h = d[v] - d[u], c = -inf;
	for(ll i = 0; i < lg; i++){
		if((h >> i) & 1) c = max(c, mx[i][v]), v = par[i][v];
	}
	for(ll i = lg; i--;){
		if(d[v] >= (1ll << i) && par[i][v] != par[i][u]){
			c = max(c, max(mx[i][v], mx[i][u]));
			v = par[i][v];
			u = par[i][u];
		}
	}
	if(v != u){
		c = max(c, max(mx[0][v], mx[0][u]));
		v = par[0][v];
	}
	return Mp(v, c);
}

void solve(ll v){
	ll u, c;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(vis[u]) continue;
		solve(u);
		if(s[u].empty()) ans[e[c].F.S] = -1;
		else ans[e[c].F.S] = s[u].begin() -> F - 1;
		if(s[v].size() < s[u].size()) s[u].swap(s[v]);
		for(set<pll>::iterator it = s[u].begin(); it != s[u].end(); it++){
			s[v].insert(*it);
		}
		s[u].clear();
	}
	for(ll i = 0; i < q1[v].size(); i++){
		s[v].insert(q1[v][i]);
	}
	for(ll i = 0; i < q2[v].size(); i++){
		s[v].erase(q2[v][i]);
	}
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].S.F >> e[i].S.S >> e[i].F.F;
		e[i].F.S = i;
	}
	
	sort(e, e + m);
	init();
	
	for(ll i = 0; i < m; i++){
		v = e[i].S.F;
		u = e[i].S.S;
		if(Union(v, u)){
			g[v].pb(Mp(u, i));
			g[u].pb(Mp(v, i));
			val[i] = 1;
		}
	}
	
	dfs(1);
	
	for(ll j = 1; j < lg; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] >= (1ll << j)) par[j][i] = par[j - 1][par[j - 1][i]], mx[j][i] = max(mx[j - 1][i], mx[j - 1][par[j - 1][i]]);
		}
	}
	
	for(ll i = 0; i < m; i++){
		if(val[i]) continue;
		v = e[i].S.F;
		u = e[i].S.S;
		pll pl = lca(v, u);
		ans[e[i].F.S] = pl.S - 1;
		q1[v].pb(Mp(e[i].F.F, i));
		q1[u].pb(Mp(e[i].F.F, i));
		q2[pl.F].pb(Mp(e[i].F.F, i));
	}
	
	fill(vis, vis + maxn, 0);
	solve(1);
	
	for(ll i = 0; i < m; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}