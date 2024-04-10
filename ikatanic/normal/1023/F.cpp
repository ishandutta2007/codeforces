#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 500500;
const int LG = 21;

struct UnionFind {
  vector<int> p;

  UnionFind(int n) : p(vector<int>(n, 0)) { REP(i, n) p[i] = i; }

  int findset(int x) { return x == p[x] ? x : p[x] = findset(p[x]); }

  void merge(int x, int y) { p[findset(x)] = findset(y); }
};

vector<pair<int, int>> E[MAX];
int parent[MAX], parent_eid[MAX], depth[MAX];

void dfs(int x) {
  for (auto& e : E[x]) {
    int y = e.first;
    if (y != parent[x]) {
      parent[y] = x;
      parent_eid[y] = e.second;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
  }
}

int L[MAX][LG];

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int j = LG - 1; j >= 0; --j)
    if (depth[u] - (1 << j) >= depth[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG - 1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int nxt[MAX];

int mark(int x, int p, int c, vector<int>& lim) {
  if (x != nxt[x]) return nxt[x] = mark(nxt[x], p, c, lim);
  if (depth[x] <= depth[p]) return x;

  int i = parent_eid[x];
  if (i >= 0 && i < (int)lim.size()) lim[i] = c;
  return nxt[x] = mark(parent[x], p, c, lim);
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;

  UnionFind uf(N);

  vector<pair<int, int>> tree;
  REP(i, K) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.merge(a, b);
    tree.push_back({a, b});
  }

  struct Constraint {
    int a, b, w;
  };

  vector<Constraint> constraints;
  REP(i, M) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;

    if (uf.findset(a) == uf.findset(b)) {
      constraints.push_back({a, b, w});
    } else {
      uf.merge(a, b);
      tree.push_back({a, b});
    }
  }

  assert((int)tree.size() == N - 1);
  REP(i, N - 1) {
    E[tree[i].first].push_back({tree[i].second, i});
    E[tree[i].second].push_back({tree[i].first, i});
  }

  parent[0] = 0;
  depth[0] = 0;
  parent_eid[0] = -1;
  dfs(0);

  REP(i, N) L[i][0] = parent[i];
  FOR(j, 1, LG) REP(i, N) L[i][j] = L[L[i][j - 1]][j - 1];

  REP(i, N) nxt[i] = i;

  vector<int> lim(K, -1);

  for (auto& c : constraints) {
    int x = lca(c.a, c.b);
    mark(c.a, x, c.w, lim);
    mark(c.b, x, c.w, lim);
  }

  llint total = 0;
  REP(i, K) {
    if (lim[i] == -1) {
      total = -1;
      break;
    } else {
      total += lim[i];
    }
  }

  cout << total << "\n";
  return 0;
}