#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i + 1 < n - 1; i++)
      ans = max(ans, a[n - 1] - a[i] + a[i + 1] - a[i]);
    for (int i = n - 1; i - 1 > 0; i--)
      ans = max(ans, a[i] - a[0] + a[i] - a[i - 1]);
    printf("%lld\n", ans);
    // printf("%lld\n", a[n - 1] - a[0] + max(a[1] - a[0], a[n - 1] - a[n -
    // 2]));
  }
  return 0;
}