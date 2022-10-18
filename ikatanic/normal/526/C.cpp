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
  int C, h1, h2, w1, w2;
  scanf("%d %d %d %d %d", &C, &h1, &h2, &w1, &w2);

  llint ans = 0;
  
  REP(rot, 2) {
    for (llint k = 0; k <= 10000000 && k*w1 <= C; ++k)
      ans = max(ans, llint(k)*h1 + ((C-k*w1)/w2)*llint(h2));
    swap(h1, h2);
    swap(w1, w2);
  }
  printf("%lld\n", ans);
  return 0;
}