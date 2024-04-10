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

struct Pt {
  int x, y;
};

int ccw(const Pt& a, const Pt& b, const Pt& c) {
  llint w = 0;
  w += llint(a.x) * (b.y - c.y);
  w += llint(b.x) * (c.y - a.y);
  w += llint(c.x) * (a.y - b.y);
  return w < 0 ? -1 : w > 0;
}

llint dist(const Pt& a, const Pt& b) {
  llint dx = a.x - b.x;
  llint dy = a.y - b.y;
  return dx*dx + dy*dy;
}

bool inside(const Pt& p, vector<Pt>& h) {
  int lo = 1, hi = (int)h.size() - 2;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ccw(h[0], h[mid], p) < 0) hi = mid - 1; else
      lo = mid;
  }

  if (ccw(h[lo], h[lo+1], p) == 0) return false;
  if (ccw(h[0], h[lo], p) == 0 && lo == 1) return false;
  if (ccw(h[lo+1], h[0], p) == 0 && lo+1 == (int)h.size()-1) return false;

  return
    ccw(h[0], h[lo], p) >= 0 &&
    ccw(h[lo], h[lo+1], p) >= 0 &&
    ccw(h[lo+1], h[0], p) >= 0;
}

int main(void) {
  int n, m;
  vector<Pt> a, b;
  scanf("%d %d", &n, &m);
  int sx, sy;
  scanf("%d %d", &sx, &sy);
  REP(i, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    b.push_back({x, y});
  }

  int mx = 0, my = 0;
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    a.push_back({x, y});
    mx = max(mx, x);
    my = max(my, y);
  }
  a.insert(a.begin(), {0, 0});
  a.push_back({0, my});
  a.push_back({mx, 0});

  sort(a.begin() + 1, a.end(), [&a] (const Pt& A, const Pt& B) {
      int c = ccw(a[0], A, B);
      if (c) return c > 0;
      return dist(a[0], A) < dist(a[0], B);
    }
  );
  
  vector<Pt> h;
  for (auto& p: a) {
    while (h.size() >= 2 && ccw(h[h.size()-2], h.back(), p) <= 0) h.pop_back();
    h.push_back(p);
  }
  assert(h[0].x == 0 && h[0].y == 0);

  for (auto& p: b)
    if (!inside(p, h)) {
      puts("Max");
      return 0;
    }

  puts("Min");
  return 0;
}