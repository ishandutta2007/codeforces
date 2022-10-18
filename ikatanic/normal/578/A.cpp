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

const double inf = 1e100;

int main(void) {
  llint a, b;
  scanf("%lld %lld", &a, &b);

  double ans = inf;
 
  if (a == b) {
    ans = a;
  }
  if (a > b) {
    llint k = (a - b) / (2*b);
    if (k > 0) ans = min(ans, double(a - b) / (2*k));
  }
  llint k = (a + b) / (2*b);
  if (k > 0) ans = min(ans, double(a + b) / (2*k));

  if (ans == inf) puts("-1"); else
    printf("%.10lf\n", ans);
  return 0;
}