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

const int MAX = 1000100;

struct Pt {
  int x, y;
} a[MAX];

int ccw(const Pt &a, const Pt &b, const Pt &c) {
  llint w = 0;
  w += llint(a.x) * (b.y - c.y);
  w += llint(b.x) * (c.y - a.y);
  w += llint(c.x) * (a.y - b.y);
  return w < 0 ? -1 : w > 0;
}

int ans[MAX];

int main(void) {
  int k, n;
  scanf("%d %d", &k, &n);
  REP(i, n) scanf("%d %d", &a[i].x, &a[i].y);
  FOR(i, 1, k+1) ans[i] = 1;
  
  REP(i, n) REP(j, i) {
    int cnt = 0;
    REP(k, n)
      if (ccw(a[i], a[j], a[k]) == 0) cnt++;

    int x1 = a[i].x, y1 = a[i].y;
    int x2 = a[j].x, y2 = a[j].y;

    if (x1 == x2 && x1 <= k) {
      ans[x1] = max(ans[x1], cnt);
      continue;
    }
    if (y1 == y2) continue;

    llint A = llint(y1)*(x1 - x2);
    if (A % (y1-y2)) continue;
    
    llint x = x1 - A / (y1-y2);
    if (x > 0 && x <= k) {
      ans[x] = max(ans[x], cnt);
      assert(ccw(a[i], a[j], {(int)x, 0}) == 0);
    }
  }

  llint sum = accumulate(ans + 1, ans + k + 1, 0LL);
  printf("%lld\n", sum);
  return 0;
}