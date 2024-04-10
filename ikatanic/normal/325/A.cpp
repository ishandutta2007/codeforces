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

const int inf = 1e9;

int main(void) {
  int n;
  scanf("%d", &n);
  
  int x1 = inf, x2 = -inf;
  int y1 = inf, y2 = -inf;
  llint area = 0;
  REP(i, n) {
    int X1, Y1, X2, Y2;
    scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
    x1 = min(x1, X1);
    x2 = max(x2, X2);
    y1 = min(y1, Y1);
    y2 = max(y2, Y2);
    area += llint(X2-X1)*(Y2-Y1);
  }

  if (x2-x1 == y2-y1 && area == llint(x2-x1)*(x2-x1)) puts("YES"); else
    puts("NO");
  return 0;
}