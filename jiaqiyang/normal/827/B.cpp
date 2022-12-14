#include <cstdio>

const int N = 200000 + 10;

int n, k;

int main() {
  scanf("%d%d", &n, &k);
  int m = n - k - 1;
  int ans = 2 * (m / k + 1);
  if (m % k) ++ans;
  if (m % k > 1) ++ans;
  printf("%d\n", ans);
  for (int i = 1; i <= k; ++i) printf("%d %d\n", 1, i + 1);
  for (int i = k + 2; i <= n; ++i) printf("%d %d\n", i - k, i);
  return 0;
}