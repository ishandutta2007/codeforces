//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll n, h[maxn];
ll dp[maxn], mx[maxn], pd[maxn], xm[maxn], dd[maxn];
vector<int> g[maxn];

void dfs(int v, int p = -1){
	mx[v] = dp[v] = 0;
	for(int u : g[v]){
		if(u == p) continue;
		dfs(u, v);
		mx[v] = max(mx[v], mx[u]);
		dp[v] += dp[u];
	}
	dd[v] = dp[v];
	dp[v] += max(mx[v], h[v]) - mx[v];
	mx[v] = max(mx[v], h[v]);
	return;
}
void sfd(int v, int p = -1){
	ll s = pd[v];
	vector<pll> vec;
	vec.pb(Mp(xm[v], v));
	for(int u : g[v]){
		if(u == p) continue;
		s += dp[u];
		vec.pb(Mp(mx[u], u));
	}
	sort(all(vec), greater<pll>());
	for(int u : g[v]){
		if(u == p) continue;
		pd[u] = s - dp[u];
		if(vec[0].S == u) xm[u] = vec[1].F;
		else xm[u] = vec[0].F;
		pd[u] += max(xm[u], h[v]) - xm[u];
		xm[u] = max(h[v], xm[u]);
	}
	for(int u : g[v]){
		if(u == p) continue;
		sfd(u, v);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	sfd(1);
	ll cn = 0, vv = 0;
	for(int i = 1; i <= n; i++){
		if(h[i] == mx[1]) cn++, vv = i;
	}
	ll ans = inf;
	for(int i = 1; i <= n; i++){
		if(cn != 1 || vv != i) ans = min(ans, dd[i] + mx[1] + pd[i]);
	}
	cout << ans << "\n";
	
	return 0;
}