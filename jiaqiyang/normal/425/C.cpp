#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, K = 300 + 10;

int n, m, s, e, a[N], b[N];

int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  static std::vector<int> pos[N];
  for (int i = 1; i <= m; ++i) scanf("%d", b + i), pos[b[i]].push_back(i);
  static int f[K][N];
  memset(f, 0x3f, sizeof f);
  memset(f[0], 0, sizeof f[0]);
  int ans = 0;
  for (int i = 1; i < K; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = f[i][j - 1];
      std::vector<int>::iterator it = std::upper_bound(pos[a[j]].begin(), pos[a[j]].end(), f[i - 1][j - 1]);
      if (it != pos[a[j]].end()) f[i][j] = std::min(f[i][j], *it);
      if (i * e + j + f[i][j] <= s) ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}