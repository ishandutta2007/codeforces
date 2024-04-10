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

ll n, m, d[maxn], p[maxn], h[maxn];

bool vis[maxn];

vector<ll> g[maxn];

vector<pll> vec;

void dfs(ll v){
	ll u;
	vis[v] = 1;
	h[v] = inf;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			p[u] = v;
			dfs(u);
			if(h[u] < d[u]){
				vec.pb({v, u});
			}
			h[v] = min(h[v], h[u]);
		}
		else if(u != p[v] && d[u] < d[v]){
			h[v] = min(h[v], d[u]);
			vec.pb({v, u});
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	if(vec.size() != m){
		cout << 0;
		return 0;
	}
	
	for(ll i = 0; i < m; i++){
		cout << vec[i].F << " " << vec[i].S << '\n';
	}
	
	return 0;
}