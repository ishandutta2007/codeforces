#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

typedef pair<double, double> line;
#define k first
#define l second
  
int y[303][303];
double a[303][303];

line v[303][303];
int m[303];

const double eps = 1e-8;
int ccw(line a, line b, line c) {
  double w = llint(a.k)*(b.l-c.l) + llint(b.k)*(c.l-a.l) + llint(c.k)*(a.l-b.l);
  return w < -eps ? -1 : w > eps;
}

line getLine(int x1, int y1, int x2, int y2) {
  double k = (y2-y1)/(x2-x1);
  double l = y1 - x1*k;
  return make_pair(k, l);
}

double equal(double x, double y) { return fabs(x-y) < eps; }

double intersect(line a, line b) {
  assert(!equal(a.k, b.k));
  return (b.l-a.l)/(a.k-b.k);
}

double eval(line l, double x) {
  return l.k*x + l.l;
}

double calcArea(line *a, int n) {
  double ans = 0;
  double lx = 0;
  REP(i, n) {
    double rx = 1;
    if (i+1 < n) rx = min(rx, intersect(a[i], a[i+1]));
    
    if (rx < lx) continue;

    double ly = eval(a[i], lx);
    double ry = eval(a[i], rx);
    
    if (ly > ry) swap(ly, ry);
    ans += (rx-lx)*(ly + (ry-ly)/2);
    lx = rx;
  }
  return ans;
}


int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) REP(j, k+1) scanf("%d", y[i]+j);
 
  REP(i, n) {
    double ans = 0;
    REP(j, k) {
      line l = getLine(0, y[i][j], 1, y[i][j+1]);

      int p = 0;
      while (p < m[j] && l >= v[j][p]) p++;
      
      // isti k
      if (p < m[j] && equal(v[j][p].k, l.k)); else {
        if (p-1 >= 0 && equal(v[j][p-1].k, l.k)) v[j][--p] = l; else {
          for (int s = m[j]; s > p; --s) v[j][s] = v[j][s-1];
          v[j][p] = l, m[j]++;
        }
        int ns = p;
        for (int s = p; s < m[j]; ++s) {
          if (s+1 < m[j] && equal(v[j][s].k, v[j][s+1].k)) continue;
          while (ns > 1 && ccw(v[j][ns-2], v[j][ns-1], v[j][s]) >= 0) ns--;
          v[j][ns++] = v[j][s];
        }
        m[j] = ns;
      }
      
      a[i][j] = calcArea(v[j], m[j]);
      ans += a[i][j];
      if (i > 0) ans -= a[i-1][j];
    }
    printf("%lf\n", ans);
  }
  
  return 0;
}