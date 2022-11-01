#include <stdio.h>
#include <algorithm>

int d[100'000];

long long solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", d + i);
  if (n == 1)
    return 0;

  long long ans = 0;
  if (auto it = std::max_element(d + 1, d + n); *it > 0)
    ans = *it;

  std::sort(d, d + n);
  for (int i = 0; i < n; i++) {
    ans -= (long long) d[i] * (2 * i - n + 1);
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    printf("%lld\n", solve());
}