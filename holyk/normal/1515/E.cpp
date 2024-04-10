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

int n, m, f[404][404], c[404][404];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  f[1][1] = 1;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % m;
  }
  for (int i = 2; i <= n; i++) {
    f[i][i] = f[i - 1][i - 1] * 2LL % m;
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k <= i; k++) {
        f[i][j] = (f[i][j] + 1LL * f[k][k] * f[i - k][j - k - 1] % m * c[i][k]) % m;
      }
    }
  }
  // for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) std::cout << f[i][j] << " \n"[j == n]; 
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += f[i][n], ans %= m;
  std::cout << ans << "\n";
  return 0;
}