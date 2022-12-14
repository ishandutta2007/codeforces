#include <cmath>
#include <cstdio>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<double, int> Info;

const int N = 2000 + 10;

inline void check(Info& lhs, const Info &rhs) { lhs = (lhs.fst < rhs.fst ? lhs : rhs); }

int n, a, b;
double p[N], u[N], q[N];

Info f[N][N];

Info solve(double k) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= b && j <= i; ++j)
      f[i][j] = std::make_pair(1. / 0., 0);
  f[0][0] = std::make_pair(0., 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= b && j <= i; ++j) {
      Info cur = f[i][j];
      check(f[i + 1][j], Info(cur.fst + 1., cur.snd));
      check(f[i + 1][j], Info(cur.fst + p[i] - k, cur.snd + 1));
      check(f[i + 1][j + 1], Info(cur.fst + u[i], cur.snd));
      check(f[i + 1][j + 1], Info(cur.fst + p[i] * u[i] - k, cur.snd + 1));
    }
  }
  return *std::min_element(f[n], f[n] + b + 1);
}

int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++i) scanf("%lf", &p[i]), p[i] = 1. - p[i];
  for (int i = 0; i < n; ++i) scanf("%lf", &u[i]), u[i] = 1. - u[i];
  double l = -1., r = 1.;
  for (int i = 30; i--;) {
    double mid = (l + r) / 2.;
    if (solve(mid).snd <= a) l = mid; else r = mid;
  }
  printf("%.7f\n", n - (l * a + solve(l).fst));
  return 0;
}