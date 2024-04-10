#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(3e5 + 5);
int n;
std::vector<int> g[N];
std::vector<PII> p[N];

struct Node {
  Node *ls, *rs;
  LL val, tag;
  int dep;
  Node(LL v, int d) : ls(nullptr), rs(nullptr), val(v), tag(0), dep(d) {}
  void add(LL x) {
    val += x;
    tag += x;
  }
  void pushdown() {
    if (tag) {
      if (ls) ls->add(tag);
      if (rs) rs->add(tag);
      tag = 0;
    }
  }
} *root[N];
Node *merge(Node *x, Node *y) {
  if (!x) return y;
  if (!y) return x;
  static std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  if (x->val > y->val) std::swap(x, y);
  x->pushdown(), y->pushdown();
  if (rnd() & 1) {
    x->rs = merge(x->rs, y);
  } else {
    x->ls = merge(x->ls, y);
  }
  return x;
}
int dep[N];
void update(int x) {
  while (root[x] && root[x]->dep >= dep[x] + (x == 1)) {
    root[x]->pushdown();
    root[x] = merge(root[x]->ls, root[x]->rs);
  }
  if (!root[x]) {
    puts("-1");
    exit(0);
  }
}
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  if (x > 1 && g[x].size() == 1) {
    for (auto [f, v] : p[x]) {
      root[x] = merge(root[x], new Node(v, dep[f]));
      // update(x);
    }
    update(x);
    return;
  }
  for (int y : g[x]) {
    if (y == fa) continue;
    dfs(y, x);
    if (root[x]) {
      LL v = root[x]->val;
      assert(root[y]);
      root[x]->add(root[y]->val);
      root[y]->add(v);
    }
    root[x] = merge(root[x], root[y]);
    // update(x);
  }
  for (auto [f, v] : p[x]) {
    assert(root[x]);
    root[x] = merge(root[x], new Node(v + root[x]->val, dep[f]));
    // update(x);
  }
  update(x);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int m;
  std::cin >> n >> m;
  if (n == 1) return puts("0"), 0;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x == y) continue;
    p[x].emplace_back(y, z);
  }
  dfs(1, 0);
  assert(root[1]);
  std::cout << root[1]->val << "\n";
  return 0;
}