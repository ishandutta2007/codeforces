#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<std::string> a(n);
    for (auto &s: a) std::cin >> s;
    for (int d = 0; d < 10; d++) {
      int ans = 0;
      int minx, miny, maxx, maxy;
      minx = miny = n, maxx = maxy = -1;
      auto mabs = [](int x) { return x > 0 ? x : -x; };
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          if (a[i][j] == '0' + d) {
            smin(minx, i), smax(maxx, i);
            smin(miny, j), smax(maxy, j);
          }
      }
      for (int i = 0; i < n; i++) {
        int l = 0;
        while (l < n && a[i][l] != '0' + d) l++;
        if (l == n) continue;
        int r = n - 1;
        while (r >= 0 && a[i][r] != '0' + d) r--;
        smax(ans, (r - l) * std::max(n - 1 - i, i));
        smax(ans, std::max(r, n - 1 - l) * std::max(maxx - i, i - minx));
      }
      for (int i = 0; i < n; i++) {
        int l = 0;
        while (l < n && a[l][i] != '0' + d) l++;
        if (l == n) continue;
        int r = n - 1;
        while (r >= 0 && a[r][i] != '0' + d) r--;
        smax(ans, (r - l) * std::max(n - 1 - i, i));
        smax(ans, std::max(r, n - 1 - l) * std::max(maxy - i, i - miny));
      }
      std::cout << ans << " ";
    }
    std::cout << "\n";
  }
  return 0;
}