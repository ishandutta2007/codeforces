//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, dp[maxn][level][12], par[maxn][level], d[maxn];

bool vis[maxn];

vector<ll> g[maxn], h[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
	return;
}

void lca(ll v, ll u, ll x){
	if(d[v] < d[u]) swap(v, u);
	ll p1, p2, h = d[v] - d[u], a[10], b[10];
	fill(a, a + 10, inf);
	for(ll i = 0; i < level; i++){
		if((h >> i) & 1){
			p1 = p2 = 0;
			for(ll j = 0; j < 10; j++){
				if(dp[v][i][p1] < a[p2]) b[j] = dp[v][i][p1++];
				else b[j] = a[p2++];
			}
			for(ll j = 0; j < 10; j++){
				a[j] = b[j];
			}
			v = par[v][i];
		}
	}
	for(ll i = level - 1; i--;){
		if(d[v] < (1 << i) || par[v][i] == par[u][i]) continue;
		p1 = p2 = 0;
		for(ll j = 0; j < 10; j++){
			if(dp[v][i][p1] < a[p2]) b[j] = dp[v][i][p1++];
			else b[j] = a[p2++];
		}
		p1 = p2 = 0;
		for(ll j = 0; j < 10; j++){
			if(dp[u][i][p1] < b[p2]) a[j] = dp[u][i][p1++];
			else a[j] = b[p2++];
		}
		v = par[v][i];
		u = par[u][i];
	}
	if(v != u){
		p1 = p2 = 0;
		for(ll j = 0; j < 10; j++){
			if(dp[v][0][p1] < a[p2]) b[j] = dp[v][0][p1++];
			else b[j] = a[p2++];
		}
		p1 = p2 = 0;
		for(ll j = 0; j < 10; j++){
			if(dp[u][0][p1] < b[p2]) a[j] = dp[u][0][p1++];
			else a[j] = b[p2++];
		}
		v = par[v][0];
		u = par[u][0];
	}
	ll k = 0;
	p1 = p2 = 0;
	for(ll j = 0; j < 10; j++){
		if(dp[v][0][p1] < a[p2]) b[j] = dp[v][0][p1++];
		else b[j] = a[p2++];
		if(b[j] < inf) k++;
	}
	for(ll j = 0; j < 10; j++){
		a[j] = b[j];
	}
	k = min(k, x);
	cout << k;
	for(ll i = 0; i < k; i++){
		cout << " " << a[i];
	}
	cout << '\n';
}

int main(){
	ll v, u, p1, p2, x;
	fast_io;
	
	cin >> n >> m >> q;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v;
		h[v].pb(i + 1);
	}
	
	for(ll i = 1; i <= n; i++){
		sort(h[i].begin(), h[i].end());
		for(ll j = 0; j < h[i].size(); j++){
			if(j >= 10) break;
			dp[i][0][j] = h[i][j];
		}
		for(ll j = h[i].size(); j < 10; j++){
			dp[i][0][j] = inf;
		}
	}
	
	dfs(1);
	
	for(ll j = 1; j < level; j++){
		for(ll i = 1; i <= n; i++){
			if(d[i] < (1 << j)) continue;
			par[i][j] = par[par[i][j - 1]][j - 1];
			v = par[i][j - 1];
			p1 = p2 = 0;
			for(ll k = 0; k < 10; k++){
				if(dp[i][j - 1][p1] < dp[v][j - 1][p2]) dp[i][j][k] = dp[i][j - 1][p1++];
				else dp[i][j][k] = dp[v][j - 1][p2++];
			}
		}
	}
	
	while(q--){
		cin >> v >> u >> x;
		lca(v, u, x);
	}
	
	return 0;
}