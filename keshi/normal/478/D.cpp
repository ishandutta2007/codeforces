#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const int MAMX = 900;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll r, g, h, dp[MAXN][2], ans;

int main(){
	fast_io;
	
	cin >> r >> g;
	h = 1;
	while((h + 1) * (h + 2) / 2 <= r + g){
		h++;
	}
	
	for(ll j = 1; j <= h; j++){
		for(ll i = 1; i <= r; i++){
			dp[i][j % 2] = dp[i][(j - 1) % 2];
			if(i - j > 0){
				dp[i][j % 2] += dp[i - j][(j - 1) % 2];
			}
			if(i == j){
				dp[i][j % 2]++;
			}
			dp[i][j % 2] %= MOD;
		}
	}
	
	for(ll i = 0; i <= r; i++){
		if(h * (h + 1) / 2 - i <= g){
			if(i == 0){
				ans++;
			}
			ans = (ans + dp[i][h % 2]) % MOD;
		}
	}
	
	cout << ans;
	
	return 0;
}