#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 4e5 + 10;
int n, m, k, a[maxn];

void discretize() {
  static int data[maxn];
  for (int i = 1; i <= n; i++) {
    data[i] = a[i];
  }
  int tot = unique(data + 1, data + n + 1) - data - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(data + 1, data + tot + 1, a[i]) - data;
  }
}

signed main() {
  scanf("%I64d %I64d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a + 1, a + n + 1);
  discretize();
  int tmp = 8 * m / n;
  if (tmp > 60) tmp = 60;
  k = 1ll << tmp;
  int ans = n;
  for (int i = 1; i <= n; i++) {
    int l = a[i], r = l + k - 1;
    int pos = upper_bound(a + 1, a + n + 1, r) - a - 1;
    ans = min(ans, n - (pos - i + 1));
  }
  printf("%I64d", ans);
  return 0;
}