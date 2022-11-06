#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(5e5 + 5), P(1e9 + 7);
struct Data {
  LL lsum, rsum;
  int cnt, len;
  Data operator+(const Data &r) const {
    return {
      lsum + 1LL * cnt * r.len + r.lsum,
      r.rsum + 1LL * r.cnt * len + rsum,
      cnt + r.cnt,
      len + r.len
    };
  }
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void build(int o, int l, int r) {
  t[o].len = r - l + 1;
  if (l == r) return;
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
}
void add(int o, int l, int r, int x) {
  if (l == r) {
    t[o].lsum = t[o].rsum = t[o].cnt = 1;
    return;
  }
  int m = l + r >> 1;
  x <= m ? add(ls, l, m, x) : add(rs, m + 1, r, x);
  t[o] = t[ls] + t[rs];
}
Data ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int m = l + r >> 1;
  if (x > m) return ask(rs, m + 1, r, x, y);
  if (y <= m) return ask(ls, l, m, x, y);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int &x : a) std::cin >> x;
  std::iota(b.begin(), b.end(), 0);
  std::sort(b.begin(), b.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  build(1, 0, n - 1);
  int ans = 0;
  for (int i : b) { 
    int l = i ? ask(1, 0, n - 1, 0, i - 1).rsum % P : 0;
    int r = i < n - 1 ? ask(1, 0, n - 1, i + 1, n - 1).lsum % P : 0;
    ans = (ans + (1LL * l * (n - i) + 1LL * r * (i + 1) + 1LL * (n - i) * (i + 1)) % P * a[i]) % P;
    add(1, 0, n - 1, i);
  }
  std::cout << ans;
  return 0;
}