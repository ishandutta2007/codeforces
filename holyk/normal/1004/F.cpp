#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

constexpr int N(1e5 + 5);
int n, m, thre;
struct Node {
  std::vector<PII> lp, rp;
  LL sum;
} t[N << 2];
Node merge(const Node &a, const Node &b) {
  Node c;
  c.sum = a.sum + b.sum;
  for (const auto &[x, i] : a.rp)
    for (const auto &[y, j] : b.lp)
      if ((x | y) >= thre) c.sum += 1LL * i * j;
  c.lp = a.lp, c.rp = b.rp;
  for (const auto &[y, j] : b.lp) {
    auto &[x, i] = c.lp.back();
    if ((x | y) == x)
      i += j;
    else
      c.lp.emplace_back(x | y, j);
  }
  for (const auto &[y, j] : a.rp) {
    auto &[x, i] = c.rp.back();
    if ((x | y) == x)
      i += j;
    else
      c.rp.emplace_back(x | y, j);
  }
  return c;
}
#define ls o << 1
#define rs o << 1 | 1
void build(int o, int l, int r) {
  if (l == r) {
    int x; readInt(x);
    t[o].lp = t[o].rp = { PII(x, 1) };
    t[o].sum = x >= thre ? 1 : 0;
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  t[o] = merge(t[ls], t[rs]);
}
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    t[o].lp = t[o].rp = { PII(y, 1) };
    t[o].sum = y >= thre ? 1 : 0;
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  t[o] = merge(t[ls], t[rs]);
}
Node ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return merge(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
}
int main() {
  readInt(n, m, thre);
  build(1, 1, n);
  while (m--) {
    int opt, x, y;
    readInt(opt, x, y);
    if (opt == 1) {
      update(1, 1, n, x, y);
    } else {
      printf("%lld\n", ask(1, 1, n, x, y).sum);
    }
  }
  return 0;
}