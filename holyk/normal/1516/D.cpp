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

constexpr int N(1e5 + 5);
int f[18][N], g[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    int &r = f[0][i] = f[0][i - 1];
    for (int j = 2; j * j <= x; j++) {
      if (x % j) continue;
      smax(r, g[j]);
      g[j] = i;
      while (x % j == 0) x /= j; 
    }
    if (x > 1) smax(r, g[x]), g[x] = i;
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }
  while (m--) {
    int l, r;
    std::cin >> l >> r;
    int ans = 1;
    for (int i = 17; i >= 0; i--) {
      if (f[i][r] >= l) ans += 1 << i, r = f[i][r];
    }
    std::cout << ans << "\n";
  }
  return 0;
}