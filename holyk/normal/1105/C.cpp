#include <bits/stdc++.h>
#include <valarray>
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
std::valarray<int> get(int x) {
  return {(x + 3) / 3, (x + 2) / 3, (x + 1) / 3};
}
std::valarray<int> operator*(std::valarray<int> a, std::valarray<int> b) {
  std::valarray r{0, 0, 0};
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
    int t = (i + j) % 3;
    r[t] = (r[t] + 1LL * a[i] * b[j]) % P;
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, l, r;
  std::cin >> n >> l >> r;
  std::valarray<int> u = get(r) - get(l - 1), v = {1, 0, 0};
  while (n--) {
    v = v * u;
  }
  std::cout << v[0];
  return 0;
}