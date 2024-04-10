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

typedef pair<int, int> pt;
#define x first
#define y second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool rec(int i, int a, int R, pt b[4], pt c[4], pt ans[4],
         bool fixedX, int x, int y1, int y2,
         bool fixedY, int y, int x1, int x2) {
  if (fixedX && fixedY) {
    if (x < x1 || x > x2) return false;
    if (y < y1 || y > y2) return false;
  }
  if (fixedX && y1 > y2) return false;
  if (fixedY && x1 > x2) return false;
  
  if (i == 4) {
    int offx, offy;
    if (fixedX && fixedY) offx = x, offy = y;
    else if (fixedX) offx = x, offy = y1;
    else if (fixedY) offy = y, offx = x1;
    else assert(false);

    REP(i, 4) {
      ans[i].x = c[i].x + offx;
      ans[i].y = c[i].y + offy;
    }
    return true;
  }

  int fy = b[i].y - c[i].y;
  int fx1 = b[i].x - c[i].x - R, fx2 = b[i].x - c[i].x + R;
  if (!fixedY) {
    if (rec(i + 1, a, R, b, c, ans,
            fixedX, x, y1, y2,
            true, fy, fx1, fx2))
      return true;
  } else {
    if (fy == y)
      if (rec(i + 1, a, R, b, c, ans,
              fixedX, x, y1, y2,
              fixedY, y, max(x1, fx1), min(x2, fx2))) return true;
  }

  int fx = b[i].x - c[i].x;
  int fy1 = b[i].y - c[i].y - R, fy2 = b[i].y - c[i].y + R;
  if (!fixedX) {
    if (rec(i + 1, a, R, b, c, ans,
            true, fx, fy1, fy2,
            fixedY, y, x1, x2))
      return true;
  } else {
    if (fx == x)
      if (rec(i + 1, a, R, b, c, ans,
              fixedX, x, max(y1, fy1), min(y2, fy2),
              fixedY, y, x1, x2)) return true;
  }
  return false;
}

bool can(pt a[4], pt ans[4], int R) {
  int pr[4] = {0, 1, 2, 3};
    
  set<int> t;
  REP(i, 4) REP(j, 4) {
    t.insert(abs(a[i].x - a[j].x));
    t.insert(abs(a[i].y - a[j].y));
  }

  do {
    pt b[4];
    REP(i, 4) b[i] = a[pr[i]];
    
    for (int a: t) {
      pt c[4] = {{0, 0}, {a, 0}, {0, a}, {a, a}};
      pt tmp[4];
      if (rec(0, a, R, b, c, tmp, false, 0, 0, 0, false, 0, 0, 0)) {
        REP(i, 4) ans[pr[i]] = tmp[i];
        return true;
      }
    }
    
  } while (next_permutation(pr, pr + 4));

  return false;
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    pt a[4], b[4];
    REP(i, 4) scanf("%d %d", &a[i].x, &a[i].y);

    int maks = 1e9;
    if (!can(a, b, maks)) {
      printf("%d\n", -1);
      continue;
    }

    int lo = 0, hi = maks;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (can(a, b, mid)) hi = mid;
      else lo = mid + 1;
    }

    printf("%d\n", lo);
    can(a, b, lo);
    REP(i, 4) printf("%d %d\n", b[i].x, b[i].y);
  }
  return 0;
}