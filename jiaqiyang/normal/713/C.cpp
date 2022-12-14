#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef long long i64;

const int N = 3000 + 10;

int n, a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] -= i, b[i] = a[i];
  std::sort(b + 1, b + n + 1);
  static i64 ans[N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans[j] += abs(a[i] - b[j]);
      if (j > 1) ans[j] = std::min(ans[j], ans[j - 1]);
    }
  }
  printf("%lld\n", ans[n]);
  return 0;
}