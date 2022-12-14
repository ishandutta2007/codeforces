#include <cmath>
#include <cstdio>
#include <cstring>

const int N = 30000 + 10, M = 100 + 10, gap = 50;

int n, h;

namespace Alice {

double pool[M], *e = pool + gap + 1, P[N][M];

void Solve() {
  double ans = 0.0;
  for (int i = -gap; i <= gap; ++i) e[i] = pow(2.0, i);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= gap; ++j)
      P[i][j] = 1.0 - pow(1.0 - e[-j], i);
  for (int i = 1; i < n; ++i) {
    static double g[M];
    for (int j = 0; j <= h; ++j) {
      g[j] = 0;
      static double f[M];
      for (int k = j; k < h; ++k) 
        f[k] = P[n - i][j] - P[n - i][k + 1] * P[i - 1][k + 1];
      for (int k = j; k < h; ++k) g[j] += e[-(k + 1)] * f[k];
      g[j] += e[-h] * P[n - i][j];
    }
    for (int j = 0; j <= h; ++j) ans += (g[j] - g[j + 1]) * e[j];
  }
  printf("%.10f\n", ans + 1.0);
}

}

namespace Bob {

void Solve() {
  printf("%d\n", n);
}

}

int main() {
  static char s[10];
  scanf(" %s%d%d", s, &n, &h);
  if (s[0] == 'A') Alice::Solve(); else Bob::Solve();
  return 0;
}