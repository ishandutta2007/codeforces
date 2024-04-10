#include <bits/stdc++.h>

#include <algorithm>
#include <csignal>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
using namespace std;
const int N = 4e5 + 5;
int n, m, a[N], d[N], hh[N], f[N], g[N];
bool ok[N];
int l[N], r[N];
int id(int x, int y) { return x * m + y + 1; }
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> e[N], ee[N], re[N];
map<pair<int, int>, bool> vis;
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
void add(int x, int y) {
  if (x == y || vis[{x, y}])
    return;
  vis[{x, y}] = true;
  e[x].push_back(y);
}
int gd, dfn[N], low[N];
int top, s[N];
bool inq[N];
void dfs(int u) {
  dfn[u] = low[u] = ++gd;
  inq[s[++top] = u] = true;
  for (int v : e[u]) {
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (inq[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    while (s[top] != u)
      inq[s[top]] = false, f[s[top]] = u, top--;
    top--;
    inq[u] = false;
    f[u] = u;
  }
}
int t1, t2, hs[N * 2];
bool cal[N];
pair<int, int> seg[N];
bool cmp(pair<int, int> &x, pair<int, int> &y) {
  if (x.first == y.first)
    return x.second > y.second;
  return x.first < y.first;
}
int getans() {
  if (t1 == 0)
    return 0;
  sort(hs + 1, hs + 1 + t2);
  t2 = unique(hs + 1, hs + 1 + t2) - hs - 1;
  for (int i = 1; i <= t1; i++) {
    auto &x = seg[i];
    x.first = lower_bound(hs + 1, hs + 1 + t2, x.first) - hs;
    x.second = lower_bound(hs + 1, hs + 1 + t2, x.second) - hs;
  }
  sort(seg + 1, seg + 1 + t1, cmp);
  int lasr = 0, kr = 0, ans = 0;
  for (int i = 1; i <= t1; i++) {
    auto x = seg[i];
    if (x.first <= lasr + 1)
      kr = max(kr, x.second);
    else {
      assert(x.first <= kr + 1);
      ans++;
      lasr = kr;
      kr = x.second;
    }
  }
  ans += kr > lasr;
  return ans;
}
queue<int> q;
bool fah[N];
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  sc(n, m);
  rep(i, 1, n * m) f[i] = i;
  char s[n][m];
  int A[n][m], B[n][m], C[n][m], D[n][m];
  memset(A, -1, sizeof(A));
  memset(B, -1, sizeof(B));
  memset(C, -1, sizeof(C));
  memset(D, 0, sizeof(D));
  for (int i = 1; i <= n * m; i++)
    l[i] = 1e9, r[i] = 0;
  rep(i, 0, n - 1) sc(s[i]);
  rep(i, 0, m - 1) sc(a[i]);
  nep(i, n - 1, 0) rep(j, 0, m - 1) {
    if (i + 1 < n)
      D[i][j] = D[i + 1][j];
    if (s[i][j] == '#') {
      ok[id(i, j)] = true;
      D[i][j]++;
      if (D[i][j] == a[j])
        l[id(i, j)] = r[id(i, j)] = j + 1;
    }
  }
  nep(i, n - 1, 0) rep(j, 0, m - 1) {
    if (i + 1 < n) {
      A[i][j] = A[i + 1][j];
      B[i][j] = B[i + 1][j];
      C[i][j] = C[i + 1][j];
    }
    if (s[i][j] == '#') {
      if (A[i][j] != -1)
        add(id(i, j), A[i][j]);
      if (B[i][j] != -1)
        add(id(i, j), B[i][j]);
      if (C[i][j] != -1)
        add(id(i, j), C[i][j]);
      if (i - 1 >= 0 && s[i - 1][j] == '#')
        add(id(i, j), id(i - 1, j));
      if (i + 1 < n && s[i + 1][j] == '#')
        add(id(i, j), id(i + 1, j));
      if (j - 1 >= 0 && s[i][j - 1] == '#')
        add(id(i, j), id(i, j - 1));
      if (j + 1 < m && s[i][j + 1] == '#')
        add(id(i, j), id(i, j + 1));
    }
    if (j - 1 >= 0 && s[i][j - 1] == '#')
      A[i][j] = id(i, j - 1);
    if (j + 1 < m && s[i][j + 1] == '#')
      B[i][j] = id(i, j + 1);
    if (s[i][j] == '#')
      C[i][j] = id(i, j);
  }
  rep(i, 1, n * m) if (!dfn[i]) dfs(i);
  vis.clear();
  rep(i, 1, n * m) for (int v : e[i]) {
    int x = f[i], y = f[v];
    assert(ok[x]);
    assert(ok[y]);
    if (x == y)
      continue;
    if (!vis[make_pair(x, y)]) {
      vis[make_pair(x, y)] = true;
      d[x]++;
      hh[y]++;
      ee[x].push_back(y);
      re[y].push_back(x);
    }
  }
  for (int i = 1; i <= n * m; i++)
    l[f[i]] = min(l[f[i]], l[i]), r[f[i]] = max(r[f[i]], r[i]);
  for (int i = 1; i <= n * m; i++)
    if (f[i] == i && hh[i] == 0 && ok[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (l[u] <= r[u])
      fah[u] = true;
    for (int v : ee[u]) {
      hh[v]--;
      fah[v] |= fah[u];
      if (fah[u])
        l[v] = 1e9, r[v] = 0;
      if (hh[v] == 0)
        q.push(v);
    }
  }
  for (int i = 1; i <= n * m; i++)
    if (f[i] == i && d[i] == 0 && ok[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    if (l[u] <= r[u]) {
      seg[++t1] = {l[u], r[u]};
      hs[++t2] = l[u];
      hs[++t2] = r[u];
    }
    q.pop();
    for (int v : re[u]) {
      d[v]--;
      l[v] = min(l[v], l[u]);
      r[v] = max(r[v], r[u]);
      if (d[v] == 0)
        q.push(v);
    }
  }
  printf("%d\n", getans());
}
/*
7 8
####..#.
..#...##
*.#.*...
.#..#.##
.**...**
##...*..
....##..
2 2 1 0 3 2 1 1
*/