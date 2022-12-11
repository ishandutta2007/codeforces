#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 3e5 + 10;
int n, m, q, lg[N], f[N][20], d[N], c, col[N], o, ord[N];
struct graph {
  struct Edge { int v, nxt; } e[N * 4];
  int ec, hd[N];
  void init(int sz) { fill(hd, hd + sz + 1, -1); ec = 0; }
  void add(int u, int v) { e[ec] = {v, hd[u]}; hd[u] = ec ++; }
  void bdd(int u, int v) { add(u, v); add(v, u); }
} G0, G1, G2;
void dfs(graph *G, int u, int fa = 0) {
  // cerr << "fa " << u << " = " << fa << endl;
  f[u][0] = fa; d[u] = fa ? d[fa] + 1 : 0; ord[u] = ++ o;
  rep(i, 1, lg[d[u]]) f[u][i] = f[f[u][i - 1]][i - 1];
  for(int i = G->hd[u]; ~i; i = G->e[i].nxt) {
    int v = G->e[i].v;
    if(!ord[v]) dfs(G, v, u);
  }
}
int lca(int u, int v) {
  if(d[u] < d[v]) swap(u, v);
  int c = d[u] - d[v];
  per(i, lg[c], 0) if(c >> i & 1) u = f[u][i];
  if(u == v) return u;
  per(i, lg[d[u]], 0) if(f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
int st[N], top;
vector<int> cl;
void ins(graph *G, int u) {
  if(!top) { st[++ top] = u; return ; }
  int l = lca(u, st[top]); cl.pb(l);
  if(l != st[top]) {
    while(top > 1 && d[l] < d[st[top - 1]]) { G->bdd(st[top - 1], st[top]); top --; }
    if(top == 1) {
      G->bdd(l, st[1]); st[1] = l;
    } else {
      if(d[l] > d[st[top - 1]]) { G->bdd(l, st[top]); st[top] = l; }
      else { G->bdd(l, st[top]); top --; }
    }
  }
  st[++ top] = u;
}
void link(graph *G) {
  rep(i, 1, top - 1) G->bdd(st[i], st[i + 1]);
  top = 0;
}
struct edge { int u, v; };
int dfn[N], low[N], idx, bel[N], bel0[N], bcc;
stack<int> s;
bool mk;
void tarjan(graph *G, int u, int f = -4) {
  dfn[u] = low[u] = ++ idx; s.push(u);
  for(int i = G->hd[u]; ~i; i = G->e[i].nxt) if(i ^ f) {
    int v = G->e[i].v;
    if(!dfn[v]) {
      tarjan(G, v, i ^ 1); low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if(low[u] == dfn[u]) {
    bcc++;
    if(mk) col[bcc] = c;
    int v = 0;
    do { v = s.top(); s.pop(); bel[v] = bcc; } while(v != u);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  lg[0] = -1;
  rep(i, 1, n) lg[i] = lg[i >> 1] + 1;
  G0.init(n);
  int u, v;
  rep(i, 1, m) { scanf("%d%d", &u, &v); G0.bdd(u, v); }
  mk = 1;
  rep(i, 1, n) if(!dfn[i]) { c++; tarjan(&G0, i); }
  mk = 0;
  G1.init(bcc);
  copy(bel, bel + n + 1, bel0);
  for(int i = 0; i < G0.ec; i += 2) {
    u = bel[G0.e[i ^ 1].v]; v = bel[G0.e[i].v];
    if(u ^ v) G1.bdd(u, v);
  }
  G2.init(n);
  // cerr << "bcc = " << bcc << endl;
  rep(i, 1, bcc) if(!ord[i]) dfs(&G1, i);
  fill(dfn, dfn + n + 1, 0);
  static int vis[N];
  vector<int> cur, V; vector<edge> ve;
  int ni, mi, z = 0;
  rep(i, 1, q) {
    scanf("%d%d", &ni, &mi);
    cur.clear(); V.clear();
    rep(j, 1, ni) {
      scanf("%d", &u);
      if((u += z) %= n, !u) u = n;
      u = bel0[u]; vis[u] = i; cur.pb(u); V.pb(u);
    }
    ve.clear();
    rep(j, 1, mi) {
      scanf("%d%d", &u, &v);
      if((u += z) %= n, !u) u = n;
      if((v += z) %= n, !v) v = n;
      u = bel0[u]; v = bel0[v];
      cur.pb(u); cur.pb(v);
      ve.pb({u, v});
    }
    sort(cur.begin(), cur.end(), [&](int x, int y) {
      return ord[x] < ord[y];
    });
    int sz = unique(cur.begin(), cur.end()) - cur.begin();
    cur.resize(sz);
    G2.ec = top = 0; cl = cur;
    for(int i = 0; i < sz; i ++) {
      ins(&G2, cur[i]);
      if(i == sz - 1 || col[cur[i + 1]] != col[cur[i]]) {
        link(&G2);
      }
    }
    for(auto e : ve) G2.bdd(e.u, e.v);
    bcc = 0;
    for(int u : cur) if(!dfn[u]) tarjan(&G2, u);
    bool tag = 1; int bid = -1;
    for(int u : V) {
      // cerr << "bel " << u << " = " << bel[u] << endl;
      if(~bid) {
        if(bid != bel[u]) { tag = 0; break ; }
      } else {
        bid = bel[u];
      }
    }
    puts(tag ? "YES" : "NO");
    if(tag) (z += i) %= n;
    for(int u : cl) G2.hd[u] = -1, dfn[u] = 0;
  }
  return 0;
}