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

const int MAX = 100100;

typedef pair<int, int> Pt;
#define x first
#define y second

int convexHull(Pt *a, int n) {
  rotate(a, min_element(a, a + n), a + n);
  
  auto ccw = [](const Pt &a, const Pt &b, const Pt &c) {
    llint ccw = a.x*llint(b.y-c.y) + b.x*llint(c.y-a.y) + c.x*llint(a.y-b.y);
    return ccw < 0 ? -1 : ccw > 0;
  };

  auto dist = [](const Pt &a, const Pt &b) {
    return llint(a.x-b.x)*(a.x-b.x) + llint(a.y-b.y)*(a.y-b.y);
  };

  sort(a + 1, a + n, [&a, &ccw, &dist](const Pt &x, const Pt &y) {
      int c = ccw(a[0], x, y);
      if (c) return c > 0;
      return dist(a[0], x) < dist(a[0], y);
    }
  );
  
  int m = 0;
  REP(i, n) {
    while (m >= 2 && ccw(a[m-2], a[m-1], a[i]) <= 0) m--;
    a[m++] = a[i];
  }

  return m;
}

Pt a[MAX];

int main(void) {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  REP(i, n) scanf("%d %d", &a[i].x, &a[i].y);

  n = convexHull(a, n);

  double best = 1e100;
  auto test = [&] (double x, double y) {
    best = min(best, max(p/x, q/y));
  };

  REP(i, n) {
    test(a[i].x, a[i].y);
    
    int j = (i + 1) % n;
    llint num = llint(p)*a[j].y - llint(q)*a[j].x;
    llint denom = llint(q)*(a[i].x - a[j].x) - llint(p)*(a[i].y - a[j].y);
    if (denom) {
      double t = double(num) / denom;
      if (t > 0 && t < 1) test(t*a[i].x + (1-t)*a[j].x, t*a[i].y + (1-t)*a[j].y);
    }
  }  

  printf("%lf\n", best);
  return 0;
}