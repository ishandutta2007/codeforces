#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 200200;

namespace BCC {
  int n, m;
  vector<int> G[MAXN];
  set<pair<int, int>> bridges;

  void init(int _n) { 
    n = _n;
    REP(i, n) G[i].clear();
  }

  void add_edge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
  }

  enum {WHITE, GRAY, BLACK};
  int color[MAXN];
  int dis[MAXN], tick;
  int low[MAXN];
  int comp_id[MAXN];

  void dfs(int i, int dad) {
    color[i] = GRAY;
    low[i] = dis[i] = ++tick;

    bool found_dad_edge = false;
    for (int j: G[i]) {
      if (j == dad && !found_dad_edge) {
        found_dad_edge = true;
        continue;
      }
      if (color[j] == GRAY) low[i] = min(low[i], dis[j]);
      if (color[j] == WHITE) {
	dfs(j, i);
	low[i] = min(low[i], low[j]);
        if (low[j] > dis[i]) bridges.insert({i, j});
      }
    }

    color[i] = BLACK;
  }

  void dfs2(int x, int id) {
    comp_id[x] = id;
    for (int y: G[x])
      if (!bridges.count({x, y}))
        if (!bridges.count({y, x}))
          if (comp_id[y] == -1) dfs2(y, id);
  }

  void decompose() {
    REP(i, n) low[i] = dis[i] = 0, color[i] = WHITE;
    REP(i, n) if (color[i] == WHITE) dfs(i, -1);
    REP(i, n) comp_id[i] = -1;
    REP(i, n) if (comp_id[i] == -1) dfs2(i, i);
  }
};

vector<int> E[MAXN], F[MAXN];

const int LG = 20;

int L[MAXN][LG];
int dep[MAXN];

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = LG-1; j >= 0; --j)
    if (dep[u] - (1<<j) >= dep[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG-1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int dad[MAXN];
int comp[MAXN];

void dfs(int x, int id) {
  if (comp[x]) return;
  comp[x] = id;
  for (int y: F[x])
    if (y != dad[x]) {
      dad[y] = x;
      dep[y] = dep[x] + 1;
      dfs(y, id);
    }
}

bool bio[MAXN];
map<pair<int, int>, int> au, ad;

pair<int, int> dfs_check(int x) {
  bio[x] = true;
  int u = 0, d = 0;
  for (int y: F[x]) {
    if (y == dad[x]) continue;

    auto pp = dfs_check(y);
    int curu = pp.first, curd = pp.second;
    if (au.count({x, y})) curu += au[{x, y}];
    if (ad.count({x, y})) curd += ad[{x, y}];

    if (curu > 0 && curd > 0) {
      puts("No");
      exit(0);
    }
    
    u += curu, d += curd;
  }
  return {u, d};
}

int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  BCC::init(n);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
    BCC::add_edge(a, b);
  }

  BCC::decompose();

  vector<int> v;  
  int* comp_id = BCC::comp_id;
  REP(i, n) {
    if (i == comp_id[i]) v.push_back(i);
    for (int j: E[i])
      if (comp_id[i] != comp_id[j]) F[comp_id[i]].push_back(comp_id[j]);
  }
  int c = 0;
  for (int x: v)
    if (!comp[x]) {
      dad[x] = x;
      dfs(x, ++c);
    }

  for (int i: v) L[i][0] = dad[i];
  FOR(j, 1, LG) for (int i: v)
    L[i][j] = L[ L[i][j-1] ][j-1];

  REP(i, q) {
    int s, t;
    scanf("%d %d", &s, &t);
    --s, --t;

    s = comp_id[s], t = comp_id[t];
    if (comp[s] != comp[t]) {
      puts("No");
      return 0;
    }

    int l = lca(s, t);

    au[{dad[l], l}]--;
    au[{dad[s], s}]++;
    ad[{dad[l], l}]--;
    ad[{dad[t], t}]++;
  }

  for (int i: v)
    if (!bio[i]) dfs_check(i);

  puts("Yes");
  return 0;
}