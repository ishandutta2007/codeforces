#include <algorithm>
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

constexpr int N(1e5 + 5), T(512);
struct Qry {
  int l, r, t, id;
  bool operator<(const Qry &rhs) const {
    return l / T == rhs.l / T ? r / T == rhs.r / T ? t < rhs.t : r > rhs.r : l < rhs.l;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;
  auto b = a, v = a;
  std::vector<Qry> q;
  std::vector<std::array<int, 3>> p;
  for (int i = 0; i < m; i++) {
    int opt, x, y;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      q.push_back({x - 1, y - 1, (int)p.size() - 1, (int)q.size()});
    } else {
      p.push_back({x - 1, b[x - 1], y});
      b[x - 1] = y;
      v.push_back(y);
    }
  }
  std::sort(v.begin(), v.end());
  v.resize(std::unique(v.begin(), v.end()) - v.begin());
  for (auto &x : a) x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
  for (auto &[i, x, y] : p) {
    x = std::lower_bound(v.begin(), v.end(), x) - v.begin();
    y = std::lower_bound(v.begin(), v.end(), y) - v.begin();
  }
  std::vector<int> c(v.size()), cc(n + 1);
  std::sort(q.begin(), q.end());
  int x = 0, y = -1, z = -1;
  std::vector<int> out(q.size());
  for (auto [l, r, t, id] : q) {
    while (x > l) {
      cc[c[a[--x]]]--;
      cc[++c[a[x]]]++;
    }
    while (y < r) {
      cc[c[a[++y]]]--;
      cc[++c[a[y]]]++;
    }
    while (x < l) {
      cc[c[a[x]]]--;
      cc[--c[a[x++]]]++;
    }
    while (y > r) {
      cc[c[a[y]]]--;
      cc[--c[a[y--]]]++;
    }
    while (z < t) {
      auto [i, x, y] = p[++z];
      a[i] = y;
      if (i < l || i > r) continue;
      cc[c[x]]--;
      cc[--c[x]]++;
      cc[c[y]]--;
      cc[++c[y]]++;
    }
    while (z > t) {
      auto [i, x, y] = p[z--];
      a[i] = x;
      if (i < l || i > r) continue;
      cc[c[y]]--;
      cc[--c[y]]++;
      cc[c[x]]--;
      cc[++c[x]]++;
    }
    out[id] = 1;
    while (cc[out[id]]) out[id]++;
  }
  for (int x : out) std::cout << x << "\n";
  return 0;
}