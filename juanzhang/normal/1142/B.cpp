#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 4e5 + 10;
int n, m, q, a[maxn], p[maxn], mp[maxn];

int nxt[maxn], pos[maxn], to[maxn];

int lg[maxn], val[18][maxn];

void build() {
  rep(i, 1, m) val[0][i] = to[i];
  for (int i = 2; i <= m; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 1; j + (1 << i) - 1 <= m; j++) {
      val[i][j] = min(val[i - 1][j], val[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(val[k][l], val[k][r - (1 << k) + 1]);
}

namespace GETto {
  int deg[maxn], dep[maxn], fa[18][maxn];
  vector <int> e[maxn];
  
  int query(int u) {
    int k = n - 1;
    if (dep[u] <= k) return m + 1;
    for (int i = 17; ~i; i--) {
      if (k >> i & 1) u = fa[i][u];
    }
    return u;
  }
  
  void dfs(int u) {
    for (int i = 1; i < 18; i++) {
      fa[i][u] = fa[i - 1][fa[i - 1][u]];
    }
    to[u] = query(u);
    for (int v : e[u]) {
      fa[0][v] = u;
      dep[v] = dep[u] + 1, dfs(v);
    }
  }
  
  void solve() {
    rep(i, 1, m) {
      if (nxt[i] <= m) e[nxt[i]].push_back(i), deg[i]++;
    }
    rep(i, 1, m) {
      if (!deg[i]) dep[i] = 1, dfs(i);
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  rep(i, 1, n) scanf("%d", p + i), mp[p[i]] = i;
  rep(i, 1, m) scanf("%d", a + i);
  fill(pos + 1, pos + n + 1, m + 1);
  per(i, m, 1) {
    nxt[i] = pos[p[mp[a[i]] % n + 1]];
    pos[a[i]] = i;
  }
  nxt[m + 1] = m + 1;
  GETto::solve();
  build();
  static int ans[maxn];
  rep(i, 1, q) {
    int l, r;
    scanf("%d %d", &l, &r);
    ans[i] = query(l, r) <= r;
  }
  rep(i, 1, q) putchar(ans[i] | 48);
  return 0;
}