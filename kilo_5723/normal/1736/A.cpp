#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn], b[maxn];
int _abs(int n) { return n < 0 ? -n : n; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i] ^ b[i];
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) sa += a[i];
    for (int i = 0; i < n; i++) sb += b[i];
    ans = min(ans, _abs(sa - sb) + 1);
    printf("%d\n", ans);
  }
  return 0;
}