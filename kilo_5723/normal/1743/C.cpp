#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    // s[n] = '0';
    int las = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (s[i] == '1') {
        if (las > t) swap(las, t);
        ans += t;
      } else {
        las = t;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}