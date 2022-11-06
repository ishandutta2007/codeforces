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

constexpr int P(998244353);
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
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    LL s = 0, t;
    for (int i = 0; i < n; i++) std::cin >> a[i], s += a[i];
    s = (s + 1 >> 1) - 1;
    int ans = 1;
    t = 0;
    for (int i = n - 1; i >= 0; i--) {
      t += a[i];
      if (t <= s) ans++;
      else break;
    }
    std::vector<LL> sum(n);
    sum[0] = a[0];
    if (n > 1) sum[1] = a[1];
    for (int i = 2; i < n; i++) {
      sum[i] = a[i] + sum[i - 2];
    }
    t = 0;
    for (int i = 0; i < n - 1; i++) {
      t += a[i];
      if (t > s) break;
      int r = i;
      for (int j = 18; j >= 0; j--) {
        int k = r + (2 << j);
        if (k < n && sum[k] - sum[i] + t <= s) r = k;
      }
      inc(ans, (r - i + 2) / 2);
      if (i > n - 4 || t + a.back() > s) continue;
      r = i;
      for (int j = 18; j >= 0; j--) {
        int k = r + (2 << j);
        if (k < n - 3 && sum[k] - sum[i] + t + a.back() <= s) r = k;
      }
      inc(ans, (r - i + 2) / 2);
    }
    t = 0;
    for (int i = 1; i < n - 1; i++) {
      t += a[i];
      if (t > s) break;
      int r = i;
      for (int j = 18; j >= 0; j--) {
        int k = r + (2 << j);
        if (k < n && sum[k] - sum[i] + t <= s) r = k;
      }
      // dbg("a %d %d\n", i, r);
      inc(ans, (r - i + 2) / 2);
      if (i > n - 4 || t + a.back() > s) continue;
      r = i;
      for (int j = 18; j >= 0; j--) {
        int k = r + (2 << j);
        if (k < n - 3 && sum[k] - sum[i] + t + a.back() <= s) r = k;
      }
      inc(ans, (r - i + 2) / 2);
      // dbg("b %d %d\n", i, r);
    }
    std::cout << ans % P << "\n";
  }
  return 0;
}