#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, ans, a[MAXN], dp[3][MAXN], l, r;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= k; i++){
		dp[0][1] += a[i];
	}
	
	for(ll i = 2; i <= n - k + 1; i++){
		dp[0][i] = dp[0][i - 1] - a[i - 1] + a[i + k - 1];
	}
	
	for(ll i = 1; i <= n - k + 1; i++){
		if(dp[0][dp[1][i - 1]] < dp[0][i]){
			dp[1][i] = i;
		}
		else{
			dp[1][i] = dp[1][i - 1];
		}
	}
	
	l = 1;
	r = k + 1;
	
	for(ll i = k + 1; i <= n - k + 1; i++){
		if(dp[0][l] + dp[0][r] < dp[0][i] + dp[0][dp[1][i - k]]){
			l = dp[1][i - k];
			r = i;
		}
	}
	
	cout << l << " " << r;
	
	return 0;
}