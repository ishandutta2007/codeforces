//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 320;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, par[maxn], a[maxn];

bool vis[maxn];

bool in[maxn][maxn];

vector<ll> g[maxn], sub[maxn], child[maxn], ans;

void dfs(ll v){
	ll u;
	bool t = 1;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		dfs(u);
		child[v].pb(u);
		for(ll j = 0; j < sub[u].size(); j++){
			sub[v].pb(sub[u][j]);
			in[v][sub[v].back()] = 1;
		}
		t = 0;
	}
	if(t){
		k++;
		sub[v].pb(v);
		in[v][v] = 1;
	}
	return;
}

bool solve(ll v, ll l, ll r){
	ll u;
	bool f;
	ans.pb(v);
	if(child[v].empty()){
		return (a[l] == v);
	}
	while(l < r){
		f = 1;
		for(ll i = 0; i < child[v].size(); i++){
			u = child[v][i];
			if(in[u][a[l]]){
				if(!solve(u, l, l + sub[u].size())) return 0;
				l += sub[u].size();
				ans.pb(v);
				f = 0;
			}
		}
		if(f) return 0;
	}
	return 1;
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
	
	for(ll i = 0; i < k; i++){
		cin >> a[i];
	}
	
	if(!solve(1, 0, k)){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}