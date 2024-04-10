//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll n, a[maxn], ans, dp[maxn][3], par[maxn];
vector<ll> g[maxn];
bool vis[maxn];

void dfs(ll v){
	dp[v][0] = dp[v][1] = dp[v][2] = a[v];
	ll m[2][4];
	memset(m, 0, sizeof m);
	for(ll i = 0; i < Sz(g[v]); i++){
		ll u = g[v][i];
		if(u == par[v]) continue;
		par[u] = v;
		dfs(u);
		dp[v][0] = max(dp[v][0], dp[u][0] + a[v]);
		dp[v][1] = max(dp[v][1], dp[u][1]);
		dp[v][2] = max(dp[v][2], dp[u][2] + a[v]);
		m[0][3] = dp[u][0];
		for(ll j = 3; j--;){
			if(m[0][j] < m[0][j + 1]) swap(m[0][j], m[0][j + 1]);
		}
		m[1][3] = dp[u][1];
		for(ll j = 3; j--;){
			if(m[1][j] < m[1][j + 1]) swap(m[1][j], m[1][j + 1]);
		}
	}
	dp[v][1] = max(dp[v][1], a[v] + m[0][0] + m[0][1]);
	ans = max(ans, m[1][0] + m[1][1]);
	for(ll i = 0; i < Sz(g[v]); i++){
		ll u = g[v][i];
		if(u == par[v]) continue;
		if(dp[u][0] == m[0][0]){
			dp[v][2] = max(dp[v][2], dp[u][1] + a[v] + m[0][1]);
			ans = max(ans, dp[u][1] + m[0][1] + m[0][2] + a[v]);
			ans = max(ans, dp[u][2] + m[0][1] + a[v]);
		}
		else if(dp[u][0] == m[0][1]){
			dp[v][2] = max(dp[v][2], dp[u][1] + a[v] + m[0][0]);
			ans = max(ans, dp[u][1] + m[0][0] + m[0][2] + a[v]);
			ans = max(ans, dp[u][2] + m[0][0] + a[v]);
		}
		else{
			dp[v][2] = max(dp[v][2], dp[u][1] + a[v] + m[0][0]);
			ans = max(ans, dp[u][1] + m[0][0] + m[0][1] + a[v]);
			ans = max(ans, dp[u][2] + m[0][0] + a[v]);
		}
	}
	return;
}

int main(){
    fast_io;
 
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	cout << ans;
 
    return 0;
}