#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 3e5 + 5;
int a[maxn];
ll solve(int n, int k) {
  ll one = 0, two = 0;
  for (int i = 0; i < n; i++) {
    one += (k - a[i]) & 1;
    two += (k - a[i]) >> 1;
  }
  // printf("%d %d\n", one, two);
  if (one > two) return one * 2 - 1;
  two -= one;
  return one * 2 + two + (two + 2) / 3;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int k = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      k = max(k, a[i]);
    }
    ll ans = inf;
    for (int i = 0; i < 10; i++) ans = min(ans, solve(n, k + i));
    printf("%lld\n", ans);
  }
  return 0;
}