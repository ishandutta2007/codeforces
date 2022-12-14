#include <stdio.h>
#include <algorithm>

const int N = 200000 + 10, INF = 100000000;

int n, c[N], d[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &c[i], &d[i]);
  int l = -INF, r = INF;
  for (int i = n; i > 0; --i) {
    l -= c[i], r -= c[i];
    if (d[i] == 1) l = std::max(l, 1900); else r = std::min(r, 1899);
    if (l > r) {
      puts("Impossible");
      return 0;
    }
  }
  if (r > 30000000) {
    puts("Infinity");
  } else {
    for (int i = 1; i <= n; ++i) r += c[i];
    printf("%d\n", r);
  }
  return 0;
}