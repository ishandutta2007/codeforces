#include <bits/stdc++.h>
using namespace std;

const int maxn = 1.5e6 + 10;
int N, rt, ls[maxn], rs[maxn];
int n, m, deg[maxn], ans[maxn];

vector <int> e[maxn];

inline void addline(int u, int v) {
  e[u].push_back(v), ++deg[v];
}

#define mid ((l + r) >> 1)
#define lson ls[k], l, mid
#define rson rs[k], mid + 1, r

void build(int &k, int l, int r) {
  k = ++N;
  if (l == r) {
    addline(l, k); return;
  }
  build(lson), build(rson);
  addline(ls[k], k), addline(rs[k], k);
}

void add(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    addline(k, x); return;
  }
  if (ql <= mid) add(lson, ql, qr, x);
  if (qr > mid) add(rson, ql, qr, x);
}

#undef mid
#undef lson
#undef rson

inline bool topo() {
  static int Q[maxn];
  int l = 1, r = 0, now = 0;
  for (int i = 1; i <= N; ++i) {
    if (!deg[i]) Q[++r] = i;
  }
  while (l <= r) {
    int u = Q[l++];
    for (int v : e[u]) {
      if (!--deg[v]) Q[++r] = v;
    }
  }
  if (r < N) return 1;
  for (int i = 1; i <= N; ++i) {
    if (Q[i] <= n) ans[Q[i]] = ++now;
  }
  return 0;
}

inline void solve() {
  scanf("%d", &n), N = n;
  for (int i = 0; i < n * 3 + 5; ++i) {
    e[i].clear(), deg[i] = 0;
  }
  build(rt, 1, n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (x == -1) continue;
    if (x <= n) addline(i, x);
    if (x > i + 1) add(rt, 1, n, i + 1, x - 1, i);
  }
  if (topo()) {
    puts("-1"); return;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], "\n "[i < n]);
  }
}

int main() {
  int Tests;
  scanf("%d", &Tests);
  while (Tests--) solve();
  return 0;
}