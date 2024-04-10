#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, ans, a[MAXN], x, dp[MAXN][4];

int main(){
	fast_io;
	
	cin >> n >> x;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j < 4; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
			if(j % 2){
				dp[i][j] += a[i];
			}
			else{
				dp[i][j] += a[i] * x;
			}
			dp[i][j] = max(0ll, dp[i][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
	
	return 0;
}