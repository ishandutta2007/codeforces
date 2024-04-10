//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn];

ld dp[maxn][maxn], ans;

int main(){
	ll v, u;
	fast_io;
	
	cout << setprecision(15) << fixed;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		for(ll j = 1; j < i; j++){
			if(a[i] > a[j]) dp[i][j] = 1;
			else dp[j][i] = 1;
		}
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		for(ll j = 1; j <= n; j++){
			if(j == v || j == u) continue;
			dp[v][j] = dp[u][j] = (dp[v][j] + dp[u][j]) / 2;
			dp[j][v] = dp[j][u] = (dp[j][v] + dp[j][u]) / 2;
		}
		dp[v][u] = dp[u][v] = (dp[v][u] + dp[u][v]) / 2;
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j < i; j++){
			ans += dp[j][i];
		}
	}
	
	cout << ans;
	
	return 0;
}