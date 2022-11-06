// Author:  HolyK
// Created: Tue Jul 13 08:51:02 2021
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
constexpr int T(512);
struct Qry {
  int l, r, id;
  bool operator<(const Qry &rhs) const {
    return l / T == rhs.l / T ? l / T & 1 ? r < rhs.r : r > rhs.r : l < rhs.l;
  }
};


namespace HashTable {
using namespace __gnu_pbds;
struct Hash {
  size_t operator()(uint64_t x) const {
    x += 48;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};
using Map = gp_hash_table<uint64_t, int, Hash>;
} // namespace HashTable

HashTable::Map cnt;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::vector<Qry> q(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].l >> q[i].r;
    q[i].id = i;
    q[i].l--, q[i].r--;
  }
  std::sort(q.begin(), q.end());
  int x = 0, y = -1, ans = 0;
  std::vector<int> out(m);
  auto add = [&](int x, int y) {
    if (cnt[x] == x) ans--;
    cnt[x] += y;
    if (cnt[x] == x) ans++;
  };
  for (auto [l, r, id] : q) {
    while (x < l) add(a[x++], -1);
    while (x > l) add(a[--x], 1);
    while (y < r) add(a[++y], 1);
    while (y > r) add(a[y--], -1);
    out[id] = ans;
  }
  for (int x : out) std::cout << x << "\n";
  return 0;
}
/*

 */