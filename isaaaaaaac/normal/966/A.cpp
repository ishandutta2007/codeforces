#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n;
int xa[N], xb[N], na, nb, v;

inline int calc(int x, int x1, int x2) {
  if (x < x1) return (x1 - x) << 1;
  if (x > x2) return (x - x2) << 1;
  return 0;
}

int main() {
  scanf("%*d%*d");
  scanf("%d%d%d", &na, &nb, &v);
  for (int i = 1; i <= na; i ++) scanf("%d", &xa[i]);
  for (int i = 1; i <= nb; i ++) scanf("%d", &xb[i]);
  int q;
  scanf("%d", &q);
  for (int p, x1, y1, x2, y2, ans, d; q; q --) {
    scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
    d = y2 - y1;
    if (d < 0) d = - d;
    if (x1 > x2) swap(x1, x2);
    if (!d) {
      printf("%d\n", x2 - x1);
      continue;
    }
    ans = 1e9;
    p = lower_bound(xa + 1, xa + na + 1, x1) - xa;
    if (p <= na) ans = min(ans, calc(xa[p], x1, x2) + d);
    p --;
    if (p > 0) ans = min(ans, calc(xa[p], x1, x2) + d);
    p = lower_bound(xb + 1, xb + nb + 1, x1) - xb;
    if (p <= nb) ans = min(ans, calc(xb[p], x1, x2) + (d - 1) / v + 1);
    p --;
    if (p > 0) ans = min(ans, calc(xb[p], x1, x2) + (d - 1) / v + 1);
    p = lower_bound(xa + 1, xa + na + 1, x2) - xa;
    if (p <= na) ans = min(ans, calc(xa[p], x1, x2) + d);
    p --;
    if (p > 0) ans = min(ans, calc(xa[p], x1, x2) + d);
    p = lower_bound(xb + 1, xb + nb + 1, x2) - xb;
    if (p <= nb) ans = min(ans, calc(xb[p], x1, x2) + (d - 1) / v + 1);
    p --;
    if (p > 0) ans = min(ans, calc(xb[p], x1, x2) + (d - 1) / v + 1);
    printf("%d\n", ans + x2 - x1);
  }
  return 0;
}