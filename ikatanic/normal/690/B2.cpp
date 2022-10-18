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

const int MAX = 505;

typedef long long llint;
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

char a[MAX][MAX];

int main(void) {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n == 0) break;

    for (int i = n-1; i >= 0; --i) {
      scanf("%s", a[i]);
      REP(j, n) a[i][j] -= '0';
    }

    vector<Pt> v;
    REP(i, n-1) REP(j, n-1)
      if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
        --a[i][j], --a[i+1][j], --a[i][j+1], --a[i+1][j+1];
        v.push_back({j+1, i+1});
      }

    REP(i, n) REP(j, n)
      assert(a[i][j] == 0);

    int m = convexHull(&v[0], v.size());
    printf("%d\n", m);
    reverse(v.begin() + 1, v.begin() + m);
    REP(i, m) {
      printf("%d %d\n", v[i].x, v[i].y);
    }
  }
  
  return 0;
}