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

ll n, m, h[maxn];

bool vis[maxn];

vector<ll> g[maxn], o[maxn];

void dfs(ll v, ll p){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
		else if(u != p && h[u] < h[v]) o[v].pb(u);
	}
	if(o[v].size() % 2) o[v].pb(p);
	else o[p].pb(v);
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	if(m % 2){
		cout << "No solution";
		return 0;
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1, 0);
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j + 1 < o[i].size(); j += 2){
			cout << o[i][j] << " " << i << " " << o[i][j + 1] << '\n';
		}
	}
	
	return 0;
}