#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, f[300][300], a[300];

inline int get(int x, int y) {
  return x == y || !(a[x] & a[y]) ? 1 << 30 : 1;
}

signed main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%I64d", &x);
    if (x) a[++m] = x;
    if (m > 3 * 64) {
      return puts("3"), 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = get(i, j);
    }
  }
  int ans = 1 << 30;
  for (int k = 1; k <= m; k++) {
    for (int i = 1; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        ans = min(ans, f[i][j] + get(i, k) + get(k, j));
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  printf("%I64d", ans > 1e9 ? -1 : ans);
  return 0;
}