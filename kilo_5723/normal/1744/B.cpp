#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    ll ans = 0, c[2];
    c[0] = c[1] = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      ans += t;
      c[t & 1]++;
    }
    while (q--) {
      int t, x;
      scanf("%d%d", &t, &x);
      ans += c[t] * x;
      if (x & 1) {
        c[!t] += c[t];
        c[t] = 0;
      }
      printf("%lld\n",ans);
    }
  }
  return 0;
}