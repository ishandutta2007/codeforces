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
  int n, k;
  scanf("%d %d", &n, &k);

  int ans = 0;
  REP(i, k) {
    int m, x, cnt = 0;
    scanf("%d", &m);
    REP(j, m) {
      scanf("%d", &x); --x;
      if (x == j && cnt == j) cnt++;
    }

    if (cnt == 0) ans += m-1 + m; else
      ans += m-cnt + m-cnt;
  }

  printf("%d\n", ans);
  return 0;
}