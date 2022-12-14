#include <cmath>
#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 2000000 + 10;

inline i64 sqr(i64 x) { return x * x; }
inline i64 cube(i64 x) { return x * x * x; }

int m;
i64 n, f[N];

inline i64 val(int x) { return x <= m ? x : (n / (2 * m - x + 1)); }
inline int pos(i64 x) { return x <= m ? x : (2 * m - n / x + 1); }

int main() {
  scanf("%I64d", &n);
  m = sqrtl(n);
  for (int i = 1; i <= 2 * m; ++i) f[i] = val(i) - 1;
  for (int i = 1; i <= m; ++i) {
    if (f[i] == f[i - 1]) continue;
    for (int j = 2 * m; val(j) >= sqr(i); --j) f[j] -= f[pos(val(j) / i)] - f[i - 1];
  }
  i64 ans;
  for (int i = 1;; ++i) {
    if (cube(i) > n) {
      ans = f[i - 1];
      break;
    }
  }
  for (int i = 1; i <= m; ++i) if (f[i] > f[i - 1]) ans += f[pos(n / i)] - f[i];
  printf("%I64d\n", ans);
  return 0;
}