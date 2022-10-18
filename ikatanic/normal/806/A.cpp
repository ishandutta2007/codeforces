#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint solve(llint x, llint y, llint p, llint q) {
  if (p*y == q*x) return 0;
  if (p == q) return -1;

  llint c = (y-x + q-p-1) / (q-p);

  if (p == 0) {
    if (x > 0) return -1;
  } else {
    c = max(c, (x+p-1)/p);
  }
  return c*q - y;
}
  
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    llint x, y, p, q;
    scanf("%lld %lld %lld %lld", &x, &y, &p, &q);

    printf("%lld\n", solve(x, y, p, q));
  }
  return 0;
}