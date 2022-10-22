#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[36][36];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h;
  cin >> n >> h;
  //dp[i][j] = number of trees with i nodes with depth at most j
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = i ? 0 : 1;
      if (j)
	for (int k = 0; k < i; k++)
	  dp[i][j] += dp[k][j-1]*dp[i-k-1][j-1];
    }
  }
  cout << dp[n][n]-dp[n][h-1] << endl;
}