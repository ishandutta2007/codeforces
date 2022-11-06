// Author:  HolyK
// Created: Thu Mar 17 14:46:27 2022
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

struct LB {
  int p[20], t[20];
  void ins(int x, int y) {
    for (int i = 19; i >= 0; i--) {
      if (~x >> i & 1) continue;
      if (!p[i]) {
        p[i] = x;
        t[i] = y;
        break;
      } else {
        if (y > t[i]) {
          std::swap(p[i], x);
          std::swap(t[i], y);
        }
        x ^= p[i];
      }
    }
  }

  int ask(int k) {
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
      if (t[i] >= k) {
        smax(ans, ans ^ p[i]);
      }
    }
    return ans;
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<LB> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (i) a[i] = a[i - 1];
    a[i].ins(x, i);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    std::cout << a[r].ask(l) << "\n";
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}