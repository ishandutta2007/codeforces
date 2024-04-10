#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int dp[2][maxn][2][2], vis[2][maxn][2][2];
char s[2][maxn];
int n;
int dfs(bool x, int y, int b0, int b1) {
  if (vis[x][y][b0][b1]) return dp[x][y][b0][b1];
  vis[x][y][b0][b1] = true;
  if (y == n - 1) return dp[x][y][b0][b1] = 0;
  int b[2] = {b0, b1}, nx[2] = {s[0][y + 1] - '0', s[1][y + 1] - '0'};
  if (b[x]) {
    b[x] = 0;
    return dp[x][y][b0][b1] = dfs(x, y, b[0], b[1]);
  }
  if (!b[!x]) return dp[x][y][b0][b1] = dfs(x, y + 1, nx[0], nx[1]);
  if (!nx[x]) {
    int tmp = dfs(!x, y + 1, nx[0], nx[1]);
    tmp = min(tmp, dfs(x, y + 1, nx[0], nx[1]) + 1);
    return dp[x][y][b0][b1] = tmp;
  }
  int tmp = dfs(x, y + 1, nx[0], nx[1]) + 1;
  nx[x] = 0;
  tmp = min(tmp, dfs(!x, y + 1, nx[0], nx[1]) + 1);
  return dp[x][y][b0][b1] = tmp;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  int ans = -dfs(0, 0, s[0][0] - '0', s[1][0] - '0');
  for (int i = 0; i < n; i++) ans += s[0][i] - '0' + s[1][i] - '0';
  printf("%d\n", ans);
  return 0;
}