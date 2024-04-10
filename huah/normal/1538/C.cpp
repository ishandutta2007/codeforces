#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, l, r, a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1, j = n, k = n; i <= n; i++) {
      int L = n + 1, R = -1;
      while (j && a[i] + a[j] > r) j--;
      if (j && a[i] + a[j] <= r) R = j;
      while (k - 1 >= 1 && a[i] + a[k - 1] >= l) k--;
      if (a[i] + a[k] >= l) L = k;
      if (L <= R) ans += R - L + 1;
    }
    for (int i = 1; i <= n; i++) ans -= a[i] + a[i] >= l && a[i] + a[i] <= r;
    printf("%lld\n", ans >> 1);
  }
}