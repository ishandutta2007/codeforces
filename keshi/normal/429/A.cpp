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

ll n, par[maxn];

bool a[maxn], b[maxn];

vector<ll> g[maxn], ans;

void dfs(ll v){
	ll u = par[par[v]];
	if((a[v] == b[v]) != (a[u] == b[u])) ans.pb(v);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(u != par[v]){
			par[u] = v;
			dfs(u);
		}
	}
}

int main(){
	ll u, v;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
	}
	
	dfs(1);
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}