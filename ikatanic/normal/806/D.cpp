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

const int MAX = 2020;
const llint inf = 1e18;

int e[MAX][MAX];
llint min_e[MAX];
llint d[MAX];
bool bio[MAX];

llint ans[MAX];
int n;

void go(int x, int y) {
  REP(i, n) {
    min_e[i] = inf;
    REP(j, n)
      if (i != j && i != x && i != y) min_e[i] = min(min_e[i], (llint)e[i][j]);
  }

  llint w = e[x][y];
  REP(i, n) d[i] = inf, bio[i] = false;

  d[x] = 0;
  while (true) {
    int a = -1;
    REP(i, n) {
      if (!bio[i] && i != y)
        if (a == -1 || d[i] < d[a]) a = i;
    }
    
    if (a == -1) break;

    bio[a] = true;
    REP(b, n) if (a != b) {
      d[b] = min(d[b], d[a] + e[a][b] - w);
      d[b] = min(d[b], d[a] + 2*(min_e[b] - w));
    }
  }

  REP(i, n) {
    ans[i] = min(ans[i], d[i] + (n-1)*w);
  }
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, n-i-1) {
      int w;
      scanf("%d", &w);
      e[i][i+j+1] = e[i+j+1][i] = w;
    }
  }
  
  int x = 0, y = 1;
  REP(i, n) REP(j, i)
    if (e[i][j] < e[x][y]) x = i, y = j;

  REP(i, n) ans[i] = inf;
  
  go(x, y);
  go(y, x);

  REP(i, n) {
    printf("%lld\n", ans[i]);
  }
  
  return 0;
}