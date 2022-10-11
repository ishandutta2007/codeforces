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

ll n, k, s, d[maxn], sz[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	for(ll i = 1; i <= n; i++){
		d[i] -= sz[i] - 1;
	}
	
	sort(d + 1, d + n + 1, greater<ll>());
	
	for(ll i = 1; i <= k; i++){
		s += d[i];
	}
	
	cout << s;
	
	return 0;
}