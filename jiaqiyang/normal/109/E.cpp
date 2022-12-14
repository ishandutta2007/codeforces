#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 15;

i64 n, k;
i64 base[N];

inline i64 calc(i64 x) {
  int res = 0;
  for (; x; x /= 10) if (x % 10 == 4 || x % 10 == 7) ++res;
  return res;
}

inline void check(i64 &lhs, i64 rhs) {
  if (lhs == -1 || rhs < lhs) lhs = rhs;
}

inline i64 get(i64 x, int d) {
  static i64 f[N][N][2];
  memset(f, -1, sizeof f);
  int t = calc(x) + d;
  static int bound[N], cnt;
  cnt = 0;
  for (; x; x /= 10) bound[cnt++] = x % 10;
  for (int i = cnt; i < N; ++i) bound[i] = 0;
  f[N - 1][0][0] = 0;
  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j <= t; ++j) {
      for (int k = 0; k < 2; ++k) {
        i64 cur = f[i + 1][j][k];
        if (cur == -1) continue;
        for (int s = k ? 0 : bound[i]; s < 10; ++s) {
          int y = j + (s == 4 || s == 7);
          if (y <= t) check(f[i][y][k || (s > bound[i])], cur + s * base[i]);
        }
      }
    }
  }
  return f[0][t][1];
}

int main() {
  base[0] = 1;
  for (int i = 1; i < N; ++i) base[i] = 10 * base[i - 1];
  scanf("%I64d%I64d", &n, &k);
  i64 m = n + k - 1;
  i64 t = 0;
  int b = 0;
  for (; k >= 10; ++b) t += n % 10 * base[b], n /= 10, m /= 10, k /= 10;
  static int mem[N];
  for (int i = 0; n + i <= m; ++i) mem[i] = calc(n + i);
  for (i64 i = get(n, 0);;) {
    for (int j = 0; n + j <= m; ++j) {
      int x = calc(i + j);
      if (x != mem[j]) {
        i = get(i + j, mem[j] - x) - j;
        goto fail;
      }
    }
    printf("%I64d\n", i * base[b] + t);
    break;
 fail:
    continue;
  }
  return 0;
}