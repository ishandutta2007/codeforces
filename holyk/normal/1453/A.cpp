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
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int &x: a) std::cin >> x;
    for (int &x: b) std::cin >> x;
    int ans = 0;
    for (int x: a)
      if (std::binary_search(b.begin(), b.end(), x))
        ans++;
    std::cout << ans << "\n";
  }
  return 0;
}