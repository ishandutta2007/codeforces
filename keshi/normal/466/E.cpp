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

ll n, m, dsu[maxn], rt[maxn], ft[maxn], st[maxn], sz[maxn], t, x, a[maxn], b[maxn];

bool vis[maxn];

vector<ll> g[maxn];

vector<pll> vec;

void dfs(ll v){
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		dfs(g[v][i]);
	}
	ft[v] = t;
}

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
		rt[i] = i;
	}
	return;
}

ll par(ll v){
	if(v != dsu[v]) dsu[v] = par(dsu[v]);
	return dsu[v];
}

void Union(ll v, ll u){
	v = par(v);
	u = par(u);
	ll r = rt[v];
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	rt[v] = r;
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	init();
	
	for(ll i = 0; i < m; i++){
		cin >> c;
		if(c == 1){
			cin >> v >> u;
			vis[v] = 1;
			g[u].pb(v);
			Union(u, v);
		}
		else if(c == 2){
			cin >> v;
			x++;
			a[x] = rt[par(v)];
			b[x] = v;
		}
		else{
			cin >> v >> u;
			vec.pb({v, u});
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}
	
	for(ll i = 0; i < vec.size(); i++){
		v = vec[i].F;
		u = a[vec[i].S];
		c = b[vec[i].S];
		if(st[v] >= st[u] && st[v] < ft[u] && st[c] >= st[v] && st[c] < ft[v]) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}