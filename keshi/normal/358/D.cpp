#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], c[maxn], dp[maxn][4];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> c[i];
	}
	
	dp[0][0] = a[0];
	dp[0][1] = -inf;
	dp[0][2] = b[0];
	dp[0][3] = -inf;
	
	for(ll i = 1; i < n; i++){
		dp[i][0] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]) + b[i];
		dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
	}
	
	cout << max(dp[n - 1][0], dp[n - 1][1]);
	
	return 0;
}