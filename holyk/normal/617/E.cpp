#include <bits/stdc++.h>
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

constexpr int N(1e6 + 5), T(300);
struct Qry {
  int l, r, id;
  int block() const {
    return l / T;
  }
  bool operator<(const Qry &rhs) const {
    int u = block(), v = rhs.block();
    return u == v ? u & 1 ? r < rhs.r : r > rhs.r : u < v;
  }
};
int a[N], cnt[N << 1];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] ^= a[i - 1];
  std::vector<Qry> q(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].l >> q[i].r;
    q[i].id = i;
    q[i].l--;
  }
  std::sort(q.begin(), q.end());
  int x = 0, y = -1;
  LL ans = 0;
  std::vector<LL> res(m);
  for (auto [l, r, id] : q) {
    while (x > l) ans += cnt[k ^ a[--x]], cnt[a[x]]++;
    while (y < r) ans += cnt[k ^ a[++y]], cnt[a[y]]++;
    while (x < l) cnt[a[x]]--, ans -= cnt[k ^ a[x++]];
    while (y > r) cnt[a[y]]--, ans -= cnt[k ^ a[y--]];
    res[id] = ans;
  }
  for (LL x : res) std::cout << x << "\n";
  return 0;
}