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
  int q;
  scanf("%d", &q);
  REP(i, q) {
    llint l, r;
    scanf("%lld %lld", &l, &r);
    
    llint cur = 0;
    for (int j = 61; j >= 0; --j) {
      llint all = cur + (1LL<<(j+1)) - 1;
      if (all <= r || (all - (1LL<<j)) < l) cur += 1LL<<j;
    }
    
    printf("%lld\n", cur);
  }

  return 0;
}