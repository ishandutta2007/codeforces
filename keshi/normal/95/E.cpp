//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, cnt[maxn], dp[maxn], ans;

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	t++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	return;
}

bool lucky(ll x){
	ll y = x;
	while(x){
		if(x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}


int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		t = 0;
		dfs(i);
		cnt[t]++;
	}
	
	fill(dp + 1, dp + maxn, inf);
	
	for(ll i = 1; i <= n; i++){
		t = 1;
		while(cnt[i]){
			ll x = min(t, cnt[i]);
			for(ll j = maxn - 1; j >= x * i; j--){
				dp[j] = min(dp[j], dp[j - x * i] + x);
			}
			cnt[i] -= x;
			t *= 2;
		}
	}
	
	ans = inf;
	
	for(ll i = 1; i < maxn; i++){
		if(lucky(i)) ans = min(ans, dp[i]);
	}
	if(ans == inf) ans = 0;
	
	cout << ans - 1;
	
	return 0;
}