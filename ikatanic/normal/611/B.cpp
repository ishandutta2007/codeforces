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

int main(void) {
  llint a, b;
  scanf("%lld %lld", &a, &b);
  llint ans = 0;
  for (int k = 2; k <= 62; ++k)
    REP(i, k-1) {
      llint x = (1LL<<k) - 1 - (1LL<<i);
      if (a <= x && x <= b) ans++;
    }
  printf("%lld\n", ans);
  return 0;
}