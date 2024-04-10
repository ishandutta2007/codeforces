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

const int MAXT = 110;
const int MAXN = 1010;
const int inf = 1e9;

int f[MAXT][MAXN];
int g[MAXT][MAXN];
int c[MAXT];
vector<int> v[MAXT];

int main(void) {
  int n, T;
  scanf("%d %d", &n, &T);
  REP(i, n) {
    int t, q;
    scanf("%d %d", &t, &q);
    v[t].push_back(q);
  }

  REP(t, T+1) {
    sort(v[t].begin(), v[t].end(), greater<int>());
    c[t] = v[t].size();
    g[t][0] = 0;
    for (int i = 1; i <= c[t]; ++i)
      g[t][i] = g[t][i-1] + v[t][i-1];
  }

  REP(t, T+1) REP(j, n+1) f[t][j] = -inf;
  f[T][1] = 0;
  for (int t = T; t > 0; --t)
    for (int i = 0; i <= n; ++i) {
      if (f[t][i] <= -inf) continue;

      for (int j = 0; j <= i && j <= c[t]; ++j) {
        int ni = min(n, (i-j)*2);
        f[t-1][ni] = max(f[t-1][ni], f[t][i] + g[t][j]);
      }
    }

  int ans = 0;
  REP(j, n+1) ans = max(ans, f[0][j]);
  printf("%d\n", ans);
  return 0;
}