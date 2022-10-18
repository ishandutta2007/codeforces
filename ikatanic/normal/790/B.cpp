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

const int MAX = 200020;

vector<int> E[MAX];
llint ans;

vector<llint> f[MAX];
llint g[MAX];
llint cnt[MAX];

void dfs(int x, int dad, int k) {
  f[x] = vector<llint>(k, 0);
  f[x][0] = 1;
  g[x] = 0;
  cnt[x] = 1;

  for (int y: E[x]) {
    if (y == dad) continue;
    
    dfs(y, x, k);

    ans += cnt[x] * g[y] + cnt[y] * g[x];
    REP(i, k) REP(j, k) {
      ans += f[x][i] * f[y][j] * ((i + j + k-1) / k);
    }
    cnt[x] += cnt[y];
    g[x] += g[y];
    REP(i, k) f[x][i] += f[y][i];
  }

  g[x] += f[x][k-1];
  rotate(f[x].begin(), f[x].begin() + k-1, f[x].end());
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1, k);
  printf("%lld\n", ans);
  return 0;
}