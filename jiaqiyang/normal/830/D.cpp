#include <cstdio>

typedef long long i64;

const int N = 400 + 10, MOD = 1000000007;

inline void add(int &lhs, i64 rhs) { lhs = (lhs + rhs) % MOD; }

int n, f[N][N];

int main() {
  scanf("%d", &n);
  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int x = 0; x <= n; ++x) {
      for (int y = 0; x + y <= n; ++y) {
        int cur = (i64)f[i - 1][x] * f[i - 1][y] % MOD;
        if (!cur) continue;
        add(f[i][x + y], cur);
        add(f[i][x + y + 1], cur);
        if (x) add(f[i][x + y], 2LL * x * cur);
        if (y) add(f[i][x + y], 2LL * y * cur);
        if (x || y) add(f[i][x + y - 1], (x + y) * (x + y - 1LL) * cur);
      }
    }
  }
  printf("%d\n", f[n][1]);
  return 0;
}