#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int P(1e9 + 7);
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, x, p; std::cin >> n >> x >> p;
  std::vector<int> a, b;
  auto perm = [&](int n, int m) {
    if (n < m) return 0LL;
    LL ans = 1;
    for (int i = n - m + 1; i <= n; i++) (ans *= i) %= P;
    return ans;
  };
  p++;
  int l = 0, r = n;
  while (l < r) {
    int m = l + r >> 1;
    if (m < p) {
      if (m != p - 1) a.push_back(m);
      l = m + 1;
    } else {
      if (m != p - 1) b.push_back(m);
      r = m;
    }
  }
  std::cout << perm(x - 1, a.size()) * perm(n - x, b.size()) % P * perm(n - 1 - a.size() - b.size(), n - 1 - a.size() - b.size()) % P;
  return 0;
}