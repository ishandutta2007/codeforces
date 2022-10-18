#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef unsigned long long ullint;

int main(void) {
  // 1bcde = n+1 znamenki
  // f(1bcde) = f(bcde) + bcde + 1 + n*45*10^(n-1)
  // bcde + 1 + n*45*10^(n-1) = 0 (mod a)
  ullint a;
  scanf("%llu", &a);

  ullint w = 45*19;
  REP(i, 18) w = (w*10)%a;
  w = (w + 1)%a;
  w = (a - w)%a;

  printf("%lld 1%019lld\n", w+1, w);
  return 0;
}