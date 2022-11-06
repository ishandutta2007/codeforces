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
    uint64_t n;
    std::cin >> n;
    if (n & 1) {
      std::cout << "-1\n";
      continue;
    }
    n >>= 1;
    int c = n & 1, m = 0;
    std::string ans = "";
    for (int i = 1; n >> i; i++)
      if (n >> i & 1) {
        c++;
        ans += "1 ", m++;
        for (int j = 1; j < i; j++)
          ans += "0 ", m++;
      }
    while (c--) ans += "1 ", m++;
    std::cout << m << "\n" << ans << "\n";
  }
  return 0;
}