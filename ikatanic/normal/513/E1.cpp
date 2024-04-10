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

const int MAXN = 30030;
const int MAXK = 220;
const int inf = 1e9;

int f[MAXN][MAXK][2][5];
int best[MAXK][2][5];
int a[MAXN];
int s[MAXN];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);
  
  s[0] = 0;
  REP(i, n) s[i+1] = s[i] + a[i];

  REP(i, n+1) REP(j, k+1) REP(p, 2) REP(ps, 5) f[i][j][p][ps] = -inf;
  REP(j, k+1) REP(p, 2) REP(ps, 5) best[j][p][ps] = -inf;

  REP(p, 2) REP(ps, 5) {
    f[n][0][p][ps] = (ps - 2) * s[n];
    best[0][p][ps] = f[n][0][p][ps];
  }

  for (int i = n-1; i >= 0; --i)
    for (int j = k; j >= 0; --j) {
      int fp = -inf, fn = -inf;
      REP(ps, 5) {
        fp = max(fp, f[i+1][j][0][ps] - (ps - 2) * s[i+1]);
        fn = max(fn, f[i+1][j][1][ps] - (ps - 2) * s[i+1]);
      }
      
      if (j > 0) {
        bool first = j == k;
        bool last = j == 1;
        
        fp = max(fp, !last*-s[i] + best[j-1][1][2 + !last + !first] + !first * -s[i]);
        fn = max(fn, !last*-s[i] + best[j-1][1][2 + !last - !first] - !first * -s[i]);
        fp = max(fp, !last*s[i] + best[j-1][0][2 - !last + !first] + !first * -s[i]);
        fn = max(fn, !last*s[i] + best[j-1][0][2 - !last - !first] - !first * -s[i]);
      }
      
      REP(ps, 5) {
        f[i][j][0][ps] = fp + (ps - 2) * s[i];
        f[i][j][1][ps] = fn + (ps - 2) * s[i];
      }
      
      REP(p, 2) REP(ps, 5)
        best[j][p][ps] = max(best[j][p][ps], f[i][j][p][ps]);
    }
  
  printf("%d\n", f[0][k][0][2]);
  return 0;
}