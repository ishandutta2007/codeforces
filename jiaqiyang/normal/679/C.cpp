#include <cstdio>
#include <algorithm>

const int N = 500 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, k;
char s[N][N];

int a[N][N], sum[N][N], size[N * N], cnt[N * N], tot;

void dfs(int x, int y) {
  if (a[x][y]) return;
  if (!(1 <= x && x <= n && 1 <= y && y <= n)) return;
  if (s[x][y] == 'X') return;
  ++size[a[x][y] = tot];
  for (int k = 0; k < 4; ++k) dfs(x + dx[k], y + dy[k]);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf(" %s", s[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!a[i][j] && s[i][j] == '.') ++tot, dfs(i, j);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == 'X');
  int ans = 0;
  for (int i = 1; i + k - 1 <= n; ++i) {
    int cur = 0;
    for (int j = 1; j <= tot; ++j) cnt[j] = 0;
    const int u = i, d = i + k - 1;
    int l = 1, r = k;
    for (int x = u; x <= d; ++x)
      for (int y = l; y <= r + 1; ++y)
        ++cnt[a[x][y]];
    for (int y = l; y <= r; ++y) ++cnt[a[u - 1][y]], ++cnt[a[d + 1][y]];
    for (int j = 1; j <= tot; ++j) if (cnt[j]) cur += size[j];
      ans = std::max(ans, sum[d][r] - sum[d][l - 1] - sum[u - 1][r] + sum[u - 1][l - 1] + cur);
    while (++r <= n) {
      for (int j = u; j <= d; ++j) if (--cnt[a[j][l - 1]] == 0) cur -= size[a[j][l - 1]];
      for (int j = u; j <= d; ++j) if (cnt[a[j][r + 1]]++ == 0) cur += size[a[j][r + 1]];
      if (--cnt[a[u - 1][l]] == 0) cur -= size[a[u - 1][l]];
      if (--cnt[a[d + 1][l]] == 0) cur -= size[a[d + 1][l]];
      ++l;
      if (cnt[a[u - 1][r]]++ == 0) cur += size[a[u - 1][r]];
      if (cnt[a[d + 1][r]]++ == 0) cur += size[a[d + 1][r]];
      ans = std::max(ans, sum[d][r] - sum[d][l - 1] - sum[u - 1][r] + sum[u - 1][l - 1] + cur);
    }
  }
  printf("%d\n", ans);
  return 0;
}