#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

int n, a[N];
i64 sum[N];

inline double calc(int c, int d) {
  return (sum[n] - sum[n - d] + sum[c] - sum[c - d - 1]) / (2. * d + 1.) - a[c];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  double ans = 0.;
  int x = 1, y = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = std::min(n - i, i - 1);
    while (r - l > 10) {
      int p = l + (r - l) / 3, q = p + (r - l) / 3;
      double u = calc(i, p), v = calc(i, q);
      if (u > v) r = q; else l = p;
    }
    for (int j = l; j <= r; ++j) if (calc(i, j) > ans) ans = calc(i, j), x = i, y = j;
  }
  printf("%d\n%d", 2 * y + 1, a[x]);
  for (int i = 1; i <= y; ++i) printf(" %d", a[x - i]);
  for (int i = 0; i < y; ++i) printf(" %d", a[n - i]);
  puts("");
  return 0;
}