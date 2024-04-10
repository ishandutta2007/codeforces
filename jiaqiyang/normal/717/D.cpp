#include <cmath>
#include <cstdio>

const int N = 8;

int n, x;
double p[1 << N];

void fwt(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  fwt(l, mid);
  fwt(mid, r);
  int t = mid - l;
  for (int i = l; i < mid; ++i) {
    double x = p[i], y = p[i + t];
    p[i] = x + y;
    p[i + t] = x - y;
  }
}

void ifwt(int l, int r) {
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  ifwt(l, mid);
  ifwt(mid, r);
  int t = mid - l;
  for (int i = l; i < mid; ++i) {
    double x = p[i], y = p[i + t];
    p[i] = (x + y) / 2.;
    p[i + t] = (x - y) / 2.;
  }
}

int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i <= x; ++i) scanf("%lf", &p[i]);
  fwt(0, 1 << N);
  for (int i = 0; i < (1 << N); ++i) p[i] = pow(p[i], n);
  ifwt(0, 1 << N);
  double ans = 0.;
  for (int i = 1; i < (1 << N); ++i) ans += p[i];
  printf("%.12f\n", ans);
  return 0;
}