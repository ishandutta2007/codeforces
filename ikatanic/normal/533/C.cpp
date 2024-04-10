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

bool okay(int x1, int y1, int x2, int y2) {
  if (x1 < 0 || y1 < 0) return false;
  if (x1 == x2 && y1 == y2) return false;
  return true;
}

int main(void) {
  int xp, yp, xv, yv;
  scanf("%d %d %d %d", &xp, &yp, &xv, &yv);
  bool who = true;

  while (true) {
    if (xp == 0 && yp == 0) {
      puts("Polycarp");
      return 0;
    }

    if (xv == 0 && yv == 0) {
      puts("Vasiliy");
      return 0;
    }

    if (who) {
      bool okx = okay(xp-1, yp, xv, yv);
      bool oky = okay(xp, yp-1, xv, yv);

      if (!okx && oky) yp--; else
        if (!oky && okx) xp--; else
          if (okx && oky) {
            if (xp-yp < xv-yv) yp--; else
              xp--;
          }
    } else {
      if (okay(xv-1, yv-1, xp, yp)) xv--, yv--; else {
        bool okx = okay(xv-1, yv, xp, yp);
        bool oky = okay(xv, yv-1, xp, yp);
        if (!okx && oky) yv--; else
          if (okx && !oky) xv--; else
            if (okx && oky) {
              if (xv > yv) xv--; else
                yv--;
            }
      }
    }
    who ^= 1;
  }


  return 0;
}