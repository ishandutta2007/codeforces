#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 50 + 10;

i64 s;

i64 solve(int a, int b, int cnt, i64 sum) {
  static i64 f[N + 1][2 * N][2];
  memset(f, 0, sizeof f);
  f[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= cnt; ++j) {
      for (int k = 0; k < 2; ++k) {
        i64 cur = f[i][j][k];
        if (!cur) continue;
        for (int x = 0; x < 2 && j + x <= cnt; ++x) {
          if (i >= a && x) continue;
          for (int y = 0; y < 2 && j + x + y <= cnt; ++y) {
            if (i >= b && y) continue;
            if (((x + y + k) & 1) != (sum >> i & 1)) continue;
            f[i + 1][j + x + y][(x + y + k) >> 1] += cur;
          }
        }
      }
    }
  }
  return f[N][cnt][0];
}

int main() {
  scanf("%lld", &s);
  i64 ans = 0;
  for (int a = 0; a <= 50; ++a) {
    for (int b = 0; b <= 50; ++b) {
      i64 det = 2 * ((1LL << a) + (1LL << b) - 1) - 1;
      i64 c = s / det;
      if (!c) continue;
      i64 t = s - det * c - ((1LL << b) - 1);
      for (int cnt = 0; cnt <= a + b; ++cnt) {
        i64 sum = t + cnt;
        if (sum < 0 || (sum & 1)) continue;
        sum >>= 1;
        ans += solve(a - 1, b - 1, cnt, sum);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}