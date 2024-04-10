#include <bits/stdc++.h>

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(2e5 + 10);
class SegTree {
#define ls o << 1
#define rs o << 1 | 1
public:
  void init(int l, int r) {
    l_ = l, r_ = r;
    memset(max, 0, sizeof max);
  }
  void update(int x, int y) {
    update(1, l_, r_, x, y);
  }
  int ask(int x) {
    if (x > r_) return 0;
    return ask(1, l_, r_, x, r_);
  }
private:
  int max[N << 2];
  void update(int o, int l, int r, int x, int y) {
    if (l == r) {
      max[o] = y;
      return;
    }
    int m = l + r >> 1;
    x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
    max[o] = std::max(max[ls], max[rs]);
  }
  int ask(int o, int l, int r, int x, int y) {
    if (x > r || y < l || x > y) return 0;
    if (x <= l && r <= y) return max[o];
    int m = l + r >> 1;
    return std::max(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
  }
  int l_, r_;
#undef ls
#undef rs
} th, tp;
std::map<int, int> p, h;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  th.init(-m, 10);
  tp.init(1, n);
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    std::cin >> opt >> x;
    if (opt == 1) {
      std::cin >> y;
      y -= i;
      p[x] = y;
      h[y] = x;
      auto u = h.begin();
      for (; u->first != y; u++) {
        th.update(u->first, 0);
        tp.update(u->second, 0);
      }
      u++;
      do {
        auto [h, p] = *--u;
        int len = tp.ask(p + 1) + 1;
        th.update(h, len);
        tp.update(p, len);
      } while (u != h.begin());
      
    } else {
      assert(x <= p.size());
      auto it = std::next(p.begin(), x - 1);
      tp.update(it->first, 0);
      th.update(it->second, 0);
      std::vector<PII> v;
      h.erase(h.find(it->second));
      for (auto u = p.begin(); u != it; u++) {
        tp.update(u->first, 0);
        th.update(u->second, 0);
        v.push_back(*u);
      }
      p.erase(it);
      std::reverse(v.begin(), v.end());
      for (auto [p, h] : v) {
        int len = th.ask(h + 1) + 1;
        th.update(h, len);
        tp.update(p, len);
      }
    }
    std::cout << tp.ask(1) << "\n";
  }
  return 0;
}