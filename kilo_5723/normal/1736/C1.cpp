#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int r = 0;
    ll ans = 0;
    for (int l = 0; l < n; l++) {
      while (r < n && a[r] >= r - l + 1) r++;
      ans += r - l;
    }
    printf("%lld\n", ans);
  }
  return 0;
}