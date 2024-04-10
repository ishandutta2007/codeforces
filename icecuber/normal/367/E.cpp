#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  x--;
  if (n > m) {
    cout << 0 << endl;
    return 0;
  }
  //dp[i][j][k] = number of ways, up to i, with j open intervals, k closed intervals
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    vector<vector<ll>> ndp(n+1,vector<ll>(n+1,0));
    for (int j = 0; j <= n; j++)
      for (int k = 0; j+k <= n; k++) {
	//Do nothing
	if (i != x)
	  (ndp[j][k] += dp[j][k]) %= mod;
	//Open
	if (j+k+1 <= n)
	  (ndp[j+1][k] += dp[j][k]) %= mod;
	//Close
	if (i != x && j)
	  (ndp[j-1][k+1] += dp[j][k]) %= mod;
	//Open and close
	if (j+k+1 <= n)
	  (ndp[j][k+1] += dp[j][k]) %= mod;
      }
    swap(dp,ndp);
  }
  ll ans = dp[0][n];
  for (int i = 1; i <= n; i++)
    (ans *= i) %= mod;
  cout << ans << endl;
}