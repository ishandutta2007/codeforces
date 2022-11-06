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

constexpr int N(1e6 + 5);
int c[N], n;
inline void add(int p, int x) {
  for (; p; p -= p & -p) c[p] += x;
}
inline int ask(int p) {
  int r = 0;
  for (; p <= n; p += p & -p) r += c[p];
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  std::map<int, int> cnt;
  for (int &x : a ) std::cin >> x;
  for (int i = 0; i < n; i++) {
    b[i] = ++cnt[a[i]];
  }
  cnt.clear();
  for (int i = n - 1; i >= 0; i--) {
    c[i] = ++cnt[a[i]];
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    ans += ask(c[i] + 1);
    add(b[i], 1);
  }
  std::cout << ans << "\n";
  return 0;

}