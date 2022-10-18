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

const int MAX = 110;

pair<int, int> a[MAX][MAX];
int ans[MAX][MAX];

int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  REP(i, n) REP(j, m) a[i][j] = {i, j};
  REP(i, q) {
    int t;
    scanf("%d", &t);
    
    if (t == 1) {
      int r;
      scanf("%d", &r); --r;
      rotate(a[r], a[r] + 1, a[r] + m);
    }

    if (t == 2) {
      int c;
      scanf("%d", &c); --c;
      auto tmp = a[0][c];
      REP(j, n-1) a[j][c] = a[j + 1][c];
      a[n-1][c] = tmp;
    }

    if (t == 3) {
      int r, c, x;
      scanf("%d %d %d", &r, &c, &x); --r, --c;
      ans[a[r][c].first][a[r][c].second] = x;
    }
  }

  REP(i, n) {
    REP(j, m) printf("%d ", ans[i][j]);
    putchar('\n');
  }
  return 0;
}