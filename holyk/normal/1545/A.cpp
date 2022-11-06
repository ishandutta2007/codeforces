// Author:  HolyK
// Created: Mon Jul 12 17:56:07 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
template <class T>
struct FenwickTree {
  std::vector<T> c;
  FenwickTree(int n) : c(n) {}
  void clear() const { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p += p & -p) c[p] += x;
  }
  T ask(int p) const {
    T r = 0;
    for (; p; p -= p & -p) r += c[p];
    return r;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<PII> a(n);
    FenwickTree<int> fen(n + 1);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i].first;
      a[i].second = i + 1;
    }
    std::sort(a.begin(), a.end());
    bool flag = true;
    std::vector<int> b(n);
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && a[i].first == a[j].first; j++) ;
      int c[2] = {0, 0};
      for (int k = i; k < j; k++) {
        b[k] ^= i - fen.ask(a[k].second) & 1;
      }
      for (int k = i; k < j; k++) fen.add(a[k].second, 1);
      for (int k = i; k < j; k++) {
        b[k] ^= a[k].second - fen.ask(a[k].second) & 1;
        if (b[k]) c[k & 1]++;
      }
      if (c[0] ^ c[1]) flag = false;
    }
    std::cout << (flag ? "yes" : "no") << "\n";
  }
  return 0;
}
/*
1
6
2 1 2 1 2 1
 */