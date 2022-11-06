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
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::priority_queue<PII> q;
    int max = 0;
    std::vector<int> ans(n);
    for (int i = 0; i < m; i++) q.emplace(-a[i], i), smax(max, a[i]), ans[i] = i;
    for (int i = m; i < n; i++) {
      auto [x, j] = q.top(); q.pop();
      smax(max, -x + a[i]);
      q.emplace(x - a[i], j);
      ans[i] = j;
    }
    if (max + q.top().first <= x) {
      std::cout << "YES\n";
      for (int x : ans) std::cout << x + 1 << " ";
      std::cout << "\n";
    } else {
      std::cout << "NO\n";
    }
    
  }
  return 0;
}