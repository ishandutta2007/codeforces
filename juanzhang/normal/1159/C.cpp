#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, a[maxn], b[maxn];

int main() {
  scanf("%d %d", &n, &m);
  bool flg = 0;
  ll ans = 0, sum = 0;
  int mn = 1 << 30, mx = 0, pos = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ans += 1ll * a[i] * m;
    if (mx < a[i]) {
      mx = a[i], pos = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
    flg |= b[i] == mx;
    mn = min(mn, b[i]), sum += b[i];
  }
  if (mx > mn) return puts("-1"), 0;
  ans += sum - mn - 1ll * (m - 1) * mx;
  if (!flg) {
    int tmp = 1 << 30;
    for (int i = 1; i <= n; i++) {
      if (i != pos) tmp = min(tmp, max(0, mn - a[i]));
    }
    ans += tmp;
  }
  printf("%I64d", ans);
  return 0;
}