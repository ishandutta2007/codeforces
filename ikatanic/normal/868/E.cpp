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

const int MAX = 52;
const int inf = 1e9;

struct Edge {
  int b, w;
};

vector<Edge> E[MAX];
int parent[MAX];

void dfs(int x) {
  for (auto& e: E[x]) {
    if (e.b != parent[x]) {
      parent[e.b] = x;
      dfs(e.b);
    }
  }
}

int f[MAX][MAX];
int g[MAX][MAX];

void solve(int x, int dad, int M) {
  vector<Edge> children;
  for (auto& e: E[x]) {
    if (e.b != dad) {
      solve(e.b, x, M);
      children.push_back(e);
    }
  }

  if (children.size() == 0) {
    FOR(k, 1, M+1) f[x][k] = g[x][M - k];
    f[x][0] = inf;
    return;
  }

  static int nf[MAX];
  bool first = true;
  
  for (auto& e: children) {
    int y = e.b;

    if (first) {
      REP(k, M+1) f[x][k] = e.w + f[y][k];
      first = false;
    } else {
      REP(k, M+1) nf[k] = 0;
      for (int k = 0; k <= M; ++k) {
        for (int l = 0; k + l <= M; ++l) {
          nf[k + l] = max(nf[k + l], min(f[x][k], e.w + f[y][l]));
        }
      }
      REP(k, M+1) f[x][k] = nf[k];
    }
  }
  f[x][0] = inf;
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N-1) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    --a, --b;
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  
  int s;
  scanf("%d", &s); --s;

  parent[s] = -1;
  dfs(s);
  
  vector<int> v(E[s].size());
  int M;
  scanf("%d", &M);
  REP(i, M) {
    int x;
    scanf("%d", &x); --x;
    while (parent[x] != s) x = parent[x];

    int idx = -1;
    REP(j, (int)E[s].size()) {
      if (E[s][j].b == x) idx = j;
    }
    assert(idx != -1);
    v[idx]++;
  }

  
  for (int m = 1; m < M; ++m) {
    REP(x, N) {
      solve(x, -1, m);
      g[x][m] = f[x][m];
    }
  }

  solve(s, -1, M);
  int ret = 1e9;
  REP(i, (int)E[s].size()) {
    ret = min(ret, E[s][i].w + f[E[s][i].b][v[i]]);
  }
  printf("%d\n", ret);
  return 0;
}