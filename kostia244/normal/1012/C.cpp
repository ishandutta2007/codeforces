#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#pragma GCC comment("/STACK:26666666")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
ll n, a[5050], dp[5050][2750][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(a, -20, sizeof a);
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, 30, sizeof dp);
	dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= (n+1)/ 2; j++) {
			for(int k = 0; k < 2; k++) {
				dp[i+2][j][0] = min(dp[i+2][j][0], dp[i][j][k]);
				dp[i+3][j][0] = min(dp[i+3][j][0], dp[i][j][k]);
			}
			dp[i+2][j+1][1] = min(dp[i+2][j+1][1], dp[i][j][0] + max(0ll, a[i-1]-a[i]+1) + max(0ll, a[i+1]-a[i]+1));
			dp[i+2][j+1][1] = min(dp[i+2][j+1][1], dp[i][j][1] + max(0ll, min(a[i-1], a[i-2]-1)-a[i]+1) + max(0ll, a[i+1]-a[i]+1));
			dp[i+3][j+1][0] = min(dp[i+3][j+1][0], dp[i][j][0] + max(0ll, a[i-1]-a[i]+1) + max(0ll, a[i+1]-a[i]+1));
			dp[i+3][j+1][0] = min(dp[i+3][j+1][0], dp[i][j][1] + max(0ll, min(a[i-1], a[i-2]-1)-a[i]+1) + max(0ll, a[i+1]-a[i]+1));
		}
	}
	for(int i = 1; i <= (n+1)/2; i++) cout << min({dp[n][i][0], dp[n][i][1], dp[n+1][i][0], dp[n+1][i][1],dp[n+2][i][0], dp[n+2][i][1]}) << " ";
}