#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ans += 1ll * a[i] * (n - a[i] + 1);
    ans -= i > 1 ? 1ll * min(a[i - 1], a[i]) * (n - max(a[i - 1], a[i]) + 1) : 0;
  }
  printf("%I64d", ans);
  return 0;
}