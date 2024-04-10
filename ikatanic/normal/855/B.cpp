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

int main(void) {
  int n;
  llint p, q, r;
  scanf("%d %lld %lld %lld", &n, &p, &q, &r);

  llint f[3] = {p, q, r};
  
  llint best[4] = {0, 0, 0, 0};
  REP(i, n) {
    llint x;
    scanf("%lld", &x);
    if (i == 0) {
      best[1] = f[0] * x;
      best[2] = best[1] + f[1] * x;
      best[3] = best[2] + f[2] * x;
    } else {
      for (int j = 0; j < 3; ++j) {
        best[j + 1] = max(best[j + 1], best[j] + f[j] * x);
      }
    }
  }

  printf("%lld\n", best[3]);
  return 0;
}