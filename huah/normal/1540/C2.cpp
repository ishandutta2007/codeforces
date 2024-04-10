#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 105, mod = 1e9 + 7;
int n, q, c[N], b[N];
// map<pair<int, int>, int> vis;
// int sol(int pos, int x, int y) {
//   if (pos == n + 1) return 1;
//   if (vis.count(mp(pos, x))) return vis[mp(pos, x)];
//   int ans = 0;
//   for (int i = max(0, x + b[pos]); i <= c[pos]; i++)
//     ans = (ans + sol(pos + 1, y - (i - (x + b[pos])), y)) % mod;
//   return vis[mp(pos, x)] = ans;
// }
int dp[N][N * N];
map<int, int> ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 2; i <= n; i++) scanf("%d", &b[i]), b[i] = b[i] + b[i - 1];
  for (int i = 2; i <= n; i++) b[i] += b[i - 1];
  scanf("%d", &q);
  int mn = 0;
  for (int i = 1; i <= n; i++) mn = min(mn, -b[i] / i);
  int mx = mn + 105;
  mn -= 5;
  while (q--) {
    int x;
    scanf("%d", &x);
    x = min(mx, max(mn, x));
    if (ans.count(x))
      printf("%d\n", ans[x]);
    else {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;
      int sc = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 1; j <= sc; j++)
          dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        for (int j = max(0, i * x + b[i]); j <= sc; j++) {
          dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
          if (j + c[i + 1] + 1 <= sc + c[i + 1])
            dp[i + 1][j + c[i + 1] + 1] =
                (dp[i + 1][j + c[i + 1] + 1] + mod - dp[i][j]) % mod;
        }
        sc += c[i + 1];
      }
      int res = 0;
      for (int j = 1; j <= sc; j++) dp[n][j] = (dp[n][j] + dp[n][j - 1]) % mod;
      for (int j = max(0, n * x + b[n]); j <= sc; j++)
        res = (res + dp[n][j]) % mod;
      printf("%d\n", ans[x] = res);
    }
  }
}