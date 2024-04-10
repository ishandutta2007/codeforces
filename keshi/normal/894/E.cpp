//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, s, c[maxn], a[maxn], b[maxn], dp[maxn], ans;

bool vis[maxn];

vector<pll> g[maxn], rg[maxn], h[maxn];

vector<ll> vec;

void dfs1(ll v){
	ll u, w;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]) dfs1(u);
	}
	vec.pb(v);
}

void dfs2(ll v){
	ll u, w;
	vis[v] = 1;
	c[v] = t;
	for(ll i = 0; i < rg[v].size(); i++){
		u = rg[v][i].F;
		w = rg[v][i].S;
		if(!vis[u]) dfs2(u);
		if(c[u] == c[v]){
			ll k = upper_bound(b, b + 20000, w) - b - 1;
			a[c[v]] += w * k - (k - 1) * k * (k + 1) / 6;
		}
		else{
			h[c[v]].pb({c[u], w});
		}
	}
	return;
}

int main(){
	ll v, u, w;
	fast_io;
	
	for(ll i = 1; i < 20000; i++){
		b[i] = i * (i - 1) / 2;
	}
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> w;
		g[v].pb({u, w});
		rg[u].pb({v, w});
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) dfs1(i);
	}
	
	fill(vis, vis + maxn, 0);
	reverse(vec.begin(), vec.end());
	
	for(ll i = 0; i < n; i++){
		if(!vis[vec[i]]){
			t++;
			dfs2(vec[i]);
		}
	}
	
	cin >> s;
	
	s = c[s];
	
	for(ll i = s; i <= t; i++){
		dp[i] = -inf;
		if(i == s) dp[i] = 0;
		for(ll j = 0; j < h[i].size(); j++){
			u = h[i][j].F;
			w = h[i][j].S;
			if(u < s) continue;
			dp[i] = max(dp[i], dp[u] + w);
		}
		dp[i] += a[i];
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}