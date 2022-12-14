#include <cstdio>

int n, m, v1, v2, k;

int main() {
  // v1 (t-x) + v2 x = m
  scanf("%d%d%d%d%d", &n, &m, &v1, &v2, &k);
  double l = 0., r = (double)m / v1;
  auto f = [&] (double t) { return (m - v1 * t) / (v2 - v1); };
  int c = (n + k - 1) / k;
  for (int i = 100; i--;) {
    double mid = (l + r) / 2., x = f(mid);
    double sum = 0.;
    for (int j = 1; j <= c; ++j) {
      double p = j > 1 ? (sum - x) * v1 + x * v2 : 0.;
      double q = v1 * sum;
      double d = p - q;
      // v1 * x + v2 * x = d
      sum += d / (v1 + v2);
      sum += x;
    }
    if (sum <= mid) r = mid; else l = mid;
  }
  printf("%.12f\n", l);
  return 0;
}