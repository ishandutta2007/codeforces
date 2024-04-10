#include <cstdio>
#include <algorithm>

typedef long long LL;

constexpr int N(1e5 + 5);

int n;
LL a[N], ans;

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i] += a[i - 1];
      ans = std::max(ans, -a[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}