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

constexpr int P(1e9 + 7);
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
int f[200015];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int i = 0; i <= 9; i++) f[i] = 1;
  for (int i = 10; i <= 10 + 2e5; i++) {
    f[i] = f[i - 10] + f[i - 9];
    if (f[i] >= P) f[i] -= P;
  }
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    int ans = 0;
    for (; n; n /= 10) {
      ans += f[n % 10 + m];
      if (ans >= P) ans -= P;
    }
    std::cout << ans << "\n";
  }
  return 0;
}