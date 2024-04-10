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

ll n, dsu[maxn], sz[maxn], dp[maxn], r[maxn], d[maxn], ans[maxn], x;

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
 
bool find(ll i, ll j){
	return (root(i) == root(j));
}
 
void Union(ll i, ll j){
	if (find(i, j)) return;
    ll v = root(i), u = root(j);
    if(sz[v] > sz[u]) swap(v, u);
	dsu[v] = dsu[u];
	sz[u] += sz[v];
	return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	dp[v] = sz[v];
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(vis[u]) continue;
		r[u] = r[v];
		d[u] = g[v][i].S;
		dfs(u);
		dp[v] += dp[u];
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	initialize();
	
	for(ll i = 0; i < n - 1; i++){
		cin >> e[i].S.F >> e[i].S.S >> e[i].F.F;
		e[i].F.S = i + 1;
	}
	
	sort(e, e + n - 1);
	
	for(ll i = 0; i < n - 1; ){
		ll j = i;
		while(j < n - 1 && e[i].F.F == e[j].F.F){
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
			d[vec[j]] = 0;
			r[vec[j]] = vec[j];
			dfs(vec[j]);
		}
		
		for(ll j = 0; j < vec.size(); j++){
			ans[d[vec[j]]] = dp[vec[j]] * (dp[r[vec[j]]] - dp[vec[j]]);
		}
		
		for(ll j = 0; j < vec.size(); j++){
			g[vec[j]].clear();
			dp[vec[j]] = 0;
			vis[vec[j]] = 0;
		}
		vec.clear();
		
		while(i < j){
			Union(e[i].S.F, e[i].S.S);
			i++;
		}
	}
	
	for(ll i = 1; i < n; i++){
		if(ans[i] > x){
			x = ans[i];
			vec.clear();
		}
		if(x == ans[i]) vec.pb(i);
	}
	
	cout << x * 2 << " " << vec.size() << endl;
	
	sort(vec.begin(), vec.end());
	
	for(ll i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	
	return 0;
}