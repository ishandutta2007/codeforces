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

ll n, m, t, ans, b[maxn], x;

bool vis[maxn], f;

vector<ll> g[maxn], h[maxn], a[maxn];

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	a[t].pb(v);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs1(u);
	}
	return;
}

void dfs2(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < h[v].size(); i++){
		u = h[v][i];
		if(!vis[u]) dfs2(u);
	}
	b[v] = x++;
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
		h[v].pb(u);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs1(i);
			t++;
		}
	}
	
	fill(vis, vis + maxn, 0);
	
	ans = n;
	
	for(ll i = 0; i < t; i++){
		for(ll j = 0; j < a[i].size(); j++){
			v = a[i][j];
			if(!vis[v]) dfs2(v);
		}
		f = 1;
		for(ll j = 0; j < a[i].size(); j++){
			v = a[i][j];
			for(ll k = 0; k < h[v].size(); k++){
				if(b[v] < b[h[v][k]]) f = 0;
			}
		}
		if(f) ans--;
	}
	
	cout << ans;
	
	return 0;
}