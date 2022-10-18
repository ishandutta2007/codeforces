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

const int MAX = 88;
const int inf = 1e9;

int e[MAX][MAX];
int f[MAX][MAX][MAX];
int nf[MAX][MAX][MAX];

int main(void) {
  int n, K;
  scanf("%d %d", &n, &K);
  n += 2;
  REP(i, n) REP(j, n) e[i][j] = inf;
  int m;
  scanf("%d", &m);
  REP(i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    e[a][b] = min(e[a][b], c);
  }

  REP(k, n) REP(j, k) REP(i, j) f[i][j][k] = inf;
  FOR(i, 1, n-1) f[0][i][n-1] = 0;

  REP(it, K-1) {
    REP(k, n) REP(j, k) REP(i, j) nf[i][j][k] = inf;

    REP(k, n) REP(j, k) REP(i, j) {
      if (f[i][j][k] < inf) {
        FOR(l, i+1, j) nf[i][l][j] = min(nf[i][l][j], f[i][j][k] + e[j][l]);
        FOR(l, j+1, k) nf[j][l][k] = min(nf[j][l][k], f[i][j][k] + e[j][l]);
      }
    }
    
    REP(k, n) REP(j, k) REP(i, j) f[i][j][k] = nf[i][j][k];
  }

  int ans = inf;
  REP(k, n) REP(j, k) REP(i, j) ans = min(ans, f[i][j][k]);
  if (ans == inf) {
    puts("-1");
  } else {
    printf("%d\n", ans);
  }
  return 0;
}