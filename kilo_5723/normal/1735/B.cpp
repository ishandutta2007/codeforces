#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mnm = inf;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mnm = min(mnm, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (a[i] - 1) / (mnm * 2 - 1);
    printf("%d\n", ans);
  }
  return 0;
}