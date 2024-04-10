#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, deg[MAXN], dp[MAXN], ans;

vector<ll> g[MAXN];

int main(){
	fast_io;
	ll u, v;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		g[max(u, v)].pb(min(u, v));
		deg[v]++;
		deg[u]++;
	}
	
	for(ll i = 1; i <= n; i++){
		v = 0;
		for(ll j = 0; j < g[i].size(); j++){
			v = max(v, dp[g[i][j]]);
		}
		dp[i] = v + 1;
	}
	
	for(ll i = 1; i <= n; i++){
		ans = max(ans, deg[i] * dp[i]);
	}
	
	cout << ans;
	
	return 0;
}