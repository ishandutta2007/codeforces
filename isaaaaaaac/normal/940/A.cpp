#include <cstdio>
#include <iostream>
using namespace std;
int a[104];
int main() {
  int n, d, Max = 0;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int j = 1; j <= 100; j ++) {
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
      if (j <= a[i] && a[i] <= j + d) cnt ++;
    Max = max(Max, cnt);
  }
  printf("%d\n", n - Max);
  return 0;
}