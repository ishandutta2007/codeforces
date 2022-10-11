//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, w[maxn], h[maxn], d[maxn], s, t;

bool f = 1, is[maxn], vis[maxn];

vector<pll> g[maxn];
vector<ll> ve;
pll x;
pair<ll, pll> ans;

void dfs(ll v){
	ll u, e;
	vis[v] = 1;
	if(v == t) f = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		e = g[v][i].S;
		if(vis[u]) continue;
		if(f) ve.pb(e);
		dfs(u);
	}
	if(f) ve.pop_back();
	return;
}

bool solve(ll v, ll p){
	ll u, e;
	bool fp = 0;
	if(v == t) fp = 1;
	vis[v] = 1;
	h[v] = inf;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		e = g[v][i].S;
		if(is[e]) continue;
		if(vis[u]){
			if(e != p) h[v] = min(h[v], d[u]);
			continue;
		}
		d[u] = d[v] + 1;
		f = solve(u, e);
		if(f) fp = 1;
		if(h[u] >= d[u] && f) x = min(x, {w[e], e});
		h[v] = min(h[v], h[u]);
	}
	return fp;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	cin >> s >> t;
	
	for(ll i = 1; i <= m; i++){
		cin >> v >> u >> w[i];
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	
	ve.pb(0);
	dfs(s);
	
	if(!vis[t]){
		cout << "0\n0";
		return 0;
	}
	
	ans = {inf, {-1, -1}};
	
	for(ll i = 0; i < ve.size(); i++){
		is[ve[i]] = 1;
		x = {inf, -1};
		fill(vis, vis + n + 1, 0);
		solve(s, -1);
		ans = min(ans, {x.F + w[ve[i]], {ve[i], x.S}});
		is[ve[i]] = 0;
	}
	
	if(ans.F == inf){
		cout << -1;
		return 0;
	}
	
	cout << ans.F << '\n';
	
	if(ans.S.F == 0) cout << "1\n" << ans.S.S;
	else cout << "2\n" << ans.S.F << " " << ans.S.S;
	
	return 0;
}