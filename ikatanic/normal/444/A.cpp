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

int v[505];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", v+i);
  double ans = 0;
  REP(i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b;
    ans = max(ans, (v[a] + v[b]) / double(c));
  }

  printf("%.10lf\n", ans);
  return 0;
}