// Hydro submission #63035ff7e4ddd633f12924a8@1661165559836
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int n;
long long ans[MAXN], sum[MAXN << 5];
int c[MAXN], root[MAXN], times[MAXN << 5], lc[MAXN << 5], rc[MAXN << 5],
    tot;
vector<int> g[MAXN];
void pushup(int u) {
  times[u] = max(times[lc[u]], times[rc[u]]);
  if (times[lc[u]] > times[rc[u]]) {
    sum[u] = sum[lc[u]];
  } else if (times[lc[u]] < times[rc[u]]) {
    sum[u] = sum[rc[u]];
  } else {
    sum[u] = sum[lc[u]] + sum[rc[u]];
  }
}
void update(int& u, int c, int l = 1, int r = n) {
  if (!u) u = ++tot;
  if (l == r) {
    sum[u] = c;
    times[u] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (c <= mid)
    update(lc[u], c, l, mid);
  else
    update(rc[u], c, mid + 1, r);
  pushup(u);
}
int merge(int u, int v, int l = 1, int r = n) {
  if (!u || !v) return u ^ v;
  if (l == r) {
    times[u] += times[v];
    return u;
  }
  int mid = (l + r) >> 1;
  lc[u] = merge(lc[u], lc[v], l, mid);
  rc[u] = merge(rc[u], rc[v], mid + 1, r);
  pushup(u);
  return u;
}
void dfs(int u, int fa = -1) {
  update(root[u], c[u]);
  if (g[u][0] == fa && g[u].size() == 1) {  // 
    ans[u] = c[u];
    return;
  }
  for (auto i : g[u]) {
    if (i == fa) continue;
    dfs(i, u);
    root[u] = merge(root[u], root[i]);
  }
  ans[u] = sum[root[u]];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) { cout << ans[i] << ' '; }
  return 0;
}