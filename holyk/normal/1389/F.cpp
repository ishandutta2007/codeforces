#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(4e5 + 5);
struct Interval {
  int l, r, t;
  bool operator<(const Interval &rhs) const {
    return r < rhs.r || r == rhs.r && l < rhs.l;
  }
};
class SegTree { // [l_, r_) SegTree
 public:
  void init(int l, int r) { l_ = l, r_ = r; }
  void add(int l, int r, int v) { add(1, l_, r_, l, r, v); }
  void update(int p, int v) { update(1, l_, r_, p, v); }
  int ask(int l, int r) { return ask(1, l_, r_, l, r); }

 private:
  int l_, r_;
  struct Node {
    int max, add;
  } t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
  void pushup(int o) {
    t[o].max = std::max(t[ls].max, t[rs].max);
  }
  void pushdown(int o) {
    if (t[o].add) {
      t[ls].add += t[o].add;
      t[rs].add += t[o].add;
      t[ls].max += t[o].add;
      t[rs].max += t[o].add;
      t[o].add = 0;
    }
  }
  void add(int o, int l, int r, int x, int y, int z) {
    if (x <= l && r <= y) {
      t[o].add += z, t[o].max += z;
      return;
    }
    pushdown(o);
    int m = l + r >> 1;
    if (x < m) add(ls, l, m, x, y, z);
    if (y > m) add(rs, m, r, x, y, z);
    pushup(o);
  }
  int ask(int o, int l, int r, int x, int y) {
    if (y <= l || x >= r) {
      return 0;
    }
    if (x <= l && r <= y) {
      return t[o].max;
    }
    pushdown(o);
    int m = l + r >> 1;
    return std::max(ask(ls, l, m, x, y), ask(rs, m, r, x, y));
  }
  void update(int o, int l, int r, int x, int y) {
    if (l == r - 1) {
      t[o].max = y;
      return;
    }
    pushdown(o);
    int m = l + r >> 1;
    x < m ? update(ls, l, m, x, y) : update(rs, m, r, x, y);
    pushup(o);
  }
#undef ls
#undef rs
} tree[2];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<Interval> a(n);
  std::vector<int> b;
  b.reserve(n * 2);
  for (auto &[l, r, t] : a) std::cin >> l >> r >> t, b.push_back(l), b.push_back(r);
  std::sort(b.begin(), b.end());
  b.resize(std::unique(b.begin(), b.end()) - b.begin());
  tree[0].init(-1, b.size());
  tree[1].init(-1, b.size());
  std::sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    auto &[l, r, t] = a[i];
    l = std::lower_bound(b.begin(), b.end(), l) - b.begin();
    r = std::lower_bound(b.begin(), b.end(), r) - b.begin();
    t--;
    auto &p = tree[t], &q = tree[t ^ 1];
    p.add(-1, l, 1);
    q.update(r, p.ask(-1, l));
  }
  std::cout << std::max(tree[0].ask(-1, b.size()), tree[1].ask(-1, b.size()));
  return 0;
}