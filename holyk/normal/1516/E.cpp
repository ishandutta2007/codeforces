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
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  int m = std::min(2 * k, n);
  std::vector f(m + 1, std::vector<int>(k + 1)), g = f;
  std::vector<int> fac(m + 1), inv(m + 1);
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= m; i++) {
    fac[i] = 1LL * fac[i - 1] * i % P;
    inv[i] = fpow(fac[i]);
  }
  auto binom = [&](int n, int m)->int {
    assert(m >= 0 && m <= n);
    return 1LL * fac[n] * inv[m] % P * inv[n - m] % P;
  };
  for (int i = 1; i <= m; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      f[i][j] = (f[i - 1][j] + 1LL * (i - 1) * f[i - 1][j - 1]) % P; 
    }
  }
  std::vector<int> c(m + 1), ans(k + 1);
  c[0] = 1;
  for (int i = 1; i <= m; i++) c[i] = 1LL * c[i - 1] * (n - i + 1) % P * fpow(i) % P;
  ans[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= m; j++) {
      for (int t = 0; t <= j; t++) {
        ans[i] = (ans[i] + 1LL * (t & 1 ? P - c[j] : c[j]) * binom(j, t) % P * f[j - t][i]) % P;
      }
    }
    if (i >= 2) inc(ans[i], ans[i - 2]);
    std::cout << ans[i] << " \n"[i == k];
  }
  return 0;
}