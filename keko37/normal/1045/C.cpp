#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;
const int MAXM = 5e5 + 10;
const int MAXQ = 2e5 + 10;

int N, M, Q, block_size, cut_size;
int disc[MAXN], low[MAXN], parent[MAXN], label[2*MAXN];
int dad[22][2*MAXN], lvl[2*MAXN];

stack<pair<int, int>> S;

vector<int> v[MAXN], bc[2*MAXN];
set<int> c[MAXN]; // components of node

void dfs(int node) {
  static int t = 0;
  int ch = 0;

  disc[node] = low[node] = ++t;

  for (int nxt : v[node]) {
    if (disc[nxt] != 0 && nxt != parent[node]) {
      low[node] = min(low[node], disc[nxt]);
      if (disc[nxt] < disc[node])
        S.push({node, nxt});
    }

    if (disc[nxt] == 0) {
      ++ch;
      parent[nxt] = node;
      S.push({node, nxt});
      dfs(nxt);
      low[node] = min(low[node], low[nxt]);

      if ((disc[node] > 1 && low[nxt] >= disc[node]) ||
          (disc[node] == 1 && ch > 1)) {
        while (S.top().first != node || S.top().second != nxt) {
          c[S.top().first].insert(block_size);
          c[S.top().second].insert(block_size);
          S.pop();
        }
        assert(!S.empty());
        c[S.top().first].insert(block_size);
        c[S.top().second].insert(block_size);
        S.pop();
        ++block_size;
      }
    }
  }

  if (disc[node] == 1) {
    bool inc = !S.empty();
    while (!S.empty()) {
      c[S.top().first].insert(block_size);
      c[S.top().second].insert(block_size);
      S.pop();
    }
    block_size += inc;
  }
}

inline void init() {
  memset(parent, -1, sizeof parent);
  memset(dad, -1, sizeof dad);
}

int bc_dfs(int node, int l) {
  lvl[node] = l;
  for (int nxt : bc[node]) {
    if (nxt == dad[0][node]) continue;
    dad[0][nxt] = node;
    bc_dfs(nxt, l + 1);
  }
}

int lca(int a, int b) {
  if (lvl[a] < lvl[b]) swap(a, b);
  for (int i = 19; i >= 0; --i)
    if (dad[i][a] != -1 && lvl[dad[i][a]] >= lvl[b])
      a = dad[i][a];
  if (a == b) return a;
  assert(lvl[a] == lvl[b]);
  for (int i = 19; i >= 0; --i) {
    if (dad[i][a] != dad[i][b]) {
      a = dad[i][a];
      b = dad[i][b];
    }
  }
  return dad[0][a];
}

int dist(int a, int b) {
  int anc = lca(a, b);
  int ret = 0;
  for (int node : {a, b}) {
    for (int i = 19; i >= 0; --i) {
      if (dad[i][node] != -1 && lvl[dad[i][node]] >= lvl[anc]) {
        ret += 1 << i;
        node = dad[i][node];
      }
    }
  }
  return ret;
}

void block_cut() {
  for (int i = 0; i < N; ++i) {
    if (c[i].size() == 1) {
      label[i] = *c[i].begin();
      continue;
    }
    for (int x : c[i]) {
      bc[x].push_back(block_size + cut_size);
      bc[block_size + cut_size].push_back(x);
    }
    label[i] = block_size + cut_size;
    ++cut_size;
  }

  bc_dfs(0, 0);

  int bc_size = block_size + cut_size;
  for (int i = 1; i < 20; ++i)
    for (int j = 0; j < bc_size; ++j)
      if (dad[i - 1][j] == -1)
        dad[i][j] = -1;
      else
        dad[i][j] = dad[i - 1][dad[i - 1][j]];

  //for (int i = 0; i < bc_size; ++i) {
    //printf("Parents of %d in bc: ", i);
    //for (int j = 0; j < 20; ++j)
      //printf("%d ", dad[j][i]);
    //printf("\n");
  //}
}

int query(int a, int b) {
  int d = dist(label[a], label[b]);
  //printf("-- %d %d | %d %d %d\n", a, b, label[a], label[b], d);
  if (c[a].size() == 1) ++d;
  if (c[b].size() == 1) ++d;
  int ret = d / 2;
  return max(0, ret);
}

int main(void) {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  init();
  dfs(0);

  assert(S.empty());

  //printf("%d\n", block_size);
  //for (int i = 0; i < N; ++i) {
    //printf("Components of %d: ", i + 1);
    //for (int x : c[i])
      //printf("%d ", x);
    //printf("\n");
  //}

  block_cut();

  for (int i = 0; i < Q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    printf("%d\n", query(a, b));
  }

  return 0;
}