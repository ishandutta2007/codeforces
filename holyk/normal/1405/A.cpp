#include <cstdio>


int main() {
  int t; scanf("%d", &t);
  while (t--) {
    static int n, a[102];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = n; i; i--)
      printf("%d ", a[i]);
    puts("");
  }
  return 0;
}