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
  llint s, x;
  scanf("%lld %lld", &s, &x);
  
  bool zero = x == s;
  llint ans = 1;
  llint rem = 0;
  REP(i, 50)
    if (x & (1LL<<i)) {
      ans *= 2;
      s -= 1LL<<i;
    } else {
      rem |= 1LL<<(i+1);
    }
  
  if (s >= 0) {
    if ((s & rem) != s) ans = 0;
  } else {
    ans = 0;
  }

  if (ans > 0 && zero) ans -= 2;
  printf("%lld\n", ans);
  return 0;
}