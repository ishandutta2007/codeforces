// Author:  HolyK
// Created: Tue Jul 13 08:20:55 2021
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
struct Hash {
  size_t operator()(uint64_t x) const {
    x += 48;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};
using Map = __gnu_pbds::gp_hash_table<uint64_t, int, Hash>;
} // namespace HashTable
HashTable::Map map;
int cnt(LL x) {
  auto it = map.find(x);
  return it == map.end() ? 0 : it->second;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<LL> a(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0, x; i < n; i++) {
    std::cin >> x;
    a[i] = a[i] == 1 ? x : -x;
  }
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  for (int i = n; i; i--) a[i] = a[i - 1];
  a[0] = 0;
  int m;
  std::cin >> m;
  std::vector<Qry> q(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].l >> q[i].r;
    q[i].l--;
    q[i].id = i;
  }
  std::sort(q.begin(), q.end());
  std::vector<LL> out(m);
  LL ans = 0;
  int x = 1, y = 0;
  for (auto [l, r, id] : q) {
    while (x < l) map[a[x]]--, ans -= cnt(a[x++] + k);
    while (x > l) ans += cnt(a[--x] + k), map[a[x]]++;
    while (y < r) ans += cnt(a[++y] - k), map[a[y]]++;
    while (y > r) map[a[y]]--, ans -= cnt(a[y--] - k);
    out[id] = ans;
  }
  for (auto x : out) std::cout << x << "\n";
  return 0;
}
/*
4 1
1 1 1 2
1 1 1 1
4
1 2
1 3
1 4
3 4
 */