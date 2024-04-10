#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;
const int MAXCOOR = 2000100;
const double eps = 1e-9;

double solve(int n, int *x, int *y) {
  llint area = 0;
  REP(i, n) {
    llint x1 = x[i], y1 = y[i];
    llint x2 = x[(i+1)%n], y2 = y[(i+1)%n];
    area += x1*y2 - x2*y1;
  }

  if (area < 0) {
    reverse(x, x + n);
    reverse(y, y + n);
  }

  static int s[MAXCOOR][2];
  REP(i, MAXCOOR) s[i][0] = s[i][1] = 0;

  llint cnt = 0;
  REP(i, n) {
    int x1 = x[i], x2 = x[(i+1)%n];
    int y1 = y[i], y2 = y[(i+1)%n];

    if (x1 == x2) continue;
    bool smjer = x1 < x2;
    
    int lo = x1, hi = x2;
    if (lo > hi) swap(lo, hi);
    
    double k = double(y2-y1)/(x2-x1);
    for (int x = lo; x <= hi; ++x) {
      double yd = (x-x1)*k + y1;
      llint y = !smjer ? floor(yd) : ceil(yd);
      s[x][smjer] = y;
    }
  }

  double ex = 0, exx = 0;
  REP(x, MAXCOOR) {
    if (s[x][0] == 0 && s[x][1] == 0) continue;
    llint c = s[x][0] - s[x][1] + 1;
    llint X = x - MAXCOOR/2;
    ex += c * X;
    exx += c * X * X;
    cnt += c;
  }
  ex /= cnt, exx /= cnt;
  return (exx - ex*ex) * (double(cnt)/(cnt-1));
}

int main(void) {
  static int x[MAXN], y[MAXN];
  
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d", x+i, y+i);
    x[i] += MAXCOOR/2;
    y[i] += MAXCOOR/2;
  }

  double ans = 0;
  ans += solve(n, x, y);
  ans += solve(n, y, x);
  printf("%.10lf\n", ans);
  return 0;
}