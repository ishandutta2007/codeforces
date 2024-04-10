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

const int MAX = 100100;
const int inf = 1e9;

char s[MAX];
int f[MAX][2][3];

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  REP(i, n) s[i] -= '0';

  REP(i, n+1) REP(j, 2) REP(k, 3) f[i][j][k] = -inf;
  f[0][0][0] = f[0][1][0] = 0;
  REP(i, n+1) REP(j, 2) REP(k, 3) {
    if (k+1 < 3) f[i][j][k+1] = max(f[i][j][k+1], f[i][j][k]);
    f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k]);
    if (j == (s[i] ^ (k == 1))) f[i+1][j^1][k] = max(f[i+1][j^1][k], f[i][j][k] + 1);
  }

  int ans = max(f[n][0][2], f[n][1][2]);
  printf("%d\n", ans);
  return 0;
}