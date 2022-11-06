#include <cstdio>


int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, c[2];
    scanf("%d", &n);
    c[0] = c[1] = 0;
    for (int i = 1, x; i <= n; i++)
      scanf("%d", &x), c[x]++;
    int u, x;
    if (c[0] >= n / 2)
      u = c[0], x = 0;
    else
      u = c[1], x = 1;
    if (u & 1 & x) u--;
    printf("%d\n", u);
    while (u--) printf("%d ", x);
    puts("");
  }
  return 0;
}