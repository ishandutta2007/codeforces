#include <algorithm>
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
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 1e9;
    for (int i = 2; i < n; i++) ans = min(ans, a[i] - a[i - 2]);
    printf("%d\n", ans);
  }
  return 0;
}