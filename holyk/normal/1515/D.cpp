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
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(l), b(r);
    for (int &x : a) std::cin >> x;
    for (int &x : b) std::cin >> x;
    if (l < r) std::swap(l, r), std::swap(a, b);
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int ans = 0;
    std::vector<int> vis(l);
    int last = -1;
    for (int i = 0, j = 0; i < r; i++) {
      while (j < l && a[j] < b[i]) j++;
      if (j < l && a[j] == b[i]) vis[j++] = 1;
      else {
        ans++;
      }
    }
    std::vector<int> c(n);
    for (int i = 0; i < l; i++) {
      if (vis[i]) continue;
      c[a[i] - 1]++;
    }
    int sum = 0;
    for (int x : c) sum += x / 2;
    ans += std::max(0, (l - r) / 2 - sum) + (l - r) / 2;
    std::cout << ans << "\n";
  }
  return 0;
}