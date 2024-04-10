//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, t, a[maxn], b[maxn], c[maxn], d[maxn];

bool vis[maxn];

vector<ll> g[maxn], r[maxn], ps[maxn];
map<ll, ll> ans[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			a[u] = a[v];
			dfs(u);
			c[v] = max(c[v], c[u] + 1);
		}
	}
	return;
}

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	r[a[v]].pb(max(c[v], d[v]));
	vector<pll> vec;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) vec.pb(Mp(c[u] + 1, u));
	}
	sort(vec.begin(), vec.end(), greater<pll>());
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			if(vec[0].S != u){
				d[u] = max(d[v] + 1, vec[0].F + 1);
			}
			else{
				d[u] = d[v] + 1;
				if(vec.size() > 1){
					d[u] = max(d[u], vec[1].F + 1);
				}
			}
			dfs1(u);
		}
	}
	return;
}

int main(){
	ll v, u, x;
	fast_io;
	cout << setprecision(10) << fixed;
	
	cin >> n >> m >> q;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			b[t] = i;
			a[i] = t++;
			dfs(i);
		}
	}
	
	fill(vis, vis + maxn, 0);
	
	for(ll i = 0; i < t; i++){
		dfs1(b[i]);
		sort(r[i].begin(), r[i].end());
		ps[i].resize(r[i].size() + 1);
		for(ll j = r[i].size(); j--;){
			ps[i][j] = ps[i][j + 1] + r[i][j];
		}
	}
	
	while(q--){
		cin >> v >> u;
		v = a[v];
		u = a[u];
		if(r[v].size() > r[u].size()) swap(v, u);
		else if(r[v].size() == r[u].size() && v > u) swap(v, u);
		if(v == u){
			cout << -1 << '\n';
			continue;
		}
		if(ans[v][u] == 0){
			ll j = 0;
			x = 0;
			for(ll i = r[v].size(); i--;){
				//while(j < r[u].size() && r[v][i] + r[u][j] + 1 < max(r[v].back(), r[u].back())) j++;
				j = lower_bound(r[u].begin(), r[u].end(), max(r[v].back(), r[u].back()) - r[v][i] - 1) - r[u].begin();
				x += (r[v][i] + 1) * (r[u].size() - j) + ps[u][j] + j * max(r[v].back(), r[u].back());
			}
			ans[v][u] = x;
		}	
		cout << ans[v][u] * 1.0 / (r[v].size() * r[u].size()) << '\n';
	}
	
	return 0;
}