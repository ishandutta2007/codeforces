#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  ll ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int v = min((ll) a[i] / 2, sum);
    ans += v, sum -= v, a[i] -= v << 1;
    ans += a[i] / 3, sum += a[i] - a[i] / 3 * 3;
  }
  printf("%I64d", ans);
  return 0;
}