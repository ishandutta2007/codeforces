#include <bits/stdc++.h>
#include <cstdint>
#include <stdint.h>
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

using PLL = std::pair<uint64_t, uint64_t>;
constexpr uint64_t P(1e9 + 7);
inline PLL operator+(PLL a, PLL b) {
  return {a.first + b.first, (a.second + b.second) % P};
}
inline PLL operator-(PLL a, PLL b) {
  return {a.first - b.first, (a.second + P - b.second) % P};
}
inline PLL operator*(PLL a, PLL b) {
  return {a.first * b.first, a.second * b.second % P};
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  std::vector<PLL> p(n + 1), base(k + 1);
  base[0] = {1, 1};
  base[1] = {31, 131};
  for (int i = 2; i <= k; i++) base[i] = base[i - 1] * base[1];
  // dbg("%llu %llu\n", base[k].first, base[k].second);
  int ans = 0;
  std::map<PLL, std::vector<int>> cnt;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base[1] + PLL(s[i - 1], s[i - 1]);
    // dbg("%llu %llu\n", p[i].first, p[i].second);
    if (i - k >= 0) {
      cnt[p[i] - p[i - k] * base[k]].push_back(i);
    }
  }
  for (int c = 'a'; c <= 'z'; c++) {
    PLL u;
    for (int i = 1; i <= k; i++) u = u * base[1] + PLL{c, c};
    auto &v = cnt[u];
    std::vector<int> f(v.size());
    // dbg("%llu %llu : ", x.first, x.second);
    // for (int u : v) dbg("%d ", u);
    // dbg("\n");
    for (int i = 0, j = -1; i < v.size(); i++) {
      while (v[i] - v[j + 1] >= k) j++;
      f[i] = j >= 0 ? f[j] + 1 : 1;
      smax(ans, f[i]);
    }
  }
  std::cout << ans << "\n";
  return 0;
}