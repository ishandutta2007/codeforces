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

ll n, m, k, d[maxn], dv, p[maxn];
bool vis[maxn];
vector<ll> g[maxn], a, b;
pll ans;

void dfs(ll v){
	ll u;
	vis[v] = 1;
	if(d[v] >= d[dv]) dv = v;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) d[u] = d[v] + 1, dfs(u);
	}
	return;
}

void solve(ll v){
	ll u;
	vis[v] = 1;
	if(d[v] & 1) a.pb(v);
	else b.pb(v);
	if(d[v] >= d[dv]) dv = v;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) p[u] = v, d[u] = d[v] + 1, solve(u);
		else if(d[v] > d[u] && u != p[v]){
			if(d[v] - d[u] < k) ans = Mp(v, u);
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> k;
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	fill(vis, vis + maxn, 0);
	fill(d, d + maxn, 0);
	dfs(dv);
	fill(vis, vis + maxn, 0);
	fill(d, d + maxn, 0);
	solve(dv);
	if(ans.F){
		cout << "2\n" << d[ans.F] - d[ans.S] + 1 << '\n';
		while(ans.F != ans.S){
			cout << ans.F << " ";
			ans.F = p[ans.F];
		}
		cout << ans.S;
		return 0;
	}
	cout << "1\n";
	if(a.size() >= (k + 1) / 2){
		for(ll i = 0; i < (k + 1) / 2; i++){
			cout << a[i] << " ";
		}
		return 0;
	}
	if(b.size() >= (k + 1) / 2){
		for(ll i = 0; i < (k + 1) / 2; i++){
			cout << b[i] << " ";
		}
		return 0;
	}
	for(ll i = 0; i < (k + 1) / 2; i++){
		cout << dv << " ";
		dv = p[p[dv]];
	}
	
	return 0;
}