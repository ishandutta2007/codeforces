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

ll n, m, a[maxn], b[maxn], c, d;

bool vis[maxn], val[maxn];

vector<ll> g[maxn];

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	a[v] = -inf;
	if(val[v]) a[v] = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dfs1(u);
			a[v] = max(a[v], a[u] + 1);
		}
	}
	return;
}

void dfs2(ll v){
	ll u;
	vis[v] = 1;
	if(val[v]) b[v] = max(b[v], 0ll);
	vector<pll> vec;
	vec.pb({b[v], v});
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		vec.pb({a[u] + 1, u});
	}
	sort(vec.begin(), vec.end(), greater<pll>());
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		if(u == vec[0].S) b[u] = vec[1].F + 1;
		else b[u] = vec[0].F + 1;
		dfs2(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> d;
	
	for(ll i = 0; i < m; i++){
		cin >> v;
		val[v] = 1;
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs1(1);
	
	fill(vis, vis + maxn, 0);
	
	b[1] = -inf;
	
	dfs2(1);
	
	for(ll i = 1; i <= n; i++){
		if(max(a[i], b[i]) <= d) c++;
	}
	
	cout << c;
	return 0;
}