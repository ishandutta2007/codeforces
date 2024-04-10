#include <bits/stdc++.h>
int n;
bool isp(int x) {
  for(int i = 2; i * i <= x; i ++)
    if(x % i == 0) return 0;
  return x > 1;
}
int main() {
  scanf("%d", &n);
  int m = n * (n + 1) / 2;
  if(isp(m)) {
    for(int i = n; i --; ) printf("1 ");
    putchar('\n');
    return 0;
  }
  bool v = 0;
  if(m % 2 == 1) {
    if(isp(m - 2)) {
      for(int i = 1; i <= n; i ++) printf("%d ", 1 + (i == 2));
      putchar('\n');
      return 0;
    }
    m -= 3; v = 1;
  }
  int u = 0;
  for(int i = 2; i <= m - i; i ++)
    if(isp(i) && isp(m - i)) {
      u = i; break ;
    }
  for(int i = 1; i <= n; i ++)
    printf("%d ", i == 3 && v ? 3 : (i == u ? 2 : 1));
  putchar('\n');
  return 0;
}