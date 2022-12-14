#include <cmath>
#include <cstdio>

const int N = 100000 + 10;

int n, p, a[N], b[N];

bool solve(double x) {
  double sum = 0.;
  for (int i = 1; i <= n; ++i) if (a[i] * x - b[i] >= 0.) sum += a[i] * x - b[i];
  return p * x >= sum;
}

int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
  double l = 0., r = 1e15;
  for (int i = 80; i--;) {
    double mid = (l > 1. ? sqrt(l * r) : (l + r) / 2.);
    if (solve(mid)) l = mid; else r = mid;
  }
  printf("%.12f\n", l > 1e14 ? -1 : l);
  return 0;
}