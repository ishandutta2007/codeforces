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
typedef pair<int, int> point;

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);

  vector<point> v, w;
  REP(x, 1010) REP(y, 1010) {
    if (x == 0 || y == 0) continue;
    if (x*x+y*y == a*a) v.push_back({x, y});
    if (x*x+y*y == b*b) w.push_back({-x, y});
  }

  for (point p: v)
    for (point r: w) {
      int dx = (p.first-r.first)*(p.first-r.first);
      int dy = (p.second-r.second)*(p.second-r.second);
      if (dx == 0 || dy == 0) continue;
      if (dx+dy == a*a+b*b) {
        puts("YES");
        printf("0 0\n%d %d\n%d %d\n", p.first, p.second, r.first, r.second);
        return 0;
      }
    }

  puts("NO");
  return 0;
}