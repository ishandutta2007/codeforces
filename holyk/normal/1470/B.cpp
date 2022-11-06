#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, cnt0 = 0;
    std::cin >> n;
    std::map<std::vector<int>, int> cnt;
    while (n--) {
      int x;
      std::cin >> x;
      std::vector<int> v;
      for (int i = 2; i * i <= x; i++) {
        int c = 0;
        while (x % i == 0) x /= i, c++;
        if (c & 1) v.push_back(i);
      }
      if (x > 1) {
        v.push_back(x);
      }
      if (v.empty()) {
        cnt0++;
        continue;
      }
      cnt[v]++;
    }
    int ans0 = cnt0;
    for (auto &[x, c] : cnt) {
      smax(ans0, c);
      if (c & 1 ^ 1) {
        cnt0 += c;
      }
    }
    int ans1 = std::max(ans0, cnt0), q;
    std::cin >> q;
    while (q--) {
      LL x; std::cin >> x;
      std::cout << (x ? ans1 : ans0) << "\n";
    }
  }
  return 0;
}