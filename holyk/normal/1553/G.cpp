// Author:  HolyK
// Created: Fri Jul 23 17:00:06 2021
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
constexpr int N(3e5 + 5), M(1e6 + 5);
bool np[N];
std::vector<int> primes;
void sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!np[i]) primes.push_back(i);
    for (int j : primes) {
      if (1LL * i * j > n) break;
      np[i * j] = true;
      if (i % j == 0) break;
    }
  }
}
int id[M];
std::vector<int> get(int x) {
  std::vector<int> res;
  for (int j = 0; j < primes.size(); j++) {
    int i = primes[j];
    if (i > x) break;
    if (x % i) continue;
    do {
      x /= i;
    } while (x % i == 0);
    res.push_back(j);
  }
  if (x > 1) {
    if (!id[x]) id[x] = ++id[0];
    res.push_back(id[x] + primes.size() - 1);
  } 
  return res;
}
struct Dsu {
  std::vector<int> f;
  Dsu(int n) : f(n) {
    std::iota(f.begin(), f.end(), 0);
  }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    return same(x, y) ? false : f[find(x)] = find(y), true;
  }
};
#include <ext/pb_ds/assoc_container.hpp>
namespace HashTable {
using namespace __gnu_pbds;
struct Hash {
  size_t operator()(PII a) const {
    uint64_t x = (uint64_t)a.first << 31 | (uint64_t)a.second;
    x += 48;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
};
using Set = gp_hash_table<PII, null_type, Hash>;
} // namespace HashTable
HashTable::Set s;
PII mp(int i, int j) {
  return i < j ? PII(i, j) : PII(j, i);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  sieve(1000);
  // std::cerr << primes.size() << "\n";
  int n, q;
  std::cin >> n >> q;
  Dsu d(3 * n + primes.size());
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    for (int j : get(a[i])) {
      d.merge(i, j + n);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = d.find(i);
    auto v = get(a[i] + 1);
    for (int j = 0; j < v.size(); j++) {
      int y = d.find(v[j] + n);
      s.insert(mp(x, y));
      for (int k = j + 1; k < v.size(); k++) {
        int z = d.find(v[k] + n);
        s.insert(mp(y, z));
      }
    }
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    x = d.find(x);
    y = d.find(y);
    if (x == y) {
      std::cout << "0\n";
    } else if (s.find(mp(x, y)) != s.end()) {
      std::cout << "1\n";
    } else {
      std::cout << "2\n";
    }
  }
  return 0;
}
/*

 */