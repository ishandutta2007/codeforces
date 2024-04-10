//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, dp[2][maxn];

int main(){
	fast_io;
	
	dp[0][1] = dp[1][1] = dp[0][2] = dp[1][2] = 0;
	for(ll i = 3; i < maxn; i++){
		dp[0][i] = (((i - 1) % 3 == 2 ? dp[0][i - 1] : dp[1][i - 1]) + ((i - 2) % 3 == 2 ? dp[0][i - 2] : dp[1][i - 2]) * 2) % mod;
		dp[1][i] = (dp[0][i - 1] + dp[0][i - 2] * 2 + 4) % mod;
	}
	cin >> t;
	while(t--){
		cin >> n;
		if(n % 3 == 0) cout << dp[1][n] << '\n';
		else cout << dp[0][n] << '\n';
	}
	
	return 0;
}