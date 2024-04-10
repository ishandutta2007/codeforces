#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, a[MAXN], dp[2][MAXN];
string s[MAXN], d[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		dp[0][i] = INF;
		dp[1][i] = INF;
		cin >> s[i];
		for(ll j = s[i].size() - 1; j > -1; j--){
			d[i] += s[i][j];
		}
	}
	
	dp[0][0] = 0;
	dp[1][0] = a[0];
	
	for(ll i = 1; i < n; i++){
		if(s[i] >= s[i - 1]){
			dp[0][i] = min(dp[0][i], dp[0][i - 1]);
		}
		if(s[i] >= d[i - 1]){
			dp[0][i] = min(dp[0][i], dp[1][i - 1]);
		}
		if(d[i] >= s[i - 1]){
			dp[1][i] = min(dp[1][i], dp[0][i - 1] + a[i]);
		}
		if(d[i] >= d[i - 1]){
			dp[1][i] = min(dp[1][i], dp[1][i - 1] + a[i]);
		}
	}
	
	if(min(dp[0][n - 1], dp[1][n - 1]) == INF){
		cout << -1;
		return 0;
	}
	
	cout << min(dp[0][n - 1], dp[1][n - 1]);
	
	return 0;
}