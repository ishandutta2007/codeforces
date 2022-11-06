// Author:  HolyK
// Created: Thu Mar 10 10:27:21 2022
#include <bits/stdc++.h>

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

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  std::vector<std::array<int, 4>> b(m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    x--;
    b[i] = {x, y, z, i};
  }

  std::sort(b.begin(), b.end());
  std::vector<int> ans, v(n, 1e9);

  for (int i = 0, j; i < m; i = j) {
    for (j = i + 1; j < m && b[i][0] == b[j][0]; j++) ;
    std::vector f(100, 1e9 + 1);
    std::vector g(j - i, std::vector<int>(100, -1));
//    std::cerr << "!! " << b[i][0] << "\n";
    for (int k = 0; k < j - i; k++) {
      auto [_, y, z, id] = b[k + i];
      for (int w = 99; w >= 0; w--) {
        if (smin(f[w], (w >= z ? f[w - z] : 0) + y)) {
          g[k][w] = k + i;
        }
      }
    }

    v[b[i][0]] = f.back();
    if (f.back() == 1e9 + 1) break;
    
    for (int w = 99, k = j - i - 1; w >= 0; k--) {
      // if (k < 0) {
      //   std::cerr << "err " << b[i][0] << "\n";
      //   return;
      // }
      // std::cerr << "! " << b[i][0] << " " << w << " " << g[k][w] << "\n";;
      if (g[k][w] >= 0) {
        ans.push_back(b[g[k][w]][3] + 1);
        w -= b[g[k][w]][2];
      }
      
    }
  }
  
  for (int i = 0, s = 0; i < n; i++) {
    s += v[i];
    if (s > a[i]) {
      std::cout << "-1\n";
      return;
    }
  }

  std::cout << ans.size() << "\n";

  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
   int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    //  std::cerr << "case:\n";
    solve();
  }
  return 0;
}