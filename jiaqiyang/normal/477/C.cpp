#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 2000 + 10, INF = 0x3f3f3f3f;

inline void check(int &lhs, int rhs) { if (rhs < lhs) lhs = rhs; }

int n, m;
char s[N], p[N];

int f[N][N];

int main() {
  scanf(" %s %s", s, p);
  n = strlen(s);
  m = strlen(p);
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int cur = f[i][j];
      if (cur == INF) continue;
      if (s[i] == p[j % m]) //{
        check(f[i + 1][j + 1], cur);
      //        check(f[i + 1][j], cur);
        //      } else {
        check(f[i + 1][j], cur + (j % m > 0));
        //      }
    }
  }
  static int ans[N];
  for (int i = 0; i <= n; ++i) {
    if (f[n][i] < INF) {
      int l = f[n][i], r = n - i;
      for (int j = l; j <= r; ++j) ans[j] = std::max(ans[j], i / m);
    }
  }
  for (int i = 0; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}