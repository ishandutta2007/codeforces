#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n, k, now, a[maxn], c[maxn], sz[maxn], fa[maxn], tid[maxn], dep[maxn]; bool vis[maxn];
vector <int> e[maxn];

void upd(int pos, int x) {
  for (; pos <= n; pos += pos & -pos) {
    c[pos] += x;
  }
}

int query(int pos) {
  int res = 0;
  for (; pos; pos &= pos - 1) {
    res += c[pos];
  }
  return res;
}

int dfs(int u, int f) {
  a[++now] = u, tid[u] = now, fa[u] = f, dep[u] = dep[f] + 1;
  for (int v : e[u]) {
    if (v != f) sz[u] += dfs(v, u);
  }
  return ++sz[u];
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs(n, 0), upd(1, -1);
  for (int i = 1; i <= n; i++) {
    upd(i, dep[a[i]] - dep[a[i - 1]]);
  }
  int tmp = n - k; vis[0] = 1;
  for (int i = n; i; i--) {
    if (query(tid[i]) < tmp) {
      for (int cur = i; !vis[cur]; tmp--, vis[cur] = 1, cur = fa[cur]) {
        upd(tid[cur], -1), upd(tid[cur] + sz[cur], 1);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (!vis[i]) printf("%d ", i);
  }
  return 0;
}