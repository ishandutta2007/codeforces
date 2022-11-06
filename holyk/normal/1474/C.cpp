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
    std::vector<int> a(n <<= 1);
    for (int &x : a) std::cin >> x;
    if (n == 2) {
      std::cout << "YES\n" << a[0] + a[1] << "\n" << a[0] << " " << a[1] << "\n";
      continue;
    }
    std::sort(a.begin(), a.end());
    auto get = [&](std::multiset<int> s, int x) {
      std::vector<PII> ans;
      while (!s.empty()) {
        assert(s.size() & 1 ^ 1);
        int u = *s.rbegin();
        int v = x - u;
        s.erase(--s.end());
        auto it = s.find(v);
        if (it == s.end()) return std::vector<PII>();
        ans.emplace_back(u, v);
        s.erase(it);
        x = u;
      }
      return ans;
    };
    auto solve = [&] {
      for (int i = 0; i < n - 1; i++) {
        std::multiset<int> s;
        for (int j = 0; j < n - 1; j++) {
          if (j != i) s.insert(a[j]);
        }
        auto ans = get(s, a.back());
        if (ans.empty()) continue;
        ans.emplace(ans.begin(), a.back(), a[i]);
        return ans;
      }
      return std::vector<PII>();
    };
    auto ans = solve();
    if (ans.empty()) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << ans[0].first + ans[0].second << "\n";
      for (auto [x, y] : ans) std::cout << x << " " << y << "\n";
    }
  }
  return 0;
}