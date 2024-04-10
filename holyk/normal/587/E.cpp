#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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


using LBasis = std::array<int, 31>;
void ins(LBasis &p, int x) {
  if (!x) return;
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1 ^ 1) continue;
    if (!p[i]) {
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
}
LBasis merge(LBasis a, LBasis b) {
  auto r = a;
  for (int i = 0; i <= 30; i++) ins(r, b[i]);
  return r;
}
constexpr int N(2e5 + 5);
#define ls o << 1
#define rs o << 1 | 1
LBasis p[N << 2];
int n, a[N], sum[N << 2];
void pushup(int o) {
  p[o] = merge(p[ls], p[rs]);
  sum[o] = sum[ls] ^ sum[rs];
}
void build(int o, int l, int r) {
  if (l == r) {
    p[o].fill(0);
    ins(p[o], sum[o] = a[l] ^ a[l - 1]);
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
void ins(int o, int l, int r, int x, int y) {
  if (l == r) {
    p[o].fill(0);
    ins(p[o], sum[o] ^= y);
    return;
  }
  int m = l + r >> 1;
  x <= m ? ins(ls, l, m, x, y) : ins(rs, m + 1, r, x, y);
  pushup(o);
}
LBasis ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return p[o];
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return merge(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
}
int qsum(int o, int l, int r, int x, int y) {
  if (y < l || x > r) return 0;
  if (x <= l && r <= y) return sum[o];
  int m = l + r >> 1;
  return qsum(ls, l, m, x, y) ^ qsum(rs, m + 1, r, x, y);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    int opt, l, r, v;
    std::cin >> opt >> l >> r;
    if (opt == 1) {
      std::cin >> v;
      ins(1, 1, n, l, v);
      if (r < n) ins(1, 1, n, r + 1, v);
    } else {
      LBasis p;
      if (l < r) 
        p = ask(1, 1, n, l + 1, r);
      else
        p.fill(0);
      ins(p, qsum(1, 1, n, 1, l));
      int ans = 1;
      for (int i = 0; i <= 30; i++) if (p[i]) ans <<= 1;
      std::cout << ans << "\n";
    }
  }
  return 0;
}