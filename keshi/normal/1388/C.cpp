//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, m, p[maxn], h[maxn], c[maxn], d[maxn];
vector<ll> g[maxn];
bool ok;

void dfs(ll v, ll par){
	ll u, x = 0;
	c[v] = p[v];
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(u == par) continue;
		dfs(u, v);
		c[v] += c[u];
		x += d[u];
	}
	if((c[v] + h[v]) & 1) ok = 0;
	d[v] = (c[v] + h[v]) / 2;
	if(x > d[v] || d[v] > c[v] || d[v] < 0) ok = 0;
	return;
}

int main(){
	fast_io;
	ll v, u;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			cin >> p[i];
		}
		for(ll i = 1; i <= n; i++){
			cin >> h[i];
		}
		for(ll i = 1; i < n; i++){
			cin >> v >> u;
			g[u].pb(v);
			g[v].pb(u);
		}
		ok = 1;
		dfs(1, 0);
		cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}