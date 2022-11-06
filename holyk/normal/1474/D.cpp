#include <algorithm>
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
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::vector<LL> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = a[i] - s[i - 1];
    if (*std::min_element(s.begin(), s.end()) >= 0 && s.back() == 0) {
      puts("YES");
      continue;
    }
    std::array<LL, 2> sum = {0, 0};
    for (int i = 0; i < n; i++) sum[i & 1] += a[i];
    std::vector<LL> suf[2];
    suf[0].assign(n, 1e18), suf[1].assign(n, 1e18);
    suf[n - 1 & 1][n - 1] = s.back();
    for (int i = n - 2; i >= 0; i--) {
      suf[0][i] = suf[0][i + 1];
      suf[1][i] = suf[1][i + 1];
      smin(suf[i & 1][i], s[i]);
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      LL delta = (a[i] - a[i + 1]) * 2LL;
      // dbg("%lld %lld %d\n", sum[i & 1], sum[i & 1 ^ 1], delta);
      if (sum[i & 1] - delta == sum[i & 1 ^ 1] && s[i] >= delta / 2 && suf[i & 1][i + 1] >= delta && suf[i & 1 ^ 1][i + 1] + delta >= 0) {
        ok = true;
        break;
      }
      if (s[i] < 0) break;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}