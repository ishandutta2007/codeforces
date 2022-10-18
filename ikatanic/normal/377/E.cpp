#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

typedef pair<int, int> building;
#define c first
#define v second

typedef pair<llint, llint> line;
#define k first
#define l second

const int MAXN = 200200;

building a[MAXN];
line p[MAXN];

int m;

int ccw(line a, line b, line c) {
  llint w = llint(a.k)*(b.l-c.l) + llint(b.k)*(c.l-a.l) + llint(c.k)*(a.l-b.l);
  return w < 0 ? -1 : w > 0;
}

llint eval(int i, llint x) {
  return llint(x)*p[i].k + p[i].l;
}

llint getY(llint x) {
  int lo = 0, hi = m-1;
  while (lo < hi) {
    int mid = (lo + hi)/2;
    if (eval(mid, x) < eval(mid+1, x)) lo = mid+1; else
      hi = mid;
  }
  return eval(lo, x);
}

llint getX(llint y) {
  if (y == 0) return 0;

  llint lo = 0, hi = ((y-p[m-1].l)/p[m-1].k) + 1;
  while (lo < hi) {
    llint mid = (lo + hi)/2;
    if (getY(mid) < y) lo = mid+1; else
      hi = mid;
  }
  return lo;
}

int main(void)
{
  int n;
  llint s;
  scanf("%d %I64d", &n, &s);
  REP(i, n) scanf("%d %d", &a[i].v, &a[i].c);
  
  sort(a, a + n); 
  m = 0;
  REP(i, n) {
    if (m > 0 && a[m-1].c < a[i].c && a[i].v <= a[m-1].v) continue;
    if (i+1 < n && a[i].c == a[i+1].c) continue;
    a[m++] = a[i];
  }
  n = m;
  
  m = 0;
  p[m++] = make_pair(0, 0);

  REP(i, n) {
    int x = getX(a[i].c);
    int y = getY(x);

    line b = make_pair(a[i].v, y-a[i].c - llint(x)*a[i].v);
    while (m > 1 && ccw(p[m-2], p[m-1], b) >= 0) m--;
    p[m++] = b;
  }
  
  llint ans = getX(s);
  printf("%I64d\n", ans);
  return 0;
}