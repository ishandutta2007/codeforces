#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
struct triple{
  int x,w,i;
};
const int maxn = 2e5 + 5;
triple a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int tmp;
      scanf("%d%d", &a[i].x, &a[i].w);
      a[i].i = i + 1;
    }
    sort(a, a + m, [](triple a, triple b) { return a.w < b.w; });
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) ans += a[i].w;
    printf("%lld\n", ans);
    sort(a, a + 2 * n, [](triple a, triple b) { return a.x < b.x; });
    for (int i = 0; i < n; i++)
      printf("%d %d\n", a[i].i, a[2 * n - 1 - i].i);
    if (tt) puts("");
  }
  return 0;
}