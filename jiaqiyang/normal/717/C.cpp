#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, MOD = 10007;

int n, a[N];

int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) ans = (ans + (i64)a[i] * a[n - i + 1]) % MOD;
  printf("%d\n", ans);
  return 0;
}