#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(3e5 + 5);
#define ls o << 1
#define rs o << 1 | 1
PII min[N << 2];
int cnt[N], c[N];
void build(int o, int l, int r) {
  if (l == r) {
    min[o] = { c[l], l };
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  min[o] = std::min(min[ls], min[rs]);
}
PII ask(int o, int l, int r, int x) {
  if (r <= x) return min[o];
  int m = l + r >> 1;
  if (x <= m) return ask(ls, l, m, x);
  return std::min(ask(ls, l, m, x), ask(rs, m + 1, r, x));
}
void update(int o, int l, int r, int x) {
  if (l == r) {
    min[o].first = INT_MAX;
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x) : update(rs, m + 1, r, x);
  min[o] = std::min(min[ls], min[rs]);
}
int main() {

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    memset(cnt, 0, m + 1 << 2);
    for (int i = 0; i < n; i++) {
      int x; std::cin >> x;
      cnt[x]++;
    }
    for (int i = 1; i <= m; i++) {
      std::cin >> c[i];
    }
    build(1, 1, m);
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 1);
    std::sort(p.begin(), p.end(), [](int i, int j) { return c[i] > c[j]; });
    LL ans = 0;
    for (auto i : p) {
      while (cnt[i]--) {
        auto v = ask(1, 1, m, i);
        if (v.first == INT_MAX) {
          ans += c[i];
        } else {
          ans += v.first;
          update(1, 1, m, v.second);
        }
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}