#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 1e9+7;
int dp[1001][1001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  dp[0][0] = 1;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if ((i+j)%2==1)
	(ans += dp[i][j]) %= mod;
      if (i < n)
	(dp[i+1][j] += dp[i][j]) %= mod;
      if (j < n && j < i)
	(dp[i][j+1] += dp[i][j]) %= mod;
      //cout << dp[i][j] << ' ';
    }
    //cout << endl;
  }
  cout << ans << endl;
}