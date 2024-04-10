#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Pt {
  int x, y, i;
  friend bool operator < (const Pt &a, const Pt &b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y > b.y;
  }
};

int ccw(const Pt &a, const Pt &b, const Pt &c) {
  llint w = 0;
  w += llint(b.x)*c.x*a.y*(c.y-b.y);
  w += llint(c.x)*a.x*b.y*(a.y-c.y);
  w += llint(a.x)*b.x*c.y*(b.y-a.y);
  return w < 0 ? -1 : w > 0;
}

const int MAXN = 200200;

Pt a[MAXN];
Pt h[MAXN];
bool can[MAXN];

int besty[MAXN], bestx[MAXN];

set<Pt> S;

int main(void) {
  int n;
  scanf("%d", &n);
  
  REP(i, n) {
    scanf("%d %d", &a[i].x, &a[i].y);
    besty[a[i].x] = max(besty[a[i].x], a[i].y);
    bestx[a[i].y] = max(bestx[a[i].y], a[i].x);
    a[i].i = i;
  }

  sort(a, a + n);
  
  int m = 0;
  REP(i, n) {
    if (bestx[a[i].y] != a[i].x) continue;
    if (besty[a[i].x] != a[i].y) continue;
    if (m > 0 && a[i].y <= h[m-1].y) continue;
    while (m >= 2 && ccw(h[m-2], h[m-1], a[i]) < 0) m--;
    h[m++] = a[i];
  }
  
  REP(i, m) S.insert(h[i]);
  REP(i, n)
    if (S.count(a[i])) can[a[i].i] = true;

  bool first = true;
  REP(i, n)
    if (can[i]) {
      if (!first) putchar(' ');
      printf("%d", i+1);
      first = false;
    }
  printf("\n");
  return 0;
}