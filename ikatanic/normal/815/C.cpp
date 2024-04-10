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

const int MAX = 5050;
const llint inf = 1e18;

vector<int> E[MAX];

llint f[MAX][MAX];
llint g[MAX][MAX];
int sz[MAX];
int c[MAX], d[MAX];

void dfs(int x) {
  for (int y: E[x]) dfs(y);

  sz[x] = 1;
  f[x][0] = inf;
  f[x][1] = c[x] - d[x];

  g[x][0] = 0;
  g[x][1] = c[x];

  for (int y: E[x]) {
    static llint nf[MAX];
    static llint ng[MAX];

    int nsz = sz[x] + sz[y];
    REP(i, nsz+1) nf[i] = ng[i] = inf;

    REP(i, sz[x]+1) REP(j, sz[y]+1) {
      nf[i + j] = min(nf[i + j], f[x][i] + f[y][j]);
      ng[i + j] = min(ng[i + j], g[x][i] + g[y][j]);
    }
    
    REP(i, nsz+1) f[x][i] = nf[i], g[x][i] = ng[i];
    sz[x] = nsz;
  }

  REP(i, sz[x]+1) f[x][i] = min(f[x][i], g[x][i]);
}

int main(void) {
  int n, b;
  scanf("%d %d", &n, &b);
  REP(i, n) {
    scanf("%d %d", &c[i], &d[i]);
    if (i > 0) {
      int p;
      scanf("%d", &p); --p;
      E[p].push_back(i);
    }
  }
  
  dfs(0);

  int ans = 0;
  while (ans < n && f[0][ans + 1] <= b) ans++;
  printf("%d\n", ans);
  return 0;
}