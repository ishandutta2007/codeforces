#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> point;
#define x first
#define y second

const int MAXN = 100100;
const int inf = 1e9;

point p[MAXN];

bool test(point a, point b) {
  return a.x <= b.y && b.x <= a.y;
}

void solve(point *p, int m, int n, set<point> &S) {
  S.clear();
  if (m > 0 && p[0].x == 0 && p[0].y == 0) return;
  S.insert({0, 0});
  
  int lastSum = 0, off = 0;
  REP(i, m) {
    int sum = p[i].x+p[i].y;
    off += sum-lastSum;

    int lo = inf, hi = -inf;
    while (true) {
      auto it = S.upper_bound({p[i].x, inf});
      if (it == S.begin()) break; --it;
      if (it->y+off < p[i].x) break;
      lo = min(lo, it->x);
      hi = max(hi, min(n-1, it->y+off));
      S.erase(it);
    }
      
    if (lo != inf) {
      if (lo < p[i].x) S.insert({lo, p[i].x-1-off});
      if (p[i].x < hi) S.insert({p[i].x+1, hi-off});
    }

    lastSum = sum;
    if (!S.size()) return;
  }
  off += n-1-lastSum;

  static set<point> tmpS;
  tmpS = S;
  S.clear();

  point last = {-1, -1};
  for (point p: tmpS) {
    point now = {p.x, min(n-1, p.y+off)};
    if (now.x > now.y) continue;
    if (test(last, now)) S.erase(last), now.x = last.x;
    S.insert(now);
    last = now;
  }
  
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    p[i] = {x, y};
  }

  sort(p, p + m, [] (const point &a, const point &b) {
      if (a.x+a.y != b.x+b.y) return a.x+a.y < b.x+b.y;
      return a.x < b.x;
    }
  );

  int lo = 0;
  while (lo < m && p[lo].x+p[lo].y < n-1) lo++;
  int hi = lo;
  while (hi < m && p[hi].x+p[hi].y == n-1) hi++;

  static set<point> U, D;
  solve(p, hi, n, U);
  
  for (int i = lo; i < m; ++i)
    p[i] = {n-1-p[i].x, n-1-p[i].y};
  reverse(p + lo, p + m);
  
  solve(p+lo, m-lo, n, D);

  bool ok = false;
  for (point p: D) {
    point r = {n-1-p.y, n-1-p.x};
    auto it = U.lower_bound(point(r.x, inf));
    if (it != U.end() && test(r, *it)) ok = true;
    if (it != U.begin() && test(r, *(--it))) ok = true;
  }
  
  if (ok) printf("%d\n", 2*n-2); else
    printf("-1\n");
  return 0;
}