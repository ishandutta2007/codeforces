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

const int MAXN = 100100;
const int LG = 20;

struct Edge {
  int b, w;
};

vector<Edge> E[MAXN];
int f[MAXN];

struct data {
  int left, right, total, sum;
  friend data operator + (const data &a, const data &b) {
    int total = a.total + b.total, sum = a.sum + b.sum;
    if (a.left == a.total && b.right == b.total) return {total, total, total, sum};
    if (a.left == a.total) return {a.total + b.left, b.right, total, sum};
    if (b.right == b.total) return {a.left, a.right + b.total, total, sum};
    return {a.left, b.right, total, sum + f[a.right + b.left]};
  }
};
  
data rev(const data &a) {
  return {a.right, a.left, a.total, a.sum};
}

struct HeavyPath {
  vector<int> v;  
  vector<data> T;
  int off;

  void init() {
    for (off = 1; off < (int)v.size(); off *= 2);
    T.resize(2*off);
    FOR(i, off, 2*off) T[i] = {0, 0, 1, 0};
    for (int i = off-1; i > 0; --i)
      T[i] = T[i*2] + T[i*2+1];
  }

  void update(int x, data val) {
    x += off;
    T[x] = val;
    for (x /= 2; x; x /= 2)
      T[x] = T[x*2] + T[x*2+1];
  }
  
  data query(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return {0, 0, 0, 0};
    if (lo >= a && hi <= b) return T[i];
    return query(i*2, lo, (lo+hi)/2, a, b) + query(i*2+1, (lo+hi)/2, hi, a, b);
  }

  data query(int a, int b) {
    if (a <= b) return query(1, 0, off, a+1, b+1);
    return rev(query(b, a));
  }
};

HeavyPath H[MAXN];
int c;

int d[MAXN], parent[MAXN], sz[MAXN];
int ch_id[MAXN], ch_pos[MAXN]; // koji heavy path i koja pozicija u njemu

void dfs(int x, int dad) {
  parent[x] = dad;
  sz[x] = 1;
  for (auto &e: E[x])
    if (e.b != dad) {
      d[e.b] = d[x] + 1;
      dfs(e.b, x);
      sz[x] += sz[e.b];
    }
}

void decompose(int x, int id, int pos) {
  ch_id[x] = id, ch_pos[x] = pos;
  H[id].v.push_back(x);

  int m = -1;
  for (auto &e: E[x])
    if (e.b != parent[x])
      if (m == -1 || sz[e.b] > sz[m]) m = e.b;
  
  if (m == -1) return;

  decompose(m, id, pos + 1);
  for (auto &e: E[x])
    if (e.b != parent[x] && e.b != m) decompose(e.b, c++, 0);
}

int ans[MAXN];
data cur_e[MAXN];

enum {QUERY, EDGE};
struct Event {
  int tip, u, v, l, i;
  friend bool operator < (const Event &a, const Event &b) {
    if (a.l != b.l) return a.l > b.l;
    return a.tip > b.tip;
  }
};
vector<Event> V;

int query(int u, int v) {
  data du = {0, 0, 0, 0}, dv = {0, 0, 0, 0};
  while (ch_id[u] != ch_id[v]) {
    if (d[H[ch_id[u]].v[0]] > d[H[ch_id[v]].v[0]]) {
      du = du + H[ch_id[u]].query(ch_pos[u], -1);
      u = parent[ H[ch_id[u]].v[0] ];
    } else {
      dv = H[ch_id[v]].query(-1, ch_pos[v]) + dv;
      v = parent[ H[ch_id[v]].v[0] ];
    }
  }
  du = du + H[ch_id[u]].query(ch_pos[u], ch_pos[v]);
  du = du + dv;
  
  int ans = du.sum;
  if (du.total == du.left) ans += f[du.total]; else
    ans += f[du.left] + f[du.right];
  return ans;
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  FOR(i, 1, n) scanf("%d", &f[i]);
  REP(i, n-1) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w); --a, --b;
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  dfs(0, -1);
  decompose(0, c++, 0);
  
  REP(i, c) H[i].init();
  
  REP(a, n) for (auto &e: E[a])
    if (parent[e.b] == a) {
      V.push_back({EDGE, a, e.b, e.w});
      cur_e[e.b] = {0, 0, 1, 0};
    }

  REP(i, q) {
    int u, v, l;
    scanf("%d %d %d", &u, &v, &l); --u, --v;
    V.push_back({QUERY, u, v, l, i});
  }
  
  sort(V.begin(), V.end());
  for (Event &e: V)
    if (e.tip == EDGE) {
      cur_e[e.v] = {1, 1, 1, 0};
      H[ch_id[e.v]].update(ch_pos[e.v], cur_e[e.v]);
    } else {
      ans[e.i] = query(e.u, e.v);
    }

  REP(i, q) printf("%d\n", ans[i]);
  return 0;
}