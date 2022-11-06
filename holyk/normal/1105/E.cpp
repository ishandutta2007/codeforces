#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
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

int id(std::string s) {
  static std::map<std::string, int> p;
  auto &x = p[s];
  return (x ? x : x = p.size()) - 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<uint64_t> g(m);
  while (n--) {
    int opt;
    std::cin >> opt;
    static uint64_t now;
    static std::vector<int> p;  
    if (opt == 2) {
      std::string s;
      std::cin >> s;
      int t = id(s);
      p.push_back(t);
      now |= 1ull << t;
    }
    if (opt == 1 || !n) {
      for (auto x : p) g[x] |= now;
      p.clear();
      now = 0;
    }
  }
  int t = m >> 1, ans = 0, base = (1 << t) - 1;
  std::vector<int> f(1 << t), h(1 << (m - t)), to(1 << (m - t)), p(1 << (m - t));
  for (int i = 0; i < 1 << t; i++) {
    for (int j = 0; j < t; j++) {
      if (i >> j & 1) continue;
      smax(f[i | 1 << j], f[i] + !(g[j] & i));
    }
  }
  for (int i = 0; i < m - t; i++) p[1 << i] = i + t;
  for (int i = 0; i < 1 << (m - t); i++) {
    if (i) to[i] = to[i & i - 1] | (g[p[i & -i]] & base);
    for (int j = 0; j < (m - t); j++) {
      if (i >> j & 1) continue;
      smax(h[i | 1 << j], h[i] + !(g[j + t] >> t & i));
    }
    smax(ans, h[i] + f[base ^ to[i]]);
  }
  std::cout << ans << "\n";
  return 0;
}