#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e5 + 5);
int n, l_, r_, a[N];
std::vector<PII> g[N];
bool vis[N];
namespace Centroid {
int tSize, mSize, root, siz[N];
void getSize(int x, int fa) {
  siz[x] = 1;
  for (auto [y, z] : g[x]) {
    if (y == fa || vis[y]) continue;
    getSize(y, x);
    siz[x] += siz[y];
  }
}
void getRoot(int x, int fa) {
  int m = tSize - siz[x];
  for (auto [y, z] : g[x]) {
    if (y == fa || vis[y]) continue;
    getRoot(y, x);
    smax(m, siz[y]);
  }
  if (smin(mSize, m)) root = x;
}
int getRoot(int x) {
  getSize(x, 0);
  tSize = mSize = siz[x];
  getRoot(x, 0);
  return root;
}
void divide(int x) {
  x = getRoot(x);
  a[++a[0]] = x;
  vis[x] = 1;
  for (auto [y, z] : g[x]) {
    if (!vis[y]) {
      divide(y);
    }
  }
}
}
// Persistent SegTree
struct Node {
  Node *ls, *rs;
  PII max;
} t[N << 2], *ptr, *root;
void update(Node *&o, int l, int r, int x, PII y) {
  if (!o) o = ptr++, o->ls = o->rs = nullptr, o->max = PII(-1e9, 0);
  smax(o->max, y);
  if (l == r) return;
  int m = l + r >> 1;
  x <= m ? update(o->ls, l, m, x, y) : update(o->rs, m + 1, r, x, y);
}
PII ask(Node *o, int l, int r, int x, int y) {
  if (!o || x > r || y < l) return PII(-1e9, 0);
  if (x <= l && r <= y) return o->max;
  int m = l + r >> 1;
  return std::max(ask(o->ls, l, m, x, y), ask(o->rs, m + 1, r, x, y));
}
int val, u_, v_;
bool ask(int x, int fa, int d, int v) {
  PII t = ask(root, 0, r_, l_ - d, r_ - d);
  if (t.first + v >= 0) {
    u_ = t.second, v_ = x;
    return true;
  }
  if (d == r_) return false;
  for (auto [y, z] : g[x]) {
    if (y == fa || vis[y]) continue;
    if (ask(y, x, d + 1, v + (z >= val ? 1 : -1)))
      return true;
  }
  return false;
}
void add(int x, int fa, int d, int v) {
  update(root, 0, r_, d, PII(v, x));
  if (d == r_) return;
  for (auto [y, z] : g[x]) {
    if (y == fa || vis[y]) continue;
    add(y, x, d + 1, v + (z >= val ? 1 : -1));
  }
}
bool solve() {
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    ptr = t, root = nullptr;
    update(root, 0, r_, 0, PII(0, x));
    for (auto [y, z] : g[x]) {
      if (vis[y]) continue;
      if (ask(y, x, 1, z >= val ? 1 : -1))
        return true;
      add(y, x, 1, z >= val ? 1 : -1);
    }
    vis[x] = 1;
  }
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> l_ >> r_;
  int l = 0, r = 0;
  for (int i = 1, x, y, z; i < n; i++) {
    std::cin >> x >> y >> z;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
    smax(r, z);
  }
  Centroid::divide(1);
  while (l <= r) {
    val = l + r >> 1;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    if (solve())
      l = val + 1;
    else
      r = val - 1;
  }
  std::cout << u_ << " " << v_ << "\n";
  return 0;
}