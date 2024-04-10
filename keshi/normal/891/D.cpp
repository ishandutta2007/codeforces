//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, sz[maxn], cnt;
pii dp[maxn], pd[maxn];
ll ans;
vector<int> g[maxn];

void dfs(int v, int p = -1){
	sz[v] = 1;
	dp[v] = Mp(0, 1);
	for(int u : g[v]){
		if(u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
		int x = dp[u].F;
		if(sz[u] & 1) x--;
		else x++;
		if(dp[v].F > x){
			dp[v] = Mp(x, 0);
		}
		if(dp[v].F == x) dp[v].S += dp[u].S;
	}
	if(sz[v] & 1) cnt++;
	return;
}

void solve(int v, int p = -1){
	map<int, int> mp;
	mp[pd[v].F] += pd[v].S;
	for(int u : g[v]){
		if(u == p) continue;
		int x = dp[u].F;
		if(sz[u] & 1) x--;
		else x++;
		mp[x] += dp[u].S;
	}
	pii fa = *mp.begin(), fb = Mp(n + 10, 0);
	if(Sz(mp) > 1){
		auto it = mp.begin();
		it++;
		fb = *it;
	}
	for(int u : g[v]){
		if(u == p) continue;
		int x = dp[u].F;
		if(sz[u] & 1) x--;
		else x++;
		pii y;
		if(x == fa.F){
			if(dp[u].S == fa.S){
				y = fb;
			}
			else y = Mp(fa.F, fa.S - dp[u].S);
		}
		else y = fa;
		if(sz[u] % 2 == 0){
			if(cnt == n / 2) ans += 1ll * sz[u] * (n - sz[u]);
		}
		else if(y.F + dp[u].F + cnt == n / 2) ans += 1ll * y.S * dp[u].S;
		if(sz[u] & 1) y.F--;
		else y.F++;
		if(y.F > 0){
			y = Mp(0, 0);
		}
		if(y.F == 0) y.S++;
		pd[u] = y;
		solve(u, v);
	}
	return;
}


int main(){
	fast_io;
	
	cin >> n;
	if(n & 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	pd[1] = Mp(0, 1);
	solve(1);
	cout << ans;
	
	return 0;
}