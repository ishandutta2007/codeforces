#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
const int maxn = 505;
int a[maxn];
int dp[2][maxn][maxn];
int tmp[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  fill(dp[0][0], dp[1][0], -inf);
  dp[0][0][0] = 0;
  bool b = false;
  for (int i = 1; i <= n; i++) {
    fill(dp[!b][0], dp[!b + 1][0], -inf);
    for (int j = 0; j < n; j++)
      for (int k = 1; k <= i; k++) dp[!b][j][k] = dp[b][j][k - 1] + a[j];
    fill(tmp, tmp + maxn, -inf);
    for (int j = 1; j < n; j++)
      for (int k = 0; k <= i; k++)
        dp[b][j][k] = max(dp[b][j][k], dp[b][j - 1][k]);
    for (int j = i - 1; j < n; j++)
      for (int k = 0; k <= i; k++) {
        int t = k - j + i - 1;
        if (t >= 0) dp[!b][j][k] = max(dp[!b][j][k], (j?dp[b][j - 1][t]:0) + a[j]);
      }
    b = !b;
  }
  int ans = -inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++) ans = max(ans, dp[b][i][j]);
  printf("%d\n", ans);
  return 0;
}