#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, P = 1e9 + 7;
int n, m, fa[maxn], sz[maxn], tid[maxn], dep[maxn];

inline int inc(int x, int y) {
  return x + y < P ? x + y : x + y - P;
}

inline int dec(int x, int y) {
  return x - y < 0 ? x - y + P : x - y;
}

struct BIT {
  int c[maxn];

  void add(int pos, int x) {
    for (; pos <= n; pos += pos & -pos) {
      c[pos] = inc(c[pos], x);
    }
  }

  int query(int pos) {
    int res = 0;
    for (; pos; pos &= pos - 1) {
      res = inc(res, c[pos]);
    }
    return res;
  }

  void add(int l, int r, int x) {
    add(l, x), add(r + 1, dec(0, x));
  }
} t1, t2;

vector <int> e[maxn];

int dfs(int u) {
  static int now;
  tid[u] = ++now;
  for (int v : e[u]) {
    sz[u] += dfs(v);
  }
  return ++sz[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", fa + i);
    e[fa[i]].push_back(i);
    dep[i] = dep[fa[i]] + 1;
  }
  dfs(1);
  scanf("%d", &m);
  while (m--) {
    int op, u, x, k;
    scanf("%d %d", &op, &u);
    int l = tid[u], r = tid[u] + sz[u] - 1;
    if (op == 1) {
      scanf("%d %d", &x, &k);
      t1.add(l, r, inc(x, 1ll * dep[u] * k % P));
      t2.add(l, r, k);
    } else {
      printf("%d\n", dec(t1.query(l), 1ll * dep[u] * t2.query(l) % P));
    }
  }
  return 0;
}