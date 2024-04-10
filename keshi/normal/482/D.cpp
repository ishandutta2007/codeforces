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

int n, p[maxn];
ll dp[maxn][2];
vector<int> g[maxn];

void dfs(int v){
	dp[v][1] = 1;
	ll zj, od[2];
	zj = 1;
	od[0] = 1;
	od[1] = 0;
	for(int u : g[v]){
		dfs(u);
		ll x = (dp[v][0] * (dp[u][0] + 1) + dp[v][1] * dp[u][1]) % mod;
		dp[v][1] = (dp[v][0] * dp[u][1] + dp[v][1] * (dp[u][0] + 1)) % mod;
		dp[v][0] = x;
		zj = zj * (dp[u][0] + 1) % mod;
		x = (od[0] + od[1] * dp[u][1]) % mod;
		od[1] = (od[1] + od[0] * dp[u][1]) % mod;
		od[0] = x;
	}
	dp[v][1] = (dp[v][1] * 2 - zj) % mod;
	dp[v][0] = (dp[v][0] * 2 - od[1]) % mod;
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> p[i];
		g[p[i]].pb(i);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][1] + mod + mod) % mod;
	
	return 0;
}