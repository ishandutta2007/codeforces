//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, p, dis[maxn], par[maxn], dsu[maxn], ans[maxn];

bool vis[maxn];

vector<pair<ll, pll> > e;

vector<pll> g[maxn], vec[maxn];

vector<ll> a[maxn];

priority_queue<pll> q;

void init(){
	for(ll i = 1; i <= k; i++){
		dsu[i] = i;
		a[i].pb(i);
	}
	return;
}

void Union(ll v, ll u, ll c){
	ll x, y;
	v = dsu[v];
	u = dsu[u];
	if(v == u) return;
	if(a[v].size() < a[u].size()) swap(v, u);
	for(ll i = 0; i < a[u].size(); i++){
		x = a[u][i];
		a[v].pb(x);
		dsu[x] = v;
		for(ll j = 0; j < vec[x].size(); j++){
			y = vec[x][j].F;
			if(dsu[y] == dsu[x]){
				ans[vec[x][j].S] = min(ans[vec[x][j].S], c);
			}
		}
	}
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m >> k >> p;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		g[v].pb({u, c});
		g[u].pb({v, c});
	}
	
	for(ll i = 0; i < p; i++){
		cin >> v >> u;
		vec[v].pb({u, i});
		vec[u].pb({v, i});
		ans[i] = inf;
	}
	
	fill(dis, dis + maxn, inf);
	
	for(ll i = 1; i <= k; i++){
		dis[i] = 0;
		par[i] = i;
		q.push({-dis[i], i});
	}
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(dis[u] > dis[v] + c){
				dis[u] = dis[v] + c;
				par[u] = par[v];
				q.push({-dis[u], u});
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < g[i].size(); j++){
			u = g[i][j].F;
			c = g[i][j].S;
			if(u > i && par[i] != par[u]){
				e.pb({dis[i] + c + dis[u], {par[i], par[u]}});
			}
		}
	}
	
	init();
	
	sort(e.begin(), e.end());
	
	for(ll i = 0; i < e.size(); i++){
		c = e[i].F;
		v = e[i].S.F;
		u = e[i].S.S;
		Union(v, u, c);
	}
	
	for(ll i = 0; i < p; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}