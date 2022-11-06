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

constexpr int N(1e6 + 5);
struct FenwickTree {
  int l, r, c[N], id[N], cnt;
  inline void clear(int l_, int r_) {
    l = l_, r = r_;
    ++cnt;
  }
  void add(int p, int x) {
    assert(p >= l && p <= r);
    for (p -= l - 1; p <= r - l + 1; p += p & -p) {
      if (id[p] != cnt) {
        id[p] = cnt;
        c[p] = 0;
      }
      c[p] += x;
    }
  }
  int ask(int p) {
    assert(p <= r && p >= l);
    int res = 0;
    for (p -= l - 1; p; p -= p & -p) {
      if (id[p] != cnt) {
        id[p] = cnt;
        c[p] = 0;
      }
      res += c[p];
    }
    return res;
  }
} t;
std::set<int> s[55];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  t.clear(-q, n);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s[x].insert(i);
    t.add(i, 1);
  }
  int f = 1;
  while (q--) {
    int c; 
    std::cin >> c;
    std::cout << t.ask(*s[c].begin()) << " ";
    t.add(*s[c].begin(), -1);
    s[c].erase(s[c].begin());
    s[c].insert(--f);
    t.add(f, 1);
  }
  return 0;
}