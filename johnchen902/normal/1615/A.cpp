#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &x), sum += x;
    printf("%d\n", sum % n == 0 ? 0 : 1);
  }
}