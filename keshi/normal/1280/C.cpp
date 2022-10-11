//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, sz[maxn], G, B;

bool vis[maxn];

vector<pll> g[maxn];

void dfs(ll v){
	ll u, c;
	vis[v] = 1;
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(vis[u]) continue;
		dfs(u);
		sz[v] += sz[u];
		if(sz[u] % 2){
			G += c;
		}
		B += min(sz[u], n - sz[u]) * c;
	}
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		n = n * 2;
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			vis[i] = 0;
			sz[i] = 0;
		}
		for(ll i = 1; i < n; i++){
			cin >> v >> u >> c;
			g[v].pb({u, c});
			g[u].pb({v, c});
		}
		G = B = 0;
		dfs(1);
		cout << G << " " << B << '\n';
	}
	
	return 0;
}