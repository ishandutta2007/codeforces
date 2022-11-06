#include <bits/stdc++.h>

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(5e5 + 5);
int g[N << 2];
#define ls o << 1
#define rs o << 1 | 1
int ask(int o, int l, int r, int x, int y, int z) {
  if (g[o] % z == 0) return 0;
  if (l == r) return 1;
  int m = l + r >> 1;
  int ans = 0;
  if (x <= m) ans += ask(ls, l, m, x, y, z);
  if (ans > 1) return ans;
  if (y > m) ans += ask(rs, m + 1, r, x, y, z);
  return ans;
}
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    g[o] = y;
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  g[o] = std::gcd(g[ls], g[rs]);
}
void build(int o, int l, int r) {
  if (l == r) {
    std::cin >> g[o];
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  g[o] = std::gcd(g[ls], g[rs]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  build(1, 1, n);
  int m;
  std::cin >> m;
  while (m--) {
    int opt, x, y, z;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      std::cin >> z;
      puts(ask(1, 1, n, x, y, z) <= 1 ? "YES" : "NO");
    } else {
      update(1, 1, n, x, y);
    }
  }
  return 0;
}