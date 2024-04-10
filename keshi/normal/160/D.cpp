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

ll n, m, dsu[maxn], sz[maxn], dp[maxn], ans[maxn], h[maxn];

bool vis[maxn];

pair<pll, pll> e[maxn];

vector<pll> g[maxn];

vector<ll> vec;

void initialize(){
    for(ll i = 1; i <= n; i++){
    	dsu[i] = i;
    	sz[i] = 1;
	}
}

ll root(ll i){
	if (dsu[i] == i) return dsu[i];
	dsu[i] = root(dsu[i]);
	return dsu[i];
}

void Union(ll i, ll j){
    ll v = root(i), u = root(j);
    if(v == u) return;
    if(sz[v] > sz[u]) swap(v, u);
	dsu[v] = dsu[u];
	sz[u] += sz[v];
	return;
}

void dfs(ll v, ll d){
	ll u, k;
	vis[v] = 1;
	dp[v] = inf;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		k = g[v][i].S;
		if(!vis[u]){
			h[u] = h[v] + 1;
			dfs(u, k);
			dp[v] = min(dp[v], dp[u]);
		}
		else if(d != k){
			dp[v] = min(dp[v], h[u]);
		}
		if(u == v) ans[k] = 0;
		else{
			if(dp[u] <= h[v]) ans[k] = 1;
			else ans[k] = 2;
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	initialize();
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].S.F >> e[i].S.S >> e[i].F.F;
		e[i].F.S = i;
	}
	
	sort(e, e + m);
	
	for(ll i = 0; i < m; ){
		ll j = i;
		while(j < m && e[i].F.F == e[j].F.F){
			e[j].S.F = root(e[j].S.F);
			e[j].S.S = root(e[j].S.S);
			vec.pb(e[j].S.F);
			vec.pb(e[j].S.S);
			g[e[j].S.F].pb({e[j].S.S, e[j].F.S});
			g[e[j].S.S].pb({e[j].S.F, e[j].F.S});
			j++;
		}
		
		for(ll j = 0; j < vec.size(); j++){
			if(vis[vec[j]]) continue;
			h[vec[j]] = 0;
			dfs(vec[j], -1);
		}
		
		for(ll j = 0; j < vec.size(); j++){
			g[vec[j]].clear();
			vis[vec[j]] = 0;
		}
		vec.clear();
		
		while(i < j){
			Union(e[i].S.F, e[i].S.S);
			i++;
		}
	}
	
	for(ll i = 0; i < m; i++){
		if(ans[i] == 0){
			cout << "none";
		}
		else if(ans[i] == 1){
			cout << "at least one";
		}
		else{
			cout << "any";
		}
		cout << '\n';
	}
	
	return 0;
}