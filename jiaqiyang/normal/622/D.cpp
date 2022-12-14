#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = !(n & 1) + 1; i <= n; i += 2) printf("%d ", i);
  for (int i = n - 2; i > 0; i -= 2) printf("%d ", i);
  for (int i = (n & 1) + 1; i <= n; i += 2) printf("%d ", i);
  for (int i = n - 1; i > 0; i -= 2) printf("%d ", i);
  printf("%d\n", n);
  return 0;
}