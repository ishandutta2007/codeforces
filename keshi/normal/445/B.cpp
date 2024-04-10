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

ll n, m, x;

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(!vis[u]){
			dfs(u);
		}
	}
	return;
}

int main(){
	ll u, v;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	x = n;
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			x--;
		}
	}
	
	cout << (1ll << x);
	
	return 0;
}