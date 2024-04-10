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

const int inf = 1e9;

const int MAXN = 330;
const int MAXS = 1<<10;

int l[MAXN], c[MAXN];
vector<int> p[MAXN];

int f[MAXS], nf[MAXS];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", l+i);
  REP(i, n) scanf("%d", c+i);

  REP(i, n) {
    int x = l[i];
    for (int j = 2; j*j <= x; ++j)
      if (x%j == 0) {
        while (x%j == 0) x /= j;
        p[i].push_back(j);
      }
    if (x > 1) p[i].push_back(x);
  }

  int ans = inf;
  REP(i, n) {
    int k = (int)p[i].size();
    REP(s, 1<<k) f[s] = inf;
    
    f[(1<<k) - 1] = c[i];
    FOR(j, i+1, n) {
      int mask = 0;
      REP(l, k)
        for (int pr: p[j])
          if (pr == p[i][l]) mask |= 1<<l;
      
      REP(s, 1<<k) nf[s] = inf;
      REP(s, 1<<k) {
        nf[s] = min(nf[s], f[s]);
        nf[s & mask] = min(nf[s & mask], f[s] + c[j]);
      }
      REP(s, 1<<k) f[s] = nf[s];
    }

    ans = min(ans, f[0]);
  }

  if (ans >= inf) ans = -1;

  printf("%d\n", ans);
  return 0;
}