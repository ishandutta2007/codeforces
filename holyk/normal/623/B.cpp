// Author:  HolyK
// Created: Sun Jan 16 21:13:07 2022
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
using LL = long long;
using PII = std::pair<int, int>;

constexpr LL INF(1e12);

void solve() {
  int n, p, q;
  std::cin >> n >> p >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  
  int k = 0;
  // std::cin >> k;
  // for (int i = 0; i < k; i++) {
  //   int x;
  //   std::cin >> x;
  //   b[x - 1] = 1;
  // }
  
  auto cal = [&](int x) -> LL {
    std::array<LL, 3> f = {};
    for (int i = 0; i < n; i++) {
      LL c = a[i] % x == 0 ? 0 : (a[i] + 1) % x == 0 || (a[i] - 1) % x == 0 ? q : INF;
      f = {
        f[0] + c,
        std::min(f[0], f[1]) + (b[i] ? INF : p),
        std::min({f[0], f[1], f[2]}) + c
      };
    }
    return std::min({f[0], f[1], f[2]});
  };

  std::vector<int> fac;
  
  auto decom = [&](int x) {
    for (int i = 2; i * i <= x; i++) {
      if (x % i) continue;
      do x /= i; while (x % i == 0);
      fac.push_back(i);
    }
    if (x > 1) {
      fac.push_back(x);
    }
  };
  
  if (k) {
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        decom(a[i]);
        decom(a[i] + 1);
        decom(a[i] - 1);
        break;
      }
    }
  } else {
    decom(a[0]), decom(a[0] - 1), decom(a[0] + 1);
    decom(a[n - 1]), decom(a[n - 1] + 1), decom(a[n - 1] - 1);
  }

  std::sort(fac.begin(), fac.end());
  fac.erase(std::unique(fac.begin(), fac.end()), fac.end());

  LL ans = 1e18;
  for (auto x : fac) smin(ans, cal(x));
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}