#include <cstdio>
#include <algorithm>

typedef long long i64;

int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 2 < k) return puts("-1"), 0;
  i64 ans = 0;
  for (int i = 1; i <= n && i <= k + 1;) {
    int j = std::min(n / (n / i), k + 1);
    ans = std::max(ans, (i64)(n / i) * (m / (k - (j - 1) + 1)));
    i = j + 1;
  }
  printf("%lld\n", ans);
  return 0;
}