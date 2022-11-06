// Author:  HolyK
// Created: Sun Mar  6 19:02:06 2022
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

constexpr int N(5e5 + 5);
LL a[3][N];
#define ls o * 2
#define rs o * 2 + 1
struct SegTree1 {
  struct Info {
    LL m1, m2, ans;
    friend Info operator+(Info a, Info b) {
      return {
        std::max(a.m1, b.m1),
        std::max(a.m2, b.m2),
        std::max({a.ans, b.ans, a.m1 + b.m2})
      };
    }
  } t[N << 2];
  void build(int o, int l, int r) {
    if (l == r) {
      t[o] = {
        a[0][l] - a[1][l - 1],
        a[2][r] + a[1][r],
        a[0][l] + a[1][l] - a[1][l - 1] + a[2][r]
      };
      return;
    }
    int m = l + r >> 1;
    build(ls, l, m), build(rs, m + 1, r);
    t[o] = t[ls] + t[rs];
  }

  void update(int o, int l, int r, int x, LL y) {
    if (l == r) {
      smax(t[o].m1, y);
      smax(t[o].ans, t[o].m1 + t[o].m2);
      return;
    }

    int m = l + r >> 1;
    if (x <= m) {
      update(ls, l, m, x, y);
    } else {
      update(rs, m + 1, r, x, y);
    }
    t[o] = t[ls] + t[rs];
  }
  Info ask(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[o];
    int m = l + r >> 1;
    if (y <= m) return ask(ls, l, m, x, y);
    if (x > m) return ask(rs, m + 1, r, x, y);
    return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
  }
} t1;

std::vector<PII> g[N];
void solve() {
  int n, q;
  std::cin >> n >> q;
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
    if (i < 2) {
      for (int j = 1; j <= n; j++) {
        a[i][j] += a[i][j - 1];
      }
    } else {
      for (int j = n; j >= 1; j--) {
        a[i][j] += a[i][j + 1];
      }
    }

    // for (int j = 1; j <= n; j++) {
    //   std::cerr << a[i][j] << " \n"[j == n];
    // }
  }
  t1.build(1, 1, n);

  LL ans = LLONG_MIN;
  for (int i = 1; i <= q; i++) {
    int l, r, k;
    std::cin >> l >> r >> k;
    g[r].push_back({l, k});
    // smax(ans, t1.ask(1, 1, n, l, r).ans - k);
  }

  for (int i = 1; i <= n; i++) {
    for (auto [l, k] : g[i]) {
      auto [m1, m2, a] = t1.ask(1, 1, n, l, i);
      // std::cerr << l << " " << i << " " << k << " : " << m1 << " " << m2 << " " << a << "\n";
      smax(ans, a - k);
      if (i < n) t1.update(1, 1, n, i + 1, m1 - k);
    }
  }

  std::cout << ans << "\n";
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