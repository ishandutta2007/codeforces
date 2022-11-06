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

constexpr int N(1e5 + 5), P(998244353);
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  
  int cnt = 0;
  std::vector<std::string> s(n);
  for (auto &v : s) {
    std::cin >> v;
    for (auto c : v) if (c == 'o') cnt++;
  }
  std::vector<int> f(cnt + 3);
  f[0] = f[1] = 0;
  for (int i = 2; i < f.size(); i++) {
    f[i] = (f[i - 1] + f[i - 2] + 499122177LL) % P * 499122177LL % P;
  }
  for (int i = 0, x = 1; i < f.size(); i++, x = 2LL * x % P) f[i] = 1LL * f[i] * x % P;
  int ans = 0;
  for (auto &v : s) {
    for (int i = 0, j; i < m; i = j) {
      for (j = i; j < m && v[i] == v[j]; j++) ;
      if (v[i] == 'o') {
        ans = (ans + 1LL * (f[j - i]) * fpow(2, cnt - j + i)) % P;
      }
    }
  }
  for (int k = 0; k < m; k++) {
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i][k] == s[j][k]; j++) ;
      if (s[i][k] == 'o') {
        ans = (ans + 1LL * (f[j - i]) * fpow(2, cnt - j + i)) % P;
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}