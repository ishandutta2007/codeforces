#include <stdio.h>
#include <algorithm>

const int SAD = 10000000;

int n;
int a[100005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  int ans = SAD;
  for (int i = 2; i < n; ++i) if ((a[i-2]^a[i-1]) > a[i] || (a[i-1]^a[i]) < a[i-2])
    ans = 1;
  if (ans != 1) {
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) for (int k = j+1; k <= n; ++k) {
      int x1 = 0, x2 = 0;
      for (int x = i; x < j; ++x) x1 ^= a[x];
      for (int x = j; x < k; ++x) x2 ^= a[x];
      if (x2 < x1) {
        ans = std::min(ans, k-i-2);
      }
    }
  }
  printf("%d\n", ans < SAD ? ans : -1);
  return 0;
}