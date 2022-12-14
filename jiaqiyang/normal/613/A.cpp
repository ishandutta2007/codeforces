#include <cmath>
#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;
const double PI = acos(-1.), eps = 1e-12;

inline double sqr(double x) { return x * x; }

int n;

struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y): x(_x), y(_y) {}
} o, point[N];

inline double dist(const Point &a, const Point &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double ternary(const Point &a, const Point &b) {
  Point v(b.x - a.x, b.y - a.y);
  double l = 0., r = 1.;
  while (fabs(r - l) > eps) {
    double p = l + (r - l) / 3., q = p + (r - l) / 3.;
    double x = dist(o, Point(a.x + p * v.x, a.y + p * v.y));
    double y = dist(o, Point(a.x + q * v.x, a.y + q * v.y));
    if (x < y) r = q; else l = p;
  }
  return dist(o, Point(a.x + l * v.x, a.y + l * v.y));
}

int main() {
  scanf("%d%lf%lf", &n, &o.x, &o.y);
  double min = 1. / 0., max = 0.;
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &point[i].x, &point[i].y);
  for (int i = 1; i <= n; ++i) {
    int j = i % n + 1;
    max = std::max(max, dist(o, point[i]));
    min = std::min(min, dist(o, point[i]));
    min = std::min(min, ternary(point[i], point[j]));
  }
  printf("%.12f\n", PI * (sqr(max) - sqr(min)));
  return 0;
}