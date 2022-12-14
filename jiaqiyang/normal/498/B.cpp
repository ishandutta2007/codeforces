#include <cmath>
#include <cstdio>
#include <algorithm>

const int N = 5000 + 10;
const double eps = 1e-12;

int n, m;

int t[N];
double f[N][N], p[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%lf%d", &p[i], &t[i]), p[i] /= 100.;
  f[0][0] = 1.;
  for (int i = 0; i < n; ++i) {
    static double tag[2 * N];
    std::fill(tag, tag + m + 1, 0.);
    double temp = pow(1. - p[i], t[i] - 1);
    for (int j = 0; j < m; ++j) {
      double cur = f[i][j];
      if (fabs(cur) < eps) continue;
      tag[j + 1] += cur;
      if (j + t[i] <= m) {
        tag[j + t[i]] -= cur * temp;
        f[i + 1][j + t[i]] += cur * temp;
      }
    }
    for (int j = 1; j <= m; ++j) tag[j] += tag[j - 1] * (1. - p[i]);
    for (int j = 0; j <= m; ++j) if (fabs(tag[j]) > eps) f[i + 1][j] += tag[j] * p[i];
  }
  double ans = 0.;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      ans += f[i][j];
  printf("%.12f\n", ans);
  return 0;
}