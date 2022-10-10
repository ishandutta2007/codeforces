#include <bits/stdc++.h>

using namespace std;

int s, a, b, c;

double l(double p) {
  if (fabs(p) < 1e-9) return 0.0;
  return log(p);
}

pair<double, double> test(double x) {
  double lo = 0.0, hi = s - x;
  for (int i = 0; i < 50; ++i) {
    double d = (hi - lo) / 3.0;
    double mid1 = lo + d;
    double mid2 = lo + 2.0 * d;
    double tmp1 = b * l(mid1) + c * l(s - x - mid1);
    double tmp2 = b * l(mid2) + c * l(s - x - mid2);
    if (tmp1 < tmp2)
      lo = mid1;
    else
      hi = mid2;
  }
  return make_pair(lo, s - x - lo);
}

int main() {
  scanf("%d", &s);
  scanf("%d %d %d", &a, &b, &c);
  double lo = 0.0, hi = s;
  for (int i = 0; i < 50; ++i) {
    double d = (hi - lo) / 3;
    double mid1 = lo + d;
    double mid2 = lo + 2.0 * d;
    pair<double, double> p1 = test(mid1);
    pair<double, double> p2 = test(mid2);
    double tmp1 = a * l(mid1) + b * l(p1.first) + c * l(p1.second);
    double tmp2 = a * l(mid2) + b * l(p2.first) + c * l(p2.second);
    if (tmp1 < tmp2) {
      lo = mid1;
    } else {
      hi = mid2;
    }
  }
  pair<double, double> tmp = test(lo);
  printf("%.15lf %.15lf %.15lf\n", lo, tmp.first, tmp.second);
  return 0;
}