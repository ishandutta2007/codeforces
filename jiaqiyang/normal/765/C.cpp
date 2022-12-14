#include <cstdio>
#include <algorithm>

int k, a, b;

int main() {
  scanf("%d%d%d", &k, &a, &b);
  if (a < k && b < k) return puts("-1"), 0;
  if (a < b) std::swap(a, b);
  if (b < k && a % k) return puts("-1"), 0;
  printf("%d\n", a / k + b / k);
  return 0;
}