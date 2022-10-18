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

const int MAXN = 200020;
const llint inf = 1e18;

vector<int> E[MAXN];
llint f[MAXN][2];
llint g[2], ng[2];
int p[MAXN], a[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d", p+i, a+i);
    if (p[i] != -1) E[--p[i]].push_back(i);
  }

  for (int x = n-1; x >= 0; --x) {
    g[0] = 0, g[1] = -inf;
    for (int y: E[x]) {
      REP(c, 2) ng[c] = -inf;
      REP(c, 2) REP(cy, 2) ng[c^cy] = max(ng[c^cy], g[c] + f[y][cy]);
      REP(c, 2) g[c] = ng[c];
    }
    
    g[1] = max(g[1], a[x] + g[0]);
    REP(c, 2) f[x][c] = g[c];
  }

  printf("%lld\n", max(f[0][0], f[0][1]));
  return 0;
}