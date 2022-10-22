#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;
ll sum[maxn], val[15];
int n, m, k, a[maxn], bl[maxn];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    bl[i] = (i - 1) % m + 1;
    sum[i] = sum[i - 1] + a[i];
  }
  bl[0] = m;
  ll ans = 0;
  memset(val, 0x3f, sizeof val);
  for (int i = 1; i <= n; i++) {
    val[bl[i - 1]] = min(val[bl[i - 1]], sum[i - 1]);
    val[bl[i - 1]] += k;
    for (int j = 1; j <= m; j++) {
      ans = max(ans, sum[i] - val[j]);
    }
  }
  printf("%I64d", ans);
  return 0;
}