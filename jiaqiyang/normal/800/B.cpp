#include <cmath>
#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;

int n;

struct Point {
  double x, y;
} p[N];

inline double sqr(double x) { return x * x; }

inline double dist(const Point &a, const Point &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double cross(const Point &o, const Point &a, const Point &b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double solve(const Point &a, const Point &b, const Point &c) {
  return fabs(cross(a, b, c) / dist(a, b));
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  double ans = 1e12;
  p[n] = p[0], p[n + 1] = p[1];
  for (int i = 0; i < n; ++i) ans = std::min(ans, dist(p[i], p[i + 1]) / 2.);
  for (int i = 0; i < n; ++i) ans = std::min(ans, solve(p[i], p[i + 2], p[i + 1]) / 2.);
  printf("%.12f\n", ans);
  return 0;
}