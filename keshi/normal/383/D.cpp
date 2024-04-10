#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
const int MAXM = 2e4 + 100;
const int MOD = 1e9 + 7;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

int n, a[MAXN], b[MAXN], dp[MAXN][MAXM], ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	dp[0][a[0] + 10000] = 1;
	dp[0][10000 - a[0]] = 1;
	
	for(ll i = 1; i < n; i++){
		dp[i][a[i] + 10000]++;
		dp[i][10000 - a[i]]++;
		for(ll j = -10000; j <= 10000; j++){
			if(0 <= j + a[i] + 10000 && j + a[i] + 10000 <= 20000){
				dp[i][j + 10000] += dp[i - 1][j + a[i] + 10000];
				dp[i][j + 10000] %= MOD;
			}
			if(0 <= j - a[i] + 10000 && j - a[i] + 10000 <= 20000){
				dp[i][j + 10000] += dp[i - 1][j - a[i] + 10000];
				dp[i][j + 10000] %= MOD;
			}
		}
	}
	
	ans = 0;
	
	for(int i = 0; i < n; i++){
		ans += dp[i][10000];
		ans %= MOD;
	}
	
	cout << ans;
	
	return 0;
}