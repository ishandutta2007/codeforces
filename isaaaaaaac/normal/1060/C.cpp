#pragma GCC optimize("Ofast")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2050;

int n, m, a[N], b[N], x;
int tab[N * N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
  scanf("%d", &x);
  for (int i = 1; i <= m; i ++) {
    int s = 0;
    for (int j = i; j <= m; j ++) {
      s += b[j];
      tab[s] = max(tab[s], j - i + 1);
    }
  }
  for (int i = 1; i <= 4000000; i ++)
    tab[i] = max(tab[i], tab[i - 1]);
  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    int s = 0;
    for (int j = i; j <= n; j ++) {
      s += a[j];
      ans = max(ans, (j - i + 1) * tab[min(x / s, 4000000)]);
    }
  }
  printf("%d\n", ans);
  return 0;
}