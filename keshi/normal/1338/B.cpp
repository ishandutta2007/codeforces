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

ll n, h[maxn], x, c;

bool vis[maxn], f[2];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			h[u] = h[v] + 1;
			dfs(u);
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
	
	for(ll i = 1; i <= n; i++){
		if(g[i].size() == 1) f[h[i] % 2] = 1;
	}
	
	x = n - 1;
	
	for(ll i = 1; i <= n; i++){
		c = 0;
		for(ll j = 0; j < g[i].size(); j++){
			u = g[i][j];
			if(g[u].size() == 1) c++;
		}
		x -= max(0ll, c - 1);
	}
	
	if(f[0] && f[1]) cout << "3 ";
	else cout << "1 ";
	cout << x;
	
	return 0;
}