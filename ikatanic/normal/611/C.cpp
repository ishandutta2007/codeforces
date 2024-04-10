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

const int MAX = 505;

char a[MAX][MAX];
int sr[MAX][MAX], sd[MAX][MAX];
int n, m;

void pre(int s[MAX][MAX]) {
  REP(i, n) REP(j, m) {
    if (i > 0) s[i][j] += s[i-1][j];
    if (j > 0) s[i][j] += s[i][j-1];
    if (i > 0 && j > 0) s[i][j] -= s[i-1][j-1];
  }
}

int sum(int s[MAX][MAX], int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  int ans = s[x2][y2];
  if (x1 > 0) ans -= s[x1-1][y2];
  if (y1 > 0) ans -= s[x2][y1-1];
  if (x1 > 0 && y1 > 0) ans += s[x1-1][y1-1];
  return ans;
}
  
int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  
  REP(i, n) REP(j, m) {
    sr[i][j] = (j+1 < m && a[i][j] == '.' && a[i][j+1] == '.');
    sd[i][j] = (i+1 < n && a[i][j] == '.' && a[i+1][j] == '.');
  }

  pre(sr);
  pre(sd);

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    --r1, --c1, --r2, --c2;
    printf("%d\n", sum(sr, r1, c1, r2, c2-1) + sum(sd, r1, c1, r2-1, c2));
  }
  return 0;
}