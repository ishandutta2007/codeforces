#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
const int maxn = 2e5 + 5;
int x[maxn], t[maxn], a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    int mxm = -inf, mnm = inf;
    for (int i = 0; i < n; i++) {
      mxm=max(mxm,x[i]+t[i]);
      mnm=min(mnm,x[i]-t[i]);
    }
    printf("%lf\n", (mxm+mnm) / 2.0);
  }
  return 0;
}