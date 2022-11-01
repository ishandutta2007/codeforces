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
int n, a[N], mn, mx;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    mn = inf;
    mx = -inf;
    for (int i = 1; i <= n; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }
    int ans = n;
    bool f1 = true, f2 = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] == mn) f1 = false;
      if (a[i] == mx) f2 = false;
      if (!f1 && !f2) ans = min(ans, i);
    }
    f1 = f2 = true;
    for (int i = n; i >= 1; i--) {
      if (a[i] == mn) f1 = false;
      if (a[i] == mx) f2 = false;
      if (!f1 && !f2) ans = min(ans, n - i + 1);
    }
    for (int i = 1; i <= n; i++)
      if (a[i] == mn) {
        for (int j = n; j > i; j--)
          if (a[j] == mx) {
            ans = min(ans, i + n - j + 1);
            break;
          }
        break;
      }
    for (int i = 1; i <= n; i++)
      if (a[i] == mx) {
        for (int j = n; j > i; j--)
          if (a[j] == mn) {
            ans = min(ans, i + n - j + 1);
            break;
          }
        break;
      }
    printf("%d\n", ans);
  }
}