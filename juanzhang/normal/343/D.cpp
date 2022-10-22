#include <bits/stdc++.h>
using namespace std;

#define mid ((s + t) >> 1)
const int maxn = 5e5 + 10;
int n, m, tag[maxn << 2], sum[maxn << 2];
int fa[maxn], sz[maxn], tid[maxn], dep[maxn], son[maxn], top[maxn];

vector <int> e[maxn];

int dfs1(int u, int f) {
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (int v : e[u]) {
    if (v != f) {
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
  tid[u] = ++now, top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (int v : e[u]) {
    if (v != fa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void pushtag(int k, int x) {
  tag[k] = sum[k] = x;
}

void pushdown(int k) {
  if (~tag[k]) {
    pushtag(k << 1, tag[k]);
    pushtag(k << 1 | 1, tag[k]);
    tag[k] = -1;
  }
}

void upd(int k, int s, int t, int l, int r, int x) {
  if (l <= s && t <= r) {
    pushtag(k, x); return;
  }
  pushdown(k);
  if (l <= mid) upd(k << 1, s, mid, l, r, x);
  if (r > mid) upd(k << 1 | 1, mid + 1, t, l, r, x);
}

int query(int pos) {
  int k = 1, s = 1, t = n;
  while (s < t) {
    pushdown(k);
    if (pos <= mid) {
      k <<= 1, t = mid;
    } else {
      k = k << 1 | 1, s = mid + 1;
    }
  }
  return sum[k];
}

void upd(int u) {
  while (top[u] != 1) {
    upd(1, 1, n, tid[top[u]], tid[u], 0);
    u = fa[top[u]];
  }
  upd(1, 1, n, 1, tid[u], 0);
}

int main() {
  memset(tag, -1, sizeof tag);
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs1(1, 0), dfs2(1, 1);
  scanf("%d", &m);
  int op, u;
  while (m--) {
    scanf("%d %d", &op, &u);
    if (op == 1) upd(1, 1, n, tid[u], tid[u] + sz[u] - 1, 1);
    if (op == 2) upd(u);
    if (op == 3) printf("%d\n", query(tid[u]));
  }
  return 0;
}