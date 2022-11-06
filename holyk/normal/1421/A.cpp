#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int a, b; std::cin >> a >> b;
    int ans = 0;
    for (int i = 1; a || b; i <<= 1, a >>= 1, b >>= 1) {
      int x = a & 1, y = b & 1;
      if (x == y) continue;
      ans += i;
    }
    std::cout << ans << "\n";
  }
  return 0;
}