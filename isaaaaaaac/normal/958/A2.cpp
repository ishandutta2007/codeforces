#pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

typedef unsigned long long ULL;
const int N = 2050;

int n, m;
char c[N];
ULL a[N], b[N][N], pw[N];
map <ULL, int> tab;

int main() {
  for (int i = pw[0] = 1; i < N; i ++) pw[i] = pw[i - 1] * 27;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    scanf("%s", c + 1);
    ULL tmp = 0;
    for (int j = 1; j <= m; j ++)
      tmp = tmp * 27 + c[j] - 'a' + 1;
    a[i] = tmp;
  }
  for (int i = 1; i + m - 1 <= n; i ++) {
    ULL tmp = 0;
    for (int j = i; j <= i + m - 1; j ++)
      tmp = tmp * 19260817 + a[j];
    tab[tmp] = i;
  }
  for (int i = 1; i <= m; i ++) {
    scanf("%s", c + 1);
    for (int j = 1; j <= n; j ++)
      b[i][j] = b[i][j - 1] * 27 + c[j] - 'a' + 1;
  }
  for (int i = 1; i + m - 1 <= n; i ++) {
    ULL tmp = 0;
    for (int j = 1; j <= m; j ++)
      tmp = tmp * 19260817 + b[j][i + m - 1] - b[j][i - 1] * pw[m];
    if (tab.count(tmp)) {
      printf("%d %d\n", tab[tmp], i);
      return 0;
    }
  }
  return 0;
}