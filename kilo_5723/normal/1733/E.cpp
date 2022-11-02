#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 140;
ll a[maxn][maxn];
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    ll t;
    int x, y;
    scanf("%lld%d%d", &t, &x, &y);
    a[0][0] = t - x - y;
    if (a[0][0] < 0) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < maxn; i++)
      for (int j = 0; j < maxn; j++) {
        if (i || j) a[i][j] = 0;
        if (i) a[i][j] += a[i - 1][j] / 2;
        if (j) a[i][j] += (a[i][j - 1] + 1) / 2;
      }
    int p = 0, q = 0;
    while (p + q < x + y) {
      if (a[p][q] & 1)
        p++;
      else
        q++;
    }
    puts(p == x ? "YES" : "NO");
  }
  return 0;
}