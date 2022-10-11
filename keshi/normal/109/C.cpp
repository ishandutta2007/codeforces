//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, sz[maxn], down[maxn], all[maxn], ans;

bool vis[maxn];

vector<pair<ll, bool> > g[maxn];

bool check(ll x){
	while(x){
		if(x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

void dfs2(ll v){
	ll u;
	vis[v] = 1;
	ans += all[v] * (all[v] - 1);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(vis[u]) continue;
		if(g[v][i].S){
			all[u] = n - sz[u] + down[u];
		}
		else{
			all[u] = all[v];
		}
		dfs2(u);
	}
	return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(vis[u]) continue;
		dfs(u);
		sz[v] += sz[u];
		if(g[v][i].S){
			down[v] += sz[u];
		}
		else{
			down[v] += down[u];
		}
	}
	return;
}

int main(){
	ll v, u, w;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u >> w;
		g[v].pb({u, check(w)});
		g[u].pb({v, check(w)});
	}
	
	dfs(1);
	all[1] = down[1];
	fill(vis, vis + n + 1, 0);
	dfs2(1);
	
	cout << ans;
	
	return 0;
}