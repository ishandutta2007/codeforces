#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);

  llint ans = 0;
  vector<llint> V;
  REP(i, n) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a <= d && b <= c) continue;
    ans += a + c;

    llint x = a + b;
    llint y = c + d;

    if (x <= y) {
      if (a > d) ans -= y;
      else ans -= x;
    } else {
      V.push_back(x);
      V.push_back(y);
    }
  }
  
  sort(V.begin(), V.end(), greater<llint>());
  for (int i = 1; i < (int)V.size(); i += 2) {
    ans -= V[i];
  }

  printf("%lld\n", ans);
  return 0;
}