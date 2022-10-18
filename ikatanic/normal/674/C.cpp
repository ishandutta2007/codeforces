#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;
const int MAXK = 52;
const double inf = 1e100;
const double eps = 1e-10;

llint s[MAX];
double g[MAX], h[MAX];
int t[MAX];

double f[MAXK][MAX];

struct Pt {
  double x, y;
};

int ccw(const Pt& a, const Pt& b, const Pt& c) {
  double w = 0;
  w += a.x * (b.y - c.y);
  w += b.x * (c.y - a.y);
  w += c.x * (a.y - b.y);
  return w < -eps ? -1 : w > eps;
}

int main(void) {
  int N, K;
  scanf("%d %d", &N, &K);
  REP(i, N) scanf("%d", &t[i]);

  s[0] = 0;
  REP(i, N) s[i + 1] = s[i] + t[i];
  g[0] = h[0] = 0;
  REP(i, N) {
    g[i + 1] = g[i] + s[i + 1] * 1.0 / t[i];
    h[i + 1] = h[i] + 1.0 / t[i];
  }

  REP(i, N) f[1][i+1] = g[i+1];

  FOR(k, 2, K+1) {
    vector<Pt> v;
    FOR(i, k-1, N+1) {
      Pt p = {-1.0*s[i], f[k-1][i] - g[i] + s[i]*h[i]};
      while (v.size() >= 2 && ccw(v[(int)v.size()-2], v.back(), p) > 0) v.pop_back();
      v.push_back(p);
    }

    int p = 0;
    FOR(j, k, N + 1) {
      while (p + 1 < (int)v.size() && v[p].x*h[j] + v[p].y > v[p+1].x*h[j] + v[p+1].y) p++;
      f[k][j] = v[p].x*h[j] + v[p].y + g[j];
    }
  }

  printf("%.10lf\n", f[K][N]);
  return 0;
}