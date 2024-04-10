//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, t, p[maxn], pp[maxn], h[maxn], d[maxn], vis[maxn], a[maxn], mn[maxn], dp[maxn], ans[maxn];
vector<ll> g[maxn], gg[maxn], vec;

void dfs(ll v){
	vec.pb(v);
	pp[v] = vec[max(0ll, Sz(vec) - 1 - k)];
	if(g[v].empty()) gg[pp[v]].pb(v);
	for(ll u : g[v]){
		h[u] = h[v] + 1;
		dfs(u);
	}
	vec.pop_back();
}
void dfs2(ll v){
	if(vis[v]) return;
	vis[v] = 1;
	for(ll u : g[v]){
		dfs2(u);
	}
	if(g[v].empty()) dfs2(pp[v]);
	vec.pb(v);
}
void dfs3(ll v){
	if(!vis[v]) return;
	a[v] = t;
	mn[t] = min(mn[t], h[v]);
	vis[v] = 0;
	for(ll u : gg[v]){
		dfs3(u);
	}
	if(v > 1) dfs3(p[v]);
	return;
}
void dfs4(ll v){
	for(ll u : g[v]){
		dfs4(u);
		if(mn[a[u]] < h[v]) dp[v] += dp[u];
	}
	if(g[v].empty()) dp[v]++;
	return;
}
void solve(ll v){
	ll x = 0;
	for(ll u : g[v]){
		solve(u);
		x += dp[u];
	}
	ans[v] = dp[v];
	for(ll u : g[v]){
		ans[v] = max(ans[v], x - dp[u] + ans[u]);
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> k;
    for(ll i = 2; i <= n; i++){
    	cin >> p[i];
    	g[p[i]].pb(i);
	}
	dfs(1);
	dfs2(1);
	for(ll i = Sz(vec); i--;){
		if(vis[vec[i]]){
			mn[t] = inf;
			dfs3(vec[i]);
			t++;
		}
	}
	for(ll i = 0; i < Sz(vec); i++){
		for(ll u : g[i]){
			if(a[i] != a[u]) mn[a[i]] = min(mn[a[i]], mn[a[u]]);
		}
		if(g[i].empty()) mn[a[i]] = min(mn[a[i]], mn[a[pp[i]]]);
	}
	dfs4(1);
	solve(1);
	cout << ans[1];
 
    return 0;
}