#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n, a[maxn << 1];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n << 1; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + n + 1);
  ll ans = 1ll * (a[n] - a[1]) * (a[n + n] - a[n + 1]);
  for (int i = 1; i <= n; i++) {
    ans = min(ans, 1ll * (a[n + n] - a[1]) * (a[n + i] - a[i + 1]));
  }
  printf("%I64d", ans);
  return 0;
}