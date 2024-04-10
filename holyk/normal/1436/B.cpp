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
    std::vector<int> a(n);
    a[0] = a[1] = 1;
    for (int i = 0; i < n; i++) {
      std::rotate(a.begin(), a.begin() + 1, a.end());
      for (int x: a) std::cout << x << " ";
      std::cout << "\n";
    }
  }
  return 0;
}