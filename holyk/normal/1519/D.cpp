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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c;
  for (int &x : a) std::cin >> x;
  for (int &x : b) std::cin >> x;
  std::vector<LL> pre(n), suf(n);
  pre[0] = 1LL * a[0] * b[0];
  suf[n - 1] = 1LL * a[n - 1] * b[n - 1];
  for (int i = 1; i < n; i++) pre[i] = 1LL * a[i] * b[i] + pre[i - 1];
  for (int i = n - 2; i >= 0; i--) suf[i] = 1LL * a[i] * b[i] + suf[i + 1];
  c = b;
  std::reverse(c.begin(), c.end());
  std::vector<std::vector<LL>> s(n);
  for (int k = 0; k < n; k++) {
    s[k].resize(n);
    for (int i = 0; i < n; i++) s[k][i] = 1LL * a[i] * c[(i + k) % n] + (i ? s[k][i - 1] : 0);
  }
  LL ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      LL t = (i ? pre[i - 1] : 0) + (j < n - 1 ? suf[j + 1] : 0);
      int k = (n - j - 1 - i + n) % n;
      // dbg("%d %d %lld %lld %d\n", i + 1, j + 1, t, s[k][j] - (i ? s[k][i - 1] : 0), k);
      smax(ans, t + s[k][j] - (i ? s[k][i - 1] : 0));
    }
  std::cout << ans << "\n";
  return 0;
}