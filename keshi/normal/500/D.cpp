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

ll n, q, t[maxn], a[maxn], c[maxn], ans;

bool vis[maxn];

vector<pll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	t[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i].F;
		if(!vis[u]){
			dfs(u);
			a[g[v][i].S] = t[u];
			t[v] += t[u];
		}
	}
	return;
}

int main(){
	cout << fixed << setprecision(10);
	ll u, v;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> u >> v >> c[i];
		g[u].pb({v, i});
		g[v].pb({u, i});
	}
	
	dfs(1);
	
	for(ll i = 1; i < n; i++){
		ans += a[i] * (n - a[i]) * c[i];
	}
	
	cin >> q;
	
	while(q--){
		cin >> v >> u;
		ans -= a[v] * (n - a[v]) * c[v];
		c[v] = u;
		ans += a[v] * (n - a[v]) * c[v];
		cout << (ans * 6.0) / (n * (n - 1)) << endl;
	}
	
	return 0;
}