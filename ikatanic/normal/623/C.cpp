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
const int inf = 1e9;

struct Pt {
  int x, y;
  friend bool operator < (const Pt& a, const Pt& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  }
};

Pt a[MAX];
int n;

llint sqr(llint x) { return x*x; }

bool can(llint D) {
  int minx = inf, maxx = -inf;
  int miny = inf, maxy = -inf;
  REP(i, n) {
    minx = min(minx, a[i].x);
    maxx = max(maxx, a[i].x);
    miny = min(miny, a[i].y);
    maxy = max(maxy, a[i].y);
  }

  if (sqr(maxx-minx) <= D) return true;
  if (sqr(maxy-miny) <= D) return true;

  bool ok = false;
  REP(rot, 2) {
    static int pminy[MAX], pmaxy[MAX];
    static int sminy[MAX], smaxy[MAX];

    REP(i, n) {
      pminy[i] = pmaxy[i] = a[i].y;
      if (i > 0) {
        pminy[i] = min(pminy[i], pminy[i-1]);
        pmaxy[i] = max(pmaxy[i], pmaxy[i-1]);
      }
    }

    for (int i = n-1; i >= 0; --i) {
      sminy[i] = smaxy[i] = a[i].y;
      if (i < n-1) {
        sminy[i] = min(sminy[i], sminy[i+1]);
        smaxy[i] = max(smaxy[i], smaxy[i+1]);
      }
    }

    int last = 0;
    while (last < n && a[last].x < 0) last++;
    int first = last;

    while (last < n) {
      while (first > 0 && a[first-1].x < 0 && -a[first-1].x <= a[last].x && sqr(a[last].x - a[first-1].x) <= D) first--;
      while (sqr(a[last].x - a[first].x) > D) first++;

      int miny = inf, maxy = -inf;
      if (last < n-1) {
        miny = min(miny, sminy[last+1]);
        maxy = max(maxy, smaxy[last+1]);
      }
      if (first > 0) {
        miny = min(miny, pminy[first-1]);
        maxy = max(maxy, pmaxy[first-1]);
      }

      if (sqr(maxy-miny) <= D && max(sqr(miny), sqr(maxy)) + sqr(a[last].x) <= D) ok = true;
      last++;
    }

    REP(i, n) a[i].x *= -1;
    reverse(a, a + n);
  }
  return ok;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", &a[i].x, &a[i].y);
  sort(a, a + n);

  llint lo = 0, hi = 1e18;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    if (can(mid)) hi = mid; else
      lo = mid+1;
  }
  printf("%lld\n", lo);
  return 0;
}