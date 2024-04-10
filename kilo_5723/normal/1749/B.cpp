#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll a[maxn], b[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      ans += a[i];
    }
    ll mxm = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &b[i]);
      ans += b[i];
      mxm = max(mxm, b[i]);
    }
    printf("%lld\n", ans - mxm);
  }
  return 0;
}