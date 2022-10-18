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

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

const int MAXN = 100100;
const int LG = 20;

struct edge {
  int b, w;
};

struct box {
  int sumsq, sum, n;
  box() { sumsq = sum = n = 0; };
  void add_delta(int x) {
    if (x < 0) x += mod;
    sumsq = add(sumsq, mul(2, mul(sum, x)));
    sumsq = add(sumsq, mul(n, mul(x, x)));
    sum = add(sum, mul(n, x));
  }
  void multiply(int x) {
    if (x < 0) x += mod;
    sumsq = mul(sumsq, mul(x, x));
    sum = mul(sum, x);
  }
  void add0() { n = add(n, 1); }
  void remove0() { n = sub(n, 1); }
  void add_box(box &b) {
    sumsq = add(sumsq, b.sumsq);
    sum = add(sum, b.sum);
    n = add(n, b.n);
  }
  void sub_box(box &b) {
    sumsq = sub(sumsq, b.sumsq);
    sum = sub(sum, b.sum);
    n = sub(n, b.n);
  }
};

vector<edge> E[MAXN];
int L[MAXN][LG];
int d[MAXN], dad[MAXN];
int dist[MAXN];
box b_up[MAXN];
box b_down[MAXN];
box b_all[MAXN];

void dfs(int x) {
  REP(i, (int)E[x].size())
    if (E[x][i].b == dad[x]) {
      E[x].erase(E[x].begin() + i);
      break;
    }

  for (edge &e: E[x]) {
    dad[e.b] = x;
    dist[e.b] = add(dist[x], e.w);
    d[e.b] = d[x] + 1;
    b_up[e.b] = b_up[x];
    b_up[e.b].add_delta(e.w);
    b_up[e.b].add0();
    dfs(e.b);
  }
}

void dfs2(int x) {
  for (edge &e: E[x]) {
    dfs2(e.b);
    box tmp = b_down[e.b];
    tmp.add_delta(e.w);
    b_down[x].add_box(tmp);
  }
  b_down[x].add0();
}

void dfs3(int x) {
  for (edge &e: E[x]) {
    int y = e.b;
    
    b_all[y] = b_all[x];
    box ydown = b_down[y];
    ydown.add_delta(e.w);
    b_all[y].sub_box(ydown);
    
    b_all[y].add_delta(e.w);
    b_all[y].add_box(b_down[y]);
    
    dfs3(y);
  }
}

int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int j = LG-1; j >= 0; --j)
    if (d[u]-(1<<j) >= d[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG-1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int solve(int u, int v) {
  int x = lca(u, v);

  if (x == v) {
    int duv = sub(dist[u], dist[v]);
    box ans = b_all[u];
    box s = b_all[v];
    s.sub_box(b_down[v]);
    s.add_delta(duv);
    ans.sub_box(s);
    return ans.sumsq;
  }

  int dxv = sub(dist[v], dist[x]);
  int dxu = sub(dist[u], dist[x]);
  
  box ans = b_down[v];
  ans.add_delta(dxv);
  ans.add_delta(dxu);
  return ans.sumsq;
}
    
int main(void) {
  int n;
  scanf("%d", &n);
  
  REP(i, n-1) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b;
    E[a].push_back({b, c});
    E[b].push_back({a, c});
  }
  
  dad[0] = -1;
  b_up[0].add0();
  dfs(0);
  dfs2(0);

  b_all[0] = b_down[0];
  dfs3(0);

  REP(i, n) L[i][0] = dad[i];
  FOR(j, 1, LG) REP(i, n)
      if (L[i][j-1] != -1) L[i][j] = L[ L[i][j-1] ][j-1]; else
        L[i][j] = L[i][j-1];

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    int ans = solve(u, v);
    ans = mul(ans, 2);
    ans = sub(ans, b_all[u].sumsq);
    printf("%d\n", ans);
  }    
    
  return 0;
}