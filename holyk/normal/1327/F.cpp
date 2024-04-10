#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int P(998244353);
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k, m;
  std::cin >> n >> k >> m;
  std::vector<std::array<int, 3>> a(m);
  for (auto &[x, y, z] : a) {
    std::cin >> x >> y >> z;
  }
  int ans = 1;
  while (k--) {
    std::vector<int> l(n + 2), s(n + 2);
    for (auto &[x, y, z] : a) {
      if (z >> k & 1) {
        s[x]++, s[y + 1]--;
      } else {
        smax(l[y + 1], x);
      }
    }
    for (int i = 1; i <= n; i++) smax(l[i + 1], l[i]);
    std::vector<int> f(n + 2);
    f[0] = 1;
    for (int i = 1; i <= n + 1; i++) {
      s[i] += s[i - 1];
      f[i] = f[i - 1];
      if (s[i]) continue;
      f[i] += f[i] - (l[i] ? f[l[i] - 1] : 0);
      if (f[i] < 0) f[i] += P;
      if (f[i] >= P) f[i] -= P;
    }
    ans = ans * (LL(f[n + 1]) - f[n] + P) % P;
  }
  std::cout << ans << "\n";
  return 0;
}