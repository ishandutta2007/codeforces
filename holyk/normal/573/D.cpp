// Author:  HolyK(Asuka Kyle)
// Created: Mon Jan 10 22:00:31 2022
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
using Vector = std::array<LL, 3>;
using Matrix = std::array<Vector, 3>;
Matrix operator*(Matrix a, Matrix b) {
  Matrix c;
  for (int i = 0; i < 3; i++) {
    c[i].fill(-1e18);
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < 3; j++) {
        smax(c[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return c;
}

constexpr int N(30005);

int n, m, s, a[N], b[N], pa[N], pb[N], ap[N], bp[N];
Matrix t[1 << 20];
void cal(int i) {
  int p[] = {0, 1, 2};
  Vector c;
  c.fill(-1e18);
  do {
    LL s = 0;
    for (int j = 0; j < 3 && i - j > 0 && i - p[j] > 0; j++) {
      int x = pa[i - j], y = pb[i - p[j]];
      if (x == y) break;
      s += 1LL * a[x] * b[y];
      smax(c[j], s);
    }
  } while (std::next_permutation(p, p + 3));
  auto &k = t[i + s - 1];
  k[0] = c;
  k[1][0] = 0, k[1][1] = k[1][2] = -1e18;
  k[2][0] = k[2][2] = -1e18, k[2][1] = 0;
}
void up(int i) {
  i += s - 1;
  while (i >>= 1) t[i] = t[i * 2 + 1] * t[i * 2];
}
void solve() {
  std::cin >> n >> m;
  s = 1 << std::__lg(2 * n - 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pa[i] = pb[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::sort(pa + 1, pa + 1 + n, [&](int i, int j) {
    return a[i] < a[j];
  });
  std::sort(pb + 1, pb + 1 + n, [&](int i, int j) {
    return b[i] < b[j];
  });
  for (int i = 1; i <= n; i++) {
    ap[pa[i]] = i, bp[pb[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cal(i);
  }
  for (int i = s - 1; i; i--) {
    t[i] = t[i * 2 + 1] * t[i * 2];
  }
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    std::swap(b[x], b[y]);
    std::swap(bp[x], bp[y]);
    pb[bp[x]] = x, pb[bp[y]] = y;
    for (int i = bp[x]; i <= bp[x] + 2 && i <= n; i++) {
      cal(i);
      up(i);
    }
    for (int i = bp[y]; i <= bp[y] + 2 && i <= n; i++) {
      cal(i);
      up(i);
    }
    std::cout << t[1][0][0] << "\n";
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}