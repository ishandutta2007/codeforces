#include <bits/stdc++.h>
using namespace std;

#define iter set <int> :: iterator
typedef long long ll;
const int maxn = 1e5 + 10;
ll ans, dis[maxn];
int n, m, tid[maxn], rk[maxn], h[maxn];
int sz[maxn], fa[maxn], dep[maxn], son[maxn], top[maxn];

set <int> seq;

struct edges {
  int nxt, to, w;
} e[maxn << 1];

void addline(int u, int v, int w) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

int dfs1(int u, int f) {
  fa[u] = f, dep[u] = dep[f] + 1;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != f) {
      dis[v] = dis[u] + e[i].w;
      sz[u] += dfs1(v, u);
      if (sz[son[u]] < sz[v]) {
        son[u] = v;
      }
    }
  }
  return ++sz[u];
}

void dfs2(int u, int tp) {
  static int now;
  top[u] = tp;
  tid[u] = ++now, rk[now] = u;
  if (son[u]) dfs2(son[u], tp);
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != fa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

ll lca(int u, int v) {
  ll res = dis[u] + dis[v];
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      u = fa[top[u]];
    } else {
      v = fa[top[v]];
    }
  }
  int _lca = dep[u] < dep[v] ? u : v;
  return res - 2 * dis[_lca];
}

ll query(iter it) {
  iter pre = it, nxt = it;
  pre = it == seq.begin() ? seq.end() : it, pre--;
  if (++nxt == seq.end()) nxt = seq.begin();
  int l = rk[*pre], r = rk[*nxt], u = rk[*it];
  return lca(l, u) + lca(u, r) - lca(l, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 1, u, v, w; i < n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    addline(u, v, w), addline(v, u, w);
  }
  dfs1(1, 0), dfs2(1, 1);
  scanf("%d", &m);
  iter it, tmp;
  char c; int x;
  while (m--) {
    scanf("%s", &c);
    if (c == '?') {
      printf("%I64d\n", ans >> 1);
      continue;
    }
    scanf("%d", &x);
    if (c == '+') {
      it = seq.insert(tid[x]).first;
      if (seq.size() > 2) {
        ans += query(it);
      } else if (seq.size() == 2) {
        tmp = it == seq.begin() ? ++it : seq.begin();
        ans = lca(rk[*tmp], x) << 1;
      }
    } else {
      it = seq.find(tid[x]);
      if (seq.size() > 2) {
        ans -= query(it);
      } else if (seq.size() == 2) {
        ans = 0;
      }
      seq.erase(tid[x]);
    }
  }
  return 0;
}