#include <cstdio>
#include <algorithm>

const int N = 100000 + 10, S = 20;

int n, h[N];

struct RMQ {
  int table[S][N];
  void init() {
    for (int i = 1; i < S; ++i)
      for (int j = 1; j + (1 << (i - 1)) <= n; ++j)
        table[i][j] = std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
  }
  int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return std::min(table[k][l], table[k][r - (1 << k) + 1]);
  }
} pre, suf;

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n + 1; ++i) scanf("%d", &h[i]);
  n += 2;
  for (int i = 1; i <= n; ++i) pre.table[0][i] = h[i] - i, suf.table[0][i] = h[i] + i;
  pre.init(), suf.init();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = std::min(i, n - i);
    while (l < r) {
      int mid = (l + r) / 2;
      int t = std::min(suf.query(i, i + mid) - mid - i, pre.query(i - mid, i) - mid + i);
      if (t <= 0) r = mid; else l = mid + 1;
    }
    ans = std::max(ans, l);
  }
  printf("%d\n", ans);
  return 0;
}