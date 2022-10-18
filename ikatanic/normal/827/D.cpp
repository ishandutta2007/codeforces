#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 201000;
const int LG = 20;
const int inf = 1e9 + 100;

struct Edge {
  int a, b, w, i;
  friend bool operator < (const Edge& a, const Edge& b) {
    return a.w < b.w;
  }
};

int dad[MAX];

Edge parentEdge[MAX];
int parent[MAX];
int depth[MAX];

int L[MAX][LG];
int Lm[MAX][LG];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

vector<Edge> e[MAX];

void dfs(int x) {
  for (auto& edge: e[x]) {
    int y = edge.b;
    if (y != parent[x]) {
      parentEdge[y] = edge;
      depth[y] = depth[x] + 1;
      parent[y] = x;
      dfs(y);
    }
  }
}

pair<int, int> lca(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int maxEdge = 0;
  for (int j = LG-1; j >= 0; --j) {
    if (depth[x] - (1<<j) >= depth[y]) {
      maxEdge = max(maxEdge, Lm[x][j]);
      x = L[x][j];
    }
  }
  if (x == y) return {x, maxEdge};

  for (int j = LG-1; j >= 0; --j) {
    if (L[x][j] != L[y][j]) {
      maxEdge = max(maxEdge, max(Lm[x][j], Lm[y][j]));
      x = L[x][j];
      y = L[y][j];
    }
  }

  maxEdge = max(maxEdge, max(Lm[x][0], Lm[y][0]));
  x = L[x][0];
  y = L[y][0];
  return {x, maxEdge};
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<Edge> E;
  REP(i, m) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    --a, --b;
    E.push_back({a, b, w, i});
  }

  sort(E.begin(), E.end());
  REP(i, n) dad[i] = i;

  vector<Edge> tree, nonTree;
  REP(i, m) {
    if (findset(E[i].a) != findset(E[i].b)) {
      dad[findset(E[i].a)] = findset(E[i].b);
      tree.push_back(E[i]);
      e[E[i].a].push_back(E[i]);
      e[E[i].b].push_back({E[i].b, E[i].a, E[i].w, E[i].i});
    } else {
      nonTree.push_back(E[i]);
    }
  }

  parent[0] = 0;
  dfs(0);

  REP(i, n) {
    L[i][0] = parent[i];
    Lm[i][0] = i == 0 ? 0 : parentEdge[i].w;
  }

  FOR(j, 1, LG) REP(i, n) {
    L[i][j] = L[ L[i][j-1] ][j-1];
    Lm[i][j] = max(Lm[i][j-1], Lm[ L[i][j-1] ][j-1]);
  }

  vector<int> ans(m, inf);
  REP(i, n) dad[i] = i;

  auto update = [&] (int x, int z, int w) {
    x = findset(x);
    while (depth[x] > depth[z]) {
      ans[parentEdge[x].i] = w;
      dad[x] = findset(parent[x]);
      x = dad[x];
    }
  };
  
  for (auto& e: nonTree) {
    auto p = lca(e.a, e.b);
    ans[e.i] = p.second - 1;

    update(e.a, p.first, e.w - 1);
    update(e.b, p.first, e.w - 1);
  }

  REP(i, m) {
    printf("%d ", ans[i] == inf ? -1 : ans[i]);
  }
  printf("\n");
  return 0;
}