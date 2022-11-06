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
    for (int &x: a) std::cin >> x;
    auto mabs = [](int x) {
      return x >= 0 ? x : -x;
    };
    LL sum = 0;
    for (int i = n - 1; i; i--) {
      a[i] = a[i] - a[i - 1];
      sum += mabs(a[i]);
    }
    LL ans = std::min(sum - mabs(a[1]), sum - mabs(a[n - 1]));
    for (int i = 2; i < n; i++) {
      if (1LL * a[i] * a[i - 1] < 0)
        smin(ans, sum - 2 * std::min(mabs(a[i]), mabs(a[i - 1])));
    }
    std::cout << ans << "\n";
  }
  return 0;
}