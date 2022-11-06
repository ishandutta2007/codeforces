// Author:  HolyK
// Created: Sun Oct 16 00:25:07 2022
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
using ULL = uint64_t;

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r{};
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
  T ask(int l, int r) { return ask(r) - ask(l); }
};

using A = __attribute((vector_size(64 * 4))) int;
constexpr int N(3e5 + 5);
std::mt19937 rng(std::random_device{}());

std::map<int, int> id;
int n, m, a[N];

A val[N * 2];
A get(int x) {
  if (id.count(x)) return val[id[x]];
  int k = id.size();
  id[x] = k;
  for (int i = 0; i < 64; i++) {
    val[k][i] = rng() & 255;
  }
  return val[k];
}

void solve() {
  std::cin >> n >> m;

  Fenwick<A> fen(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    fen.add(i, get(a[i]));
  }

  for (int i = 0; i < m; i++) {
    int opt;
    std::cin >> opt;
    if (opt == 1) {
      int i, x;
      std::cin >> i >> x;
      fen.add(i, -get(a[i]));
      fen.add(i, get(a[i] = x));
    } else {
      int l, r, x;
      std::cin >> l >> r >> x;
      A s = fen.ask(l, r + 1);
      LL k = 0;
      for (int i = 0; i < 64; i++) {
        k |= s[i] % x;
      }
      if (k) {
        std::cout << "NO\n";
      } else {
        std::cout << "YES\n";
      }
    }
  }

}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen("t.out", "w", stdout);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}