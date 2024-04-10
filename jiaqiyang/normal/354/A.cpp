#include <cstdio>
#include <climits>
#include <algorithm>

const int N = 100000 + 10;

int n, l, r, a, b, w[N], sum[N];

int main() {
  scanf("%d%d%d%d%d", &n, &l, &r, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]), sum[i] = sum[i - 1] + w[i];
  int ans = INT_MAX;
  for (int i = 0; i <= n; ++i) {
    int p = i, q = n - i;
    int x = sum[i], y = sum[n] - sum[i];
    int cur = x * l + y * r;
    cur += std::max(p - 1 - q, 0) * a + std::max(q - 1 - p, 0) * b;
    ans = std::min(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}