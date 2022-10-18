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

const int MAXN = 110;
const int MAXK = 220;

double f[MAXK][MAXN][MAXN];
double g[MAXN][MAXN];
int a[MAXN];

inline int rev(int l, int r, int x) {
  if (x < l || x > r) return x;
  return r - (x-l);
}

int main(void) {
  int n, k;

  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);

  double prob = 1.0 / (n*(n+1)/2);
  
  REP(x, n) REP(y, n)
    if (a[x] < a[y]) f[0][x][y] = 1;

  REP(i, k) REP(a, n) REP(b, n) {
    if (a == b) continue;
    
    double np = f[i][a][b] * prob;
    REP(l, n) FOR(r, l, n) {
      int na = rev(l, r, a);
      int nb = rev(l, r, b);
      f[i+1][na][nb] += np;
    }
  }
  
  double ans = 0;
  REP(a, n) REP(b, a)
    ans += f[k][a][b];
  printf("%.12lf\n", ans);
  return 0;
}