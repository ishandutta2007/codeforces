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
  int x0, y0, x1, y1;
  scanf("%d %d", &x0, &y0);
  scanf("%d %d", &x1, &y1);

  int n;
  scanf("%d", &n);

  int ans = 0;
  REP(i, n) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    llint w0 = llint(a) * x0 + llint(b) * y0 + c;
    llint w1 = llint(a) * x1 + llint(b) * y1 + c;
    if ((w0 > 0) != (w1 > 0)) ans++;
  }

  printf("%d\n", ans);
  return 0;
}