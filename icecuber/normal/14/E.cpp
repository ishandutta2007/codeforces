#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[30][30][4];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t;
  cin >> n >> t;
  //dp[i][j][k] = number of camels of length i with j zigzags, ending in k
  //First direction is always upwards
  for (int k = 0; k < 4; k++)
    dp[0][0][k] = 1;
  for (int k = 0; k < 4; k++)
    dp[1][0][k] = k;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 4; k++) {
	//if (j <= 2)
	//  cout << i << ' ' << j << ' ' << k << ": " << dp[i][j][k] << endl;
	for (int l = 0; l < 4; l++) {
	  if (k == l) continue;
	  if ((l < k) != j%2)
	    dp[i+1][j+1][l] += dp[i][j][k];
	  else
	    dp[i+1][j][l] += dp[i][j][k];
	}
      }
    }
  }
  ll ans = 0;
  for (int k = 0; k < 4; k++) ans += dp[n-1][t*2-1][k];
  cout << ans << endl;
}