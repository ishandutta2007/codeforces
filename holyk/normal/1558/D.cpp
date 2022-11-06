// Author:  HolyK
// Created: Wed Aug 25 14:32:54 2021
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

constexpr int P(998244353);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int mod(LL x) {
  return x % P;
}
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
struct Z {
  int x;
  Z(int v = 0) : x(v < 0 ? v + P : v >= P ? v - P : v) {}
  int val() const {
    return x;
  }
  Z inv() const {
    assert(x);
    return Z(fpow(x));
  }
  Z pow(int k) const {
    return Z(fpow(x, k));
  }
  Z operator-() const {
    return Z(P - x);
  }
  Z &operator+=(const Z &r) {
    inc(x, r.x);
    return *this;
  }
  Z &operator-=(const Z &r) {
    dec(x, r.x);
    return *this;
  }
  Z &operator*=(const Z &r) {
    x = 1LL * x * r.x % P;
    return *this;
  }
  Z &operator/=(const Z &r) {
    x = 1LL * x * fpow(r.x) % P;
    return *this;
  }
  inline friend Z operator+(const Z &a, const Z &b) {
    return Z(a) += b;
  }
  inline friend Z operator-(const Z &a, const Z &b) {
    return Z(a) -= b;
  }
  inline friend Z operator*(const Z &a, const Z &b) {
    return Z(a) *= b;
  }
  inline friend Z operator/(const Z &a, const Z &b) {
    return Z(a) /= b;
  }
};
constexpr int N(1e6 + 5);
int fac[N], ifac[N];
int bin(int n, int m) {
  if (m < 0 || m > n) return 0;
  return 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
void init(int n) {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  ifac[n] = fpow(fac[n]);
  for (int i = n - 1; i > 0; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % P;
}
int n, m, c[N];
void add(int p, int x) {
  for (; p <= n; p += p & -p) c[p] += x;
}
int find(int s) {
  int p = 0, r = 0;
  for (int i = 1 << 17; i; i >>= 1) {
    int q = p + i;
    if (q <= n && q - c[q] - r < s) {
      p = q;
      r += c[q];
    }
  }
  return p + 1;
}
int main() {
  init(1e6);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
      std::cin >> a[i] >> b[i];
    }
    std::set<int> s;
    for (int i = m - 1; i >= 0; i--) {
      s.insert(find(b[i] + 1));
      add(b[i] = find(b[i]), 1);
    }
    for (int i : b) add(i, -1);
    std::cout << bin(2 * n - s.size() - 1, n) << "\n";
  }
  return 0;
}