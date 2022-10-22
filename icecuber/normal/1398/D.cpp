#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[210][210][210];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<vector<int>> a(3);
  int n[3];
  cin >> n[0] >> n[1] >> n[2];
  for (int i = 0; i < 3; i++) {
    a[i].resize(n[i]);
    for (int&v : a[i]) cin >> v;
    sort(a[i].begin(), a[i].end());
  }
  for (int i = 0; i <= n[0]; i++) {
    for (int j = 0; j <= n[1]; j++) {
      for (int k = 0; k <= n[2]; k++) {
	if (i) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
	if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
	if (k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
	for (int l = 0; l < 3; l++) {
	  int ni = i+(l!=0);
	  int nj = j+(l!=1);
	  int nk = k+(l!=2);
	  if (ni > n[0] || nj > n[1] || nk > n[2]) continue;
	  ll prod = 1;
	  if (l != 0) prod *= a[0][i];
	  if (l != 1) prod *= a[1][j];
	  if (l != 2) prod *= a[2][k];
	  dp[ni][nj][nk] = max(dp[ni][nj][nk], dp[i][j][k]+prod);
	}
      }
    }
  }
  cout << dp[n[0]][n[1]][n[2]] << endl;
}