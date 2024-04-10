#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn], r[maxn], s[maxn];
ll sr[maxn], ss[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  r[0] = 1;
  for (int i = 1; i <= n; i++) {
    r[i] = r[i - 1];
    while (r[i] <= n && a[r[i]] >= r[i] - i + 1) r[i]++;
    s[i] = s[i - 1];
    if (s[i] < r[i] + 1) s[i] = min(r[i] + 1, n + 1);
    while (s[i] <= n && a[s[i]] >= s[i] - i + 1) s[i]++;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += r[i] - i;
  // for (int i = 1; i <= n; i++) printf("%d ", r[i]);
  // puts("");
  // for (int i = 1; i <= n; i++) printf("%d ", s[i]);
  // puts("");
  // printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    sr[i] = sr[i - 1] + r[i];
    ss[i] = ss[i - 1] + s[i] - r[i];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k, x;
    scanf("%d%d", &k, &x);
    if (x < a[k]) {
      int p = lower_bound(r + 1, r + n + 1, k) - r, q = k - x + 1;
      if (q <= p)
        printf("%lld\n", ans);
      else
        printf("%lld\n", ans - sr[q - 1] + sr[p - 1] + 1LL * k * (q - p));

    } else {
      int p = lower_bound(r + 1, r + n + 1, k) - r,
          q = upper_bound(r, r + n + 1, k) - r;
      p = max(p, k - x + 1);
      if (q <= p)
        printf("%lld\n", ans);
      else
        printf("%lld\n", ans + ss[q - 1] - ss[p - 1]);
    }
  }
  return 0;
}