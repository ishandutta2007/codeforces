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

double p[111];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%lf", p+i);

  sort(p, p + n);
  double ans = 0;

  double pone = 0, pzero = 1.0;
  for (int i = n-1; i >= 0; --i) {
    pone = pone * (1 - p[i]) + pzero * p[i];
    pzero *= (1 - p[i]);
    ans = max(ans, pone);
  }
  
  printf("%.10lf\n", ans);
  return 0;
}