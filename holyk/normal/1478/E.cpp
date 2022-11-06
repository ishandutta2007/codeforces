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

constexpr int N(2e5 + 5);
int sum[N << 2], tag[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void pushup(int o) {
  sum[o] = sum[ls] + sum[rs];
}
void pushdown(int o, int l, int r) {
  if (tag[o] != -1) {
    tag[ls] = tag[rs] = tag[o];
    int m = l + r >> 1;
    sum[ls] = tag[o] * (m - l + 1);
    sum[rs] = tag[o] * (r - m); 
    tag[o] = -1;
  }
}
void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    tag[o] = z;
    sum[o] = (r - l + 1) * z;
    return;
  }
  int m = l + r >> 1;
  pushdown(o, l, r);
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}
int ask(int o, int l, int r, int x, int y) {
  if (x > r || y < l) return 0;
  if (x <= l && r <= y) return sum[o];
  int m = l + r >> 1;
  pushdown(o, l, r);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
char s[N], to[N];
void build(int o, int l, int r) {
  tag[o] = -1;
  if (l == r) {
    sum[o] = s[l] - '0';
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  sum[o] = sum[ls] + sum[rs];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, q;
    std::cin >> n >> q >> to + 1 >> s + 1;
    build(1, 1, n);
    std::vector<PII> a(q);
    for (auto &[x, y] : a) std::cin >> x >> y;
    std::reverse(a.begin(), a.end());
    bool ok = true;
    for (auto [x, y] : a) {
      int c = ask(1, 1, n, x, y);
      int len = y - x + 1;
      if (c * 2 == len) {
        ok = false;
        break;
      }
      if (c <= len / 2) {
        update(1, 1, n, x, y, 0);
      } else {
        update(1, 1, n, x, y, 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      ok &= ask(1, 1, n, i, i) == to[i] - '0';
    }
    puts(ok ? "YES" : "NO");
  } 
  return 0;
}