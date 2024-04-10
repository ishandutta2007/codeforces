#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1010;

int f1[MAXN][MAXN];
int g1[MAXN][MAXN];
int f2[MAXN][MAXN];
int g2[MAXN][MAXN];

int a[MAXN][MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", a[i]+j);

  f1[0][0] = a[0][0];
  REP(i, n) REP(j, m) {
    f1[i+1][j] = max(f1[i+1][j], f1[i][j] + a[i+1][j]);
    f1[i][j+1] = max(f1[i][j+1], f1[i][j] + a[i][j+1]);
  }
  f2[n-1][m-1] = a[n-1][m-1];
  for (int i = n-1; i >= 0; --i)
    for (int j = m-1; j >= 0; --j) {
      if (i > 0) f2[i-1][j] = max(f2[i-1][j], f2[i][j] + a[i-1][j]);
      if (j > 0) f2[i][j-1] = max(f2[i][j-1], f2[i][j] + a[i][j-1]);
    }

  g1[n-1][0] = a[n-1][0];
  for (int i = n-1; i >= 0; --i) 
    REP(j, m) {
      if (i > 0) g1[i-1][j] = max(g1[i-1][j], g1[i][j] + a[i-1][j]);
      g1[i][j+1] = max(g1[i][j+1], g1[i][j] + a[i][j+1]);
    }
  g2[0][m-1] = a[0][m-1];
  REP(i, n)
    for (int j = m-1; j >= 0; --j) {
      g2[i+1][j] = max(g2[i+1][j], g2[i][j] + a[i+1][j]);
      if (j > 0) g2[i][j-1] = max(g2[i][j-1], g2[i][j] + a[i][j-1]);
    }

  int ans = 0;
  for (int i = 1; i+1 < n; ++i)
    for (int j = 1; j+1 < m; ++j) {
      ans = max(ans, f1[i][j-1] + g1[i+1][j] + f2[i][j+1] + g2[i-1][j]);
      ans = max(ans, g1[i][j-1] + f1[i-1][j] + g2[i][j+1] + f2[i+1][j]);
    }

  printf("%d\n", ans);
  return 0;
}