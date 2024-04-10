#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int inf = 1e9;

int main(void) {
  int n, m, x, y, a, b;
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b); --x, --y;

  auto solve = [&a, &b, &n, &m] (int x, int y) {
    if (x == 0 && y == 0) return 0;
    if (x-a < 0 && x+a >= n) return inf;
    if (y-b < 0 && y+b >= m) return inf;
    if (x%a || y%b) return inf;
    x /= a, y /= b;
    if (x%2 != y%2) return inf;
    return max(x, y);
  };

  int ans = inf;
  ans = min(ans, solve(x, y));
  ans = min(ans, solve(n-x-1, y));
  ans = min(ans, solve(x, m-y-1));
  ans = min(ans, solve(n-x-1, m-y-1));
  
  if (ans >= inf) puts("Poor Inna and pony!"); else
    printf("%d\n", ans);
  return 0;
}