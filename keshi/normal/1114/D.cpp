//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans, a[maxn], dp[2][maxn][maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll t = n - 2; t >= 0; t--){
		for(ll l = 1; l + t <= n; l++){
			ll r = l + t;
			dp[0][l][r] = inf;
			if(l > 1) dp[0][l][r] = min(dp[0][l][r], dp[0][l - 1][r] + (a[l] != a[l - 1]));
			if(r < n) dp[0][l][r] = min(dp[0][l][r], dp[1][l][r + 1] + (a[l] != a[r + 1]));
			dp[1][l][r] = inf;
			if(l > 1) dp[1][l][r] = min(dp[1][l][r], dp[0][l - 1][r] + (a[r] != a[l - 1]));
			if(r < n) dp[1][l][r] = min(dp[1][l][r], dp[1][l][r + 1] + (a[r] != a[r + 1]));
		}
	}
	
	ans = inf;
	
	for(ll i = 1; i <= n; i++){
		ans = min(ans, dp[0][i][i]);
	}
	
	cout << ans;
	
	return 0;
}