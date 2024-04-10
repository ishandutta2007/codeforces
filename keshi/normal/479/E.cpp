#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 100;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b, k, dp[MAXN][2], ptr, ans, s;

int main(){
	fast_io;
	
	cin >> n >> a >> b >> k;
	
	if(a > b){
		a = n + 1 - a;
		b = n + 1 - b;
	}
	
	dp[a][0] = 1;
	
	for(ll j = 1; j <= k; j++){
		ptr = 1;
		s = 0;
		for(ll i = 1; i < b; i++){
			while(ptr < b && abs(ptr - i) < abs(ptr - b)){
				s += dp[ptr++][(j - 1) % 2];
				s %= MOD;
			}
			dp[i][j % 2] = (s - dp[i][(j - 1) % 2] + MOD) % MOD;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		ans = (ans + dp[i][k % 2]) % MOD;
	}
	
	cout << ans;
	
	return 0;
}