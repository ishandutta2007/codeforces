#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

constexpr int N(2e5 + 5);
int n, a[N], head[N];
struct Edge {
  int v, w, next;
} e[N << 1];
void addEdge(int x, int y, int z) {
  static int c = 0;
  e[++c] = { y, z, head[x] }, head[x] = c;
  e[++c] = { x, z, head[y] }, head[y] = c;
}
bool vis[N];
int rt, tSize, mSize, siz[N];
void getSize(int x, int fa) {
  siz[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].v;
    if (y == fa || vis[y])  continue;
    getSize(y, x);
    siz[x] += siz[y];
  }
}
void findrt(int x, int fa) {
  int max = tSize - siz[x];
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].v;
    if (y == fa || vis[y]) continue;
    findrt(y, x);
    smax(max, siz[y]);
  }
  if (smin(mSize, max)) rt = x;
}
double ans = INFINITY, f, diff;
int pos;
void dfs(int x, int fa, int d) {
  f += a[x] * sqrt(d) * d, diff += a[x] * sqrt(d);
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].v;
    if (y == fa) continue;
    dfs(y, x, d + e[i].w);
  }
}
void solve(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  int p;
  double s = 0, m = 0;
  f = 0;
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].v;
    diff = 0;
    dfs(y, x, e[i].w);
    if (smax(m, diff)) p = y;
    s += diff;
  }
  if (smin(ans, f)) pos = x;
  if (m * 2 > s && !vis[p]) {
    getSize(p, 0);
    tSize = mSize = siz[p];
    findrt(p, 0);
    solve(rt);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1, x, y, z; i < n; i++) {
    std::cin >> x >> y >> z;
    addEdge(x, y, z);
  }
  getSize(1, 0), tSize = mSize = n, findrt(1, 0), solve(rt);
  printf("%d %.10f", pos, ans);
  return 0;
}