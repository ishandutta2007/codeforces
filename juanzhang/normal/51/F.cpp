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
const int maxn = 1e5 + 10;
int n, m, ans;

int h[maxn], h2[maxn], out[maxn];

struct edges {
  int nxt, to;
} E[maxn << 1], E2[maxn << 1];

set <pii> G2;

void addline(int u, int v) {
  static int ecnt = 1;
  E[++ecnt] = edges{h[u], v}, h[u] = ecnt;
}

void addline2(int u, int v) {
  static int ecnt = 1;
  E2[++ecnt] = edges{h2[u], v}, h2[u] = ecnt, out[v] = out[v] ? -1 : ecnt;
}

bool cut[maxn << 1];
int dfn[maxn], low[maxn];

void tarjan(int u, int f) {
  static int now;
  dfn[u] = low[u] = ++now;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!dfn[v]) {
      tarjan(v, u);
      chkmin(low[u], low[v]);
      if (low[v] > dfn[u]) cut[i ^ 1] = cut[i] = 1;
    } else if (v != f) {
      chkmin(low[u], dfn[v]);
    }
  }
}

int tot, bl[maxn];

void dfs(int u) {
  bl[u] = tot, ans++;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!cut[i] && !bl[v]) dfs(v);
  }
}

int dis[maxn];

void getans(int rt) {
  static int Q[maxn], pre[maxn], vis[maxn << 1];
  int l = 1, r = 1;
  Q[1] = rt, dis[rt] = 0;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h2[u]; i; i = E2[i].nxt) {
      int v = E2[i].to;
      if (dis[v] == -1) {
        Q[++r] = v, dis[v] = dis[u] + 1, ans++;
      }
    }
  }
  int S = 0, T = 0;
  rep(i, 1, r) {
    if (dis[S] <= dis[Q[i]]) S = Q[i];
  }
  rep(i, 1, r) {
    dis[Q[i]] = -1;
  }
  l = r = 1;
  Q[1] = S, dis[S] = 0;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h2[u]; i; i = E2[i].nxt) {
      int v = E2[i].to;
      if (dis[v] == -1) {
        Q[++r] = v, pre[v] = i, dis[v] = dis[u] + 1;
      }
    }
  }
  rep(i, 1, r) {
    if (dis[T] <= dis[Q[i]]) T = Q[i];
  }
//  printf("#(%d %d)\n", S, T);
  for (int u = T; u != S; u = E2[pre[u] ^ 1].to) {
    vis[pre[u] ^ 1] = vis[pre[u]] = 1, ans--;
  }
  rep(i, 1, r) {
    int u = Q[i];
    if (out[u] > 0 && !vis[out[u]]) {
      vis[out[u] ^ 1] = vis[out[u]] = 1, ans--;
    }
  }
}

void solve() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read();
    addline(u, v), addline(v, u);
  }
  rep(i, 1, n) if (!dfn[i]) {
    tarjan(i, -1);
  }
  rep(i, 1, n) if (!bl[i]) {
    ++tot, dfs(i);
  }
//  puts("GG");
//  rep(i, 1, n) printf("%d%c", bl[i], "\n "[i < n]);
  ans -= tot;
  rep(u, 1, n) for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (bl[u] != bl[v] && G2.find({bl[u], bl[v]}) == G2.end()) {
      G2.insert({bl[u], bl[v]}), addline2(bl[u], bl[v]);
      G2.insert({bl[v], bl[u]}), addline2(bl[v], bl[u]);
    }
  }
  ans--;
  memset(dis, -1, sizeof dis);
  rep(i, 1, tot) if (dis[i] == -1) {
    ans++, getans(i);
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}