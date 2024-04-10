#include <cstdio>
#include <cinttypes>
#include <numeric>
#include <algorithm>

const int N = 300000 + 10;

int32_t n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  std::sort(a + 1, a + n + 1);
  int64_t ans = 0;
  for (int i = 1; i < n; ++i) ans += (int64_t)a[i] * (i + 1);
  ans += (int64_t)a[n] * n;
  printf("%" PRId64 "\n", ans);
  return 0;
}