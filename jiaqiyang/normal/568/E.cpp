#include <cstdio>
#include <cstring>
#include <cassert>
#include <set>
#include <algorithm>

const int N = 100000 + 10, INF = 0x3f3f3f3f;

inline bool check(int &lhs, int rhs) { return rhs < lhs ? (lhs = rhs, true) : false; }

int n, m, a[N], b[N];

int main() {
  scanf("%d", &n);
  a[0] = -INF;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  a[n + 1] = INF;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
  std::multiset<int> pool(b + 1, b + m + 1);
  std::sort(b + 1, b + m + 1);
  m = std::unique(b + 1, b + m + 1) - b - 1;
  static int f[N], g[N], pre[N], lis[N];
  memset(f, 0x3f, sizeof f);
  f[0] = -INF, g[0] = 0;
  int tot = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (a[i] == -1) {
      for (int j = m, k = tot; j > 0; --j) {
        while (k && f[k] >= b[j]) --k;
        if (check(f[k + 1], b[j])) g[k + 1] = -1;
      }
    } else {
      int j = std::lower_bound(f, f + tot + 1, a[i]) - f;
      lis[i] = j;
      pre[i] = g[j - 1];
      if (check(f[j], a[i])) g[j] = i;
    }
    if (f[tot + 1] != INF) ++tot;
  }
  static int ans[N], sum[N];
  for (int i = 1; i <= n + 1; ++i) sum[i] = sum[i - 1] + (a[i] == -1);
  for (int i = 0; i <= n + 1; ++i) ans[i] = a[i];
  for (int i = n + 1; i;) {
    if (pre[i] == -1) {
      for (int j = i - 1; j >= 0; --j) {
        if (a[j] == -1 || lis[j] >= lis[i] || a[j] >= a[i]) continue;
        int p = sum[i] - sum[j];
        int l = std::upper_bound(b + 1, b + m + 1, a[j]) - b;
        int r = std::lower_bound(b + 1, b + m + 1, a[i]) - b;
        if (lis[i] - lis[j] - 1 <= std::min(p, r - l)) {
          for (int t = lis[i] - lis[j] - 1, k = j; t--;) {
            while (a[k] != -1) ++k;
            pool.erase(pool.find(ans[k++] = b[l++]));
          }
          i = j;
          break;
        }
      }
    } else {
      i = pre[i];
    }
  }
  for (int i = 1; i <= n; ++i) if (ans[i] == -1) ans[i] = *pool.begin(), pool.erase(pool.begin());
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}