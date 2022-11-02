#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if (n == 1) {
      puts("0");
      continue;
    }
    if (n == 2) {
      printf("%d\n", max(a[0] - a[1], a[1] - a[0]));
      continue;
    }
    int ans = a[n - 1] - a[0];
    int mxm = 0, mnm = 1000;
    for (int i = 1; i < n - 1; i++) {
      mxm = max(mxm, a[i]);
      mnm = min(mnm, a[i]);
    }
    for (int i = 1; i < n; i++) ans = max(ans, a[i - 1] - a[i]);
    ans = max(ans, mxm - a[0]);
    ans = max(ans, a[n - 1] - mnm);
    printf("%d\n", ans);
  }
  return 0;
}