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

llint cube(llint x) { return x*x*x; }

llint get(llint N) {
  llint lo = 0, hi = 1000000;
  while (lo < hi) {
    llint mid = (lo + hi + 1) / 2;
    if (cube(mid) <= N) lo = mid;
    else hi = mid - 1;
  }
  return lo;
}

pair<llint, llint> best;

void rec(llint m, llint cnt, llint sum) {
  if (m == 0) {
    best = max(best, {cnt, sum});
    return;
  }
  
  llint a = get(m);
  rec(m - cube(a), cnt + 1, sum + cube(a));
  if (a > 1) {
    rec(cube(a) - 1 - cube(a-1), cnt + 1, sum + cube(a-1));
  }
}

int main(void) { 
  llint m;
  scanf("%lld", &m);
  rec(m, 0, 0);
  printf("%lld %lld\n", best.first, best.second);
  return 0;
}