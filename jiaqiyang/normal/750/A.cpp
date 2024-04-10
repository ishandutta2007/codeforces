#include <stdio.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  k = 240 - k;
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (k >= 5 * i) k -= 5 * i, ++ans; else break;
  printf("%d\n", ans);
  return 0;
}