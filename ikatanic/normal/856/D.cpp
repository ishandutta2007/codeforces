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

const int LG = 20;
const int MAX = 200200;

struct Query {
  int a, b, w;
} q[MAX];

vector<int> E[MAX];
vector<int> qs[MAX];
int L[MAX][LG];
int d[MAX];

int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int j = LG-1; j >= 0; --j)
    if (d[u] - (1<<j) >= d[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG-1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int l[MAX];
int p[MAX];

int sum(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += l[x];
  return r;
}

void add(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    l[x] += v;
}

void add_interval(int x, int y, int v) {
  add(x, v);
  add(y, -v);
}

int tick;
int start[MAX], fin[MAX];

void dfs(int x) {
  start[x] = tick++;
  for (int y: E[x]) dfs(y);
  fin[x] = tick;
}

int getChild(int u, int v) {
  assert(start[u] < start[v] && fin[v] <= fin[u]);
  int lo = 0, hi = (int)E[u].size() - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (start[E[u][mid]] <= start[v]) lo = mid;
    else hi = mid - 1;
  }
  int x = E[u][lo];
  assert(start[x] <= start[v] && fin[v] <= fin[x]);
  return x;
}

int f[MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  p[0] = 0;
  d[0] = 0;
  FOR(i, 1, n) {
    scanf("%d", &p[i]);
    --p[i];
    d[i] = d[p[i]] + 1;
    E[p[i]].push_back(i);
  }

  REP(i, n) L[i][0] = p[i];
  FOR(j, 1, LG) REP(i, n) L[i][j] = L[ L[i][j-1] ][j-1];

  REP(i, m) {
    scanf("%d %d %d", &q[i].a, &q[i].b, &q[i].w);
    --q[i].a, --q[i].b;
    qs[lca(q[i].a, q[i].b)].push_back(i);
  }

  tick = 0;
  dfs(0);

  for (int i = n-1; i >= 0; --i) {
    int all = 0;
    for (int j: E[i]) all += f[j];
    f[i] = all;

    
    for (int k: qs[i]) {
      int a = q[k].a, b = q[k].b;
      int nf = all;

      if (a != i) {
        nf -= f[getChild(i, a)];
        nf += sum(start[a]);
      }
      
      if (b != i) {
        nf -= f[getChild(i, b)];
        nf += sum(start[b]);
      }

      nf += q[k].w;
      
      f[i] = max(f[i], nf);
    }

    add_interval(start[i], start[i] + 1, all);
    for (int j: E[i]) {
      add_interval(start[j], fin[j], all - f[j]);
    }
  }

  printf("%d\n", f[0]);
  return 0;
}