#include <cmath>
#include <cstdio>
#include <map>
#include <algorithm>

const int N = 2000 + 10;
const double eps = 1e-10, INF = 1e9, PI = acos(-1.);

inline double sqr(double x) { return x * x; }

struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y): x(_x), y(_y) {}
  inline double arg() const { return atan2(y, x); }
};

inline Point operator+ (const Point &lhs, const Point &rhs) { return Point(lhs.x + rhs.x, lhs.y + rhs.y); }
inline Point operator- (const Point &lhs, const Point &rhs) { return Point(lhs.x - rhs.x, lhs.y - rhs.y); }

inline double cross(const Point &o, const Point &a, const Point &b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

inline double dist(const Point &lhs, const Point &rhs) { return sqrt(sqr(lhs.x - rhs.x) + sqr(lhs.y - rhs.y)); }

int n, m;
Point p[N];

bool solve(const Point &o, double r) {
  std::map< double, std::pair<int, int> > cnt;
  std::pair<int, int> sum;
  cnt[0] = cnt[2. * PI] = std::pair<int, int>();
  for (int i = 0; i < n + m; ++i) {
    double x = (p[i] - o).arg(), d = dist(p[i], o);
    if (d > 2. * r) continue;
    if (d == 0.) {
      if (i < n) ++sum.first;
      continue;
    }
    double y = acos(d / 2. / r);
    double u = fmod(x - y + 2. * PI, 2. * PI), v = fmod(x + y + 2. * PI, 2. * PI);
    if (i < n) {
      ++cnt[u].first, --cnt[v].first;
      if (u > v) ++cnt[0].first, --cnt[2. * PI].first;
    } else {
      ++cnt[u].second, --cnt[v].second;
      if (u > v) ++cnt[0].second, --cnt[2. * PI].second;
    }
  }
  std::map< double, std::pair<int, int> >::iterator i, j;
  i = cnt.begin();
  for (j = i++; i != cnt.end(); ++i, ++j) {
    sum.first += j->second.first, sum.second += j->second.second;
    if (i->first - j->first > eps && sum.first && !sum.second) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n + m; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  double l = .5;
  for (int i = 0; i < n + m; ++i) {
    double r = INF;
    if (!solve(p[i], l)) continue;
    for (int cnt = 50; cnt-- && fabs(r - l) > 1e-5 * std::max(l, 1.);) {
      double mid = (l > 1. ? sqrt(l * r) : (l + r) / 2.);
      if (solve(p[i], mid)) l = mid; else r = mid;
    }
  }
  printf("%.10f\n", (INF - l) < 5e-4 * INF ? -1 : l);
  return 0;
}