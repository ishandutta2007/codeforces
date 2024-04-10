#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], ps[maxn], ans, dp[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		for(ll r = i; r <= n; r++){
			dp[i][r] = inf;
		}
		ps[i] = ps[i - 1] + a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		dp[1][i] = i - 1;
	}
	
	for(ll r = 1; r <= n; r++){
		ll l = r;
		ans = inf;
		for(ll x = r + 1; x <= n; x++){
			while(l - 1 >= 0 && ps[r] - ps[l - 1] <= ps[x] - ps[r]){
				ans = min(ans, dp[l][r]);
				l--;
			}
			dp[r + 1][x] = min(dp[r + 1][x], ans + x - r - 1);
		}
	}
	
	ans = inf;
	
	for(ll i = 1; i <= n; i++){
		ans = min(ans, dp[i][n]);
	}
	
	cout << ans;
	
	return 0;
}