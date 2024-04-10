#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 6e5 + 10;
int n, m, q, A[maxn], ans[maxn];

struct edge {
  int u, v, w;
} EE[maxn];

struct Querys {
  int op, x;
} Q[maxn];

int tot, par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

set <int> E[maxn];
vector <int> da[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int dfn[maxn], id[maxn], sz[maxn], val[maxn << 2];

void build(int k, int l, int r) {
  if (l == r) {
    val[k] = A[id[l]];
    return;
  }
  build(lson), build(rson), val[k] = max(val[k << 1], val[k << 1 | 1]);
}

void upd(int k, int l, int r, int ql, int qr, int v) {
  if (val[k] < v) return;
  if (ql <= l && r <= qr && l == r) return val[k] = 0, void();
  if (ql <= mid) upd(lson, ql, qr, v);
  if (qr > mid) upd(rson, ql, qr, v);
  val[k] = max(val[k << 1], val[k << 1 | 1]);
}

int query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return val[k];
  }
  int res = 0;
  if (ql <= mid) res = query(lson, ql, qr);
  if (qr > mid) chkmax(res, query(rson, ql, qr));
  return res;
}

#undef mid
#undef lson
#undef rson

void DFS(int u) {
  if (!u) return;
  static int now;
  dfn[u] = ++now, id[now] = u, sz[u] = 1;
//  printf("#%d : ", u);
//  for (int v : E[u]) printf("%d ", v);
//  puts("");
  for (int v : E[u]) DFS(v), sz[u] += sz[v];
}

void dfs(int u) {
  if (!u) return;
  reverse(da[u].begin(), da[u].end());
  for (int i : da[u]) {
    ans[i] = query(1, 1, tot, dfn[u], dfn[u] + sz[u] - 1);
    upd(1, 1, tot, dfn[u], dfn[u] + sz[u] - 1, ans[i]);
  }
  for (int v : E[u]) dfs(v);
}

void solve() {
  cin >> n >> m >> q;
  rep(i, 1, n) A[i] = read();
  rep(i, 1, n + n) par[i] = i;
  rep(i, 1, m) {
    int u = read(), v = read();
    EE[i] = {u, v, q + 1};
  }
  rep(i, 1, q) {
    Q[i].op = read(), Q[i].x = read();
    if (Q[i].op == 2) {
      EE[Q[i].x].w = i;
    }
  }
  sort(EE + 1, EE + m + 1, [] (edge P, edge Q) {
    return P.w > Q.w;
  });
  tot = n;
  int cur = q;
  rep(i, 1, m) {
    int u = find(EE[i].u), v = find(EE[i].v);
    if (u != v) {
      for (; cur >= EE[i].w; cur--) if (Q[cur].op == 1) {
        da[find(Q[cur].x)].push_back(cur);
//        printf("(%d) q:%d\n", find(Q[cur].x), cur);
      }
      tot++;
      E[tot].insert(u), par[u] = tot;
      E[tot].insert(v), par[v] = tot;
    }
  }
  for (; cur; cur--) if (Q[cur].op == 1) {
    da[find(Q[cur].x)].push_back(cur);
//    printf("(%d) q:%d\n", find(Q[cur].x), cur);
  }
  tot++;
  rep(i, 1, n) E[tot].insert(find(i));
//  puts("GG");
  memset(ans, -1, sizeof ans);
  DFS(tot);
//  puts("GG");
  build(1, 1, tot);
  dfs(tot);
  rep(i, 1, q) if (ans[i] != -1) {
    printf("%d\n", ans[i]);
  }
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}