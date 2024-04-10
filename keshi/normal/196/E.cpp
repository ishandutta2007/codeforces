//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, a[maxn], dis[maxn], mn[maxn], nr[maxn], par[maxn], dsu[maxn], sz[maxn], ck, ans;

bool vis[maxn];

vector<pll> g[maxn];

priority_queue<pll> q;

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}

ll root(ll v){
	if(dsu[v] == v) return v;
	return root(dsu[v]);
}

bool Union(ll v, ll u){
	ll x = root(v), y = root(u);
	if(x == y) return 0;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	dsu[y] = x;
	return 1;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		g[v].pb({u, c});
		g[u].pb({v, c});
	}
	
	fill(dis, dis + n + 1, inf);
	q.push({0, 1});
	dis[1] = 0;
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(dis[u] > dis[v] + c){
				dis[u] = dis[v] + c;
				q.push({-dis[u], u});
			}
		}
	}
	
	ans = inf;
	
	init();
	
	cin >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> a[i];
		ans = min(ans, dis[a[i]]);
	}
	
	ck = k - 1;
	
	while(ck){
		fill(dis, dis + n + 1, inf);
		fill(vis, vis + n + 1, 0);
		fill(mn, mn + n + 1, inf);
		fill(nr, nr + n + 1, -1);
		for(ll i = 0; i < k; i++){
			dis[a[i]] = 0;
			par[a[i]] = root(a[i]);
			q.push({0, a[i]});
		}
		while(!q.empty()){
			v = q.top().S;
			q.pop();
			if(vis[v]) continue;
			vis[v] = 1;
			for(ll i = 0; i < g[v].size(); i++){
				u = g[v][i].F;
				c = g[v][i].S;
				if(dis[u] > dis[v] + c){
					dis[u] = dis[v] + c;
					par[u] = par[v];
					q.push({-dis[u], u});
				}
				if(par[u] != par[v]){
					if(mn[par[v]] > dis[v] + c + dis[u]){
						mn[par[v]] = dis[v] + c + dis[u];
						nr[par[v]] = par[u];
					}
					if(mn[par[u]] > dis[v] + c + dis[u]){
						mn[par[u]] = dis[v] + c + dis[u];
						nr[par[u]] = par[v];
					}
				}
			}
		}
		for(ll i = 0; i < k; i++){
			if(Union(par[a[i]], nr[par[a[i]]])){
				ans += mn[par[a[i]]];
				ck--;
			}
		}
	}
	
	
	cout << ans;
	
	return 0;
}