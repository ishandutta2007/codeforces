//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 998244353;
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

ll n, dp[maxn][3], par[maxn], ps[maxn];
vector<ll> g[maxn];

void dfs(ll v){
	dp[v][2] = dp[v][1] = 1;
	vector<pll> vec;
	for(ll u : g[v]){
		if(u == par[v]) continue;
		par[u] = v;
		dfs(u);
		dp[v][1] = (dp[v][1] * (dp[u][0] * 2 + dp[u][2])) % mod;
		dp[v][2] = (dp[v][2] * (dp[u][0] + dp[u][2])) % mod;
		vec.pb(Mp((dp[u][0] * 2 + dp[u][2]) % mod, dp[u][1]));
	}
	ps[Sz(vec)] = 1;
	for(ll i = Sz(vec); i--;){
		ps[i] = ps[i + 1] * vec[i].F % mod;
	}
	ll s = 1;
	for(ll i = 0; i < Sz(vec); i++){
		dp[v][0] = (dp[v][0] + s * vec[i].S % mod * ps[i + 1]) % mod;
		s = s * vec[i].F % mod;
	}
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][2]) % mod;
 
    return 0;
}