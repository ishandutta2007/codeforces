#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[205][205][205];

void umax(int&a, int b) {
  a = max(a, b);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  a += " ";
  if (b[0] == b[1]) {
    int got = min((int)count(a.begin(), a.end(), b[0])+m, n);
    cout << got*(got-1)/2 << endl;
    return 0;
  }
  int ans = 0;
  fill_n((int*)dp, sizeof(dp)/sizeof(int), -(int)1e9);
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= m; k++) {
	// dp[i][j][k] = most subsequences in :i with j times b[0] and k used

	// bad character
	umax(dp[i+1][j][k], dp[i][j][k]);

	//b[0]
	umax(dp[i+1][j+1][k+(a[i]!=b[0])], dp[i][j][k]);

	//b[1]
	umax(dp[i+1][j][k+(a[i]!=b[1])], dp[i][j][k]+j);
	if (i == n) umax(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}