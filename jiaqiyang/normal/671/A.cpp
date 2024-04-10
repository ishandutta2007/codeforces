#include <cmath>
#include <cstdio>
#include <algorithm>

#define fst first
#define snd second

const int N = 100000 + 10;

int n;

struct Point {
  int x, y;
} a, b, t, point[N];

double cur[N];

inline double sqr(double x) { return x * x; }

inline double dist(const Point &lhs, const Point &rhs) {
  return sqrt(sqr(lhs.x - rhs.x) + sqr(lhs.y - rhs.y));
}

int main() {
  scanf("%d%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &t.x, &t.y, &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &point[i].x, &point[i].y);
  for (int i = 1; i <= n; ++i) cur[i] = dist(point[i], t);
  static double p[N], q[N];
  for (int i = 1; i <= n; ++i) p[i] = dist(a, point[i]) - cur[i], q[i] = dist(b, point[i]) - cur[i];
  std::pair<int, int> u(1, 0), v(1, 0);
  for (int i = 2; i <= n; ++i) if (p[i] < p[u.fst]) u.snd = u.fst, u.fst = i; else if (!u.snd || p[i] < p[u.snd]) u.snd = i;
  for (int i = 2; i <= n; ++i) if (q[i] < q[v.fst]) v.snd = v.fst, v.fst = i; else if (!v.snd || q[i] < q[v.snd]) v.snd = i;
  double ans = 0.;
  for (int i = 1; i <= n; ++i) ans += 2. * cur[i];
  if (n > 1) {
    double det = std::min(p[u.fst], q[v.fst]);
    if (u.fst != v.fst) det = std::min(det, p[u.fst] + q[v.fst]);
    if (v.snd && u.fst != v.snd) det = std::min(det, p[u.fst] + q[v.snd]);
    if (u.snd && u.snd != v.fst) det = std::min(det, p[u.snd] + q[v.fst]);
    if (u.snd && v.snd && u.snd != v.snd) det = std::min(det, p[u.snd] + q[v.snd]);
    ans += det;
  } else {
    ans = std::min(dist(a, point[1]) + dist(point[1], t), dist(b, point[1]) + dist(point[1], t));
  }
  printf("%.12f\n", ans);
  return 0;
}