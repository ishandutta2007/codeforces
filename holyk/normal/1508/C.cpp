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

constexpr int N(2e5 + 5);
struct Dsu {
  std::vector<int> f;
  Dsu(int n) : f(n) {
    std::iota(f.begin(), f.end(), 0);
  }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  void merge(int x, int y) {
    f[find(x)] = find(y);
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> e(m);
  std::vector<std::vector<PII>> g(n);
  
  int xorSum = 0;
  for (auto &[z, x, y] : e) {
    std::cin >> x >> y >> z;
    x--, y--;
    g[x].emplace_back(y, z), g[y].emplace_back(x, z);
    xorSum ^= z;
  }
  std::sort(e.begin(), e.end());
  std::priority_queue<PII> q;
  std::priority_queue<std::array<int, 3>> q2;
  std::vector<int> deg(n);
  Dsu d(n), d2(n);
  auto add = [&](int x) {
    d.merge(0, x);
    for (auto [y, z] : g[x]) {
      if (d.same(0, y)) continue;
      deg[y]++;
      q.emplace(-deg[y], y);
      q2.push({-z, x, y});
    }
  };
  add(0);
  for (int i = 0; i < n; i++) q.emplace(0, i);
  int siz = 1, cnt = 0;
  LL ans = 0;
  while (siz < n) {
    auto [u, x] = q.top();
    if (-u != deg[x] || d.same(0, x)) {
      q.pop();
      continue;
    }
    if (deg[x] == siz) {
      while (d.same(0, q2.top()[2])) q2.pop();
      auto [z, x, y] = q2.top();
      add(y);
      d2.merge(x, y);
      ans += -z;
      dbg("add1: %d %d\n", x, -z);
    } else {
      add(x);
      cnt++;
      dbg("add0: %d\n", x);
    }
    siz++; 
  }
  if (cnt + m == 1LL * n * (n - 1) / 2) {
    ans += xorSum;
    for (auto &[z, x, y] : e) {
      if (d2.same(x, y)) continue;
      if (z < xorSum) {
        ans += z - xorSum;
        dbg("select: %d %d %d\n", x, y, z);
      }
      break;
    }
  }
  std::cout << ans << "\n";
  return 0;
}