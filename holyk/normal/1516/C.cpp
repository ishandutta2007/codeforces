#include <bits/stdc++.h>
#include <numeric>
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
std::bitset<400005> f;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int g = 0;
  for (int &x : a) std::cin >> x, g = std::gcd(g, x);
  f.reset();
  f[200000] = 1;
  for (int x : a) f = (f << x) | (f >> x);
  if (!f[200000]) return puts("0"), 0;
  puts("1");
  for (int i = 0; i < n; i++) if (a[i] / g & 1) return printf("%d", i + 1), 0;
  return 0;
}