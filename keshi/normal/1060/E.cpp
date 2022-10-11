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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c[2], s, sz[maxn], d[maxn];
bool vis[maxn];
vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	c[d[v] & 1]++;
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			dfs(u);
			s += sz[u] * (n - sz[u]);
			sz[v] += sz[u];
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	cout << (s - c[0] * c[1]) / 2 + c[0] * c[1];
	
	return 0;
}