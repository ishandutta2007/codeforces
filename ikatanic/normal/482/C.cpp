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

char a[55][22];
int x[55][22];

double f[1<<20];
llint bm[1<<20];
llint p[22][55];
int bad_cnt[1<<20];
int lb[1<<20];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%s", a[i]);
  int m = strlen(a[0]);

  REP(i, n) REP(j, m) {
    if (islower(a[i][j])) x[i][j] = a[i][j] - 'a'; else
      x[i][j] = a[i][j] - 'A' + 26;
    p[j][x[i][j]] |= 1LL<<i;
  }

  REP(s, 1<<m) REP(i, m)
    if (s&(1<<i)) lb[s] = i;

  REP(i, n) {
    REP(s, 1<<m) bm[s] = 0;
    bm[0] = (1LL<<n) - 1;
    FOR(s, 1, 1<<m)
      bm[s] = p[lb[s]][x[i][lb[s]]] & bm[s ^ (1<<lb[s])];
    REP(s, 1<<m)
      if (bm[s] != (1LL<<i)) bad_cnt[s]++;
  }
  
  
  for (int s = (1<<m)-1; s >= 0; --s) {
    int cnt = 0;
    REP(i, m)
      if (!(s&(1<<i))) {
        f[s] += f[s^(1<<i)];
        cnt++;
      }
    
    if (cnt > 0 && bad_cnt[s]) {
      f[s] = double(bad_cnt[s])/n + (f[s] / double(cnt));
    }
  }

  printf("%.9lf\n", f[0]);
  return 0;
}