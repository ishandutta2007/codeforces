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

const int MAX = 5050;
const int M = 6;
const int H = 90;

int lo[M], hi[M];
int pts[M];
int a[MAX][3];
int cur[MAX];
int cnt[3];
bool can[MAX][3];

int ac[3];

int main(void) {
  int n;
  scanf("%d", &n);

  for (int m = M-1; m >= 0; --m) {
    hi[m] = n >> m;
    lo[m] = m+1 == M ? 0 : hi[m+1] + 1;
    pts[m] = (m + 1) * 500;
  }
  
  REP(i, n) {
    REP(j, 3) {
      scanf("%d", &a[i][j]);
      if (a[i][j] < 0) {
        a[i][j] *= -1;
        can[i][j] = true;
        cnt[j]++;
      }
      if (a[i][j]) ac[j]++;
    }
  }

  if (cnt[0] + cnt[1] + cnt[2] >= H) {
    puts("1");
    return 0;
  }

  int ans = n;
  REP(x1, M) REP(x2, M) REP(x3, M) {
    int x[3] = {x1, x2, x3};
    int g[3];

    bool ok = true;
    REP(j, 3) {
      if (lo[x[j]] > hi[x[j]]) ok = false;
      if (lo[x[j]] > ac[j]) ok = false;
      g[j] = min(ac[j] - lo[x[j]], cnt[j]);
      if (hi[x[j]] < ac[j] - g[j]) ok = false;
    }

    if (!ok) continue;

    int h = g[0] + g[1] + g[2];

    static int f[H][H][H];
    static int nf[H][H][H];
    const int inf = 1e9;

    REP(g0, g[0]+1) REP(g1, g[1]+1) REP(g2, g[2]+1) f[g0][g1][g2] = inf;
    f[0][0][0] = 0;

    int off = 0;
    REP(i, n) {
      cur[i] = 0;
      REP(j, 3)
        if (a[i][j]) cur[i] += pts[x[j]] * (250 - a[i][j]);
    }
    cur[0] += h * 250 * 100;

    FOR(i, 1, n) {
      if (can[i][0] || can[i][1] || can[i][2]) {
        REP(g0, g[0]+1) REP(g1, g[1]+1) REP(g2, g[2]+1) nf[g0][g1][g2] = inf;
        REP(s, 1<<3) {
          bool ok = true;
          int nscore = cur[i];
          REP(j, 3)
            if (s & (1<<j)) {
              if (!can[i][j]) ok = false;
              nscore -= pts[x[j]] * (250 - a[i][j]);
            }
          if (!ok) continue;
          REP(g0, g[0]+1) REP(g1, g[1]+1) REP(g2, g[2]+1) {
            if (f[g0][g1][g2] == inf) continue;
            int ng0 = g0 + (s&1);
            int ng1 = g1 + ((s>>1)&1);
            int ng2 = g2 + ((s>>2)&1);
            if (ng0 <= g[0] && ng1 <= g[1] && ng2 <= g[2]) {
              nf[ng0][ng1][ng2] = min(nf[ng0][ng1][ng2], f[g0][g1][g2] + (nscore > cur[0]));
            }
          }
        }
        REP(g0, g[0]+1) REP(g1, g[1]+1) REP(g2, g[2]+1) f[g0][g1][g2] = nf[g0][g1][g2];
      } else {
        if (cur[0] < cur[i]) off++;
      }
    }

    ans = min(ans, off + f[g[0]][g[1]][g[2]]);
  }

  printf("%d\n", ans+1);
  return 0;
}