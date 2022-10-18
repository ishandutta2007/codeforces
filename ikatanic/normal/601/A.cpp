#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 404;
const int inf = 1e9;

int e[MAX][MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    e[a][b] = e[b][a] = 1;
  }
  
  if (e[0][n-1]) {
    REP(i, n) REP(j, n) e[i][j] ^= 1;
  }
  REP(i, n) e[i][i] = 1;
  REP(i, n) REP(j, n)
    if (!e[i][j]) e[i][j] = inf;

  REP(k, n) REP(i, n) REP(j, n)
    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);

  if (e[0][n-1] >= inf) {
    puts("-1");
  } else {
    printf("%d\n", e[0][n-1]);
  }
  return 0;
}