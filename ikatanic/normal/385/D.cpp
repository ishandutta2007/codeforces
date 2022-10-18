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

const int MAX = 22;
const double pi = acos(-1);
const double inf = 1e9;

int x[MAX], y[MAX];
double f[1<<20];
double a[MAX];
double sa[MAX];

int main(void) {
  int n, l, r;

  scanf("%d %d %d", &n, &l, &r);
  REP(i, n) {
    scanf("%d %d %lf", x+i, y+i, a+i);
    a[i] *= pi/180;
    sa[i] = sin(a[i]);
  }

  REP(s, 1<<n) f[s] = -inf;
  f[0] = l;
  double best = 0;
  REP(s, 1<<n) {
    if (f[s] == -inf) continue;
    f[s] = min(f[s], r*1.0);
    best = max(best, f[s]-l);

    REP(i, n) {
      if (s&(1<<i)) continue;
      double b = atan2(y[i], x[i]-f[s]);
      if (b < 0) b += 2*pi;
      double c = pi - a[i] - b;

      if (c <= 0) f[s|(1<<i)] = max(f[s|(1<<i)], r*1.); else {
        double d = sqrt(y[i]*y[i] + (x[i]-f[s])*(x[i]-f[s]));
        f[s|(1<<i)] = max(f[s|(1<<i)], f[s] + d*sa[i]/sin(c));
      }
    }
  }

  printf("%.10lf\n", best);
  return 0;
}