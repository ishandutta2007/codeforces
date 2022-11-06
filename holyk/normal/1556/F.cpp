// Author:  HolyK
// Created: Mon Aug 30 00:43:43 2021
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
constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int mod(LL x) { return x % P; }
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
  Z(LL v) : x((v %= P) < 0 ? v + P : v) {}
  explicit operator bool() { return !!x; }
  Z inv() const { return Z(fpow(x)); }
  Z pow(int k) const { return Z(fpow(x, k)); }
  Z operator-() const { return Z(P - x); }
  Z &operator+=(const Z &r) { return inc(x, r.x), *this; }
  Z &operator-=(const Z &r) { return dec(x, r.x), *this; }
  Z &operator*=(const Z &r) { return x = LL(x) * r.x % P, *this; }
  Z &operator/=(const Z &r) { return x = LL(x) * fpow(r.x) % P, *this; }
  inline friend Z operator+(const Z &a, const Z &b) { return Z(a) += b; }
  inline friend Z operator-(const Z &a, const Z &b) { return Z(a) -= b; }
  inline friend Z operator*(const Z &a, const Z &b) { return Z(a) *= b; }
  inline friend Z operator/(const Z &a, const Z &b) { return Z(a) /= b; }
  inline friend std::ostream &operator<<(std::ostream &os, const Z &r) {
    return os << r.x;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<Z> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i].x;
  std::vector<std::vector<Z>> p(n, std::vector<Z>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p[i][j] = a[i] / (a[i] + a[j]);
    }
  }
  std::vector<Z> f(1 << n);
  for (int s = 1; s < 1 << n; s++) {
    f[s] = 1;
    for (int t = s - 1 & s; t > 0; --t &= s) {
      Z u = f[t];
      for (int i = 0; i < n; i++) {
        if (t >> i & 1) {
          for (int j = 0; j < n; j++) {
            if ((t ^ s) >> j & 1) {
              u *= p[i][j];
            }
          }
        }
      }
      f[s] -= u;
    }
  }
  Z ans = 0;
  for (int s = 1; s < 1 << n; s++) {
    for (int i = 0; i < n; i++) {
      if (s >> i & 1) {
        for (int j = 0; j < n; j++) {
          if (~s >> j & 1) {
            f[s] *= p[i][j];
          }
        }
      }
    }
    ans += f[s] * __builtin_popcount(s);
  }
  std::cout << ans << "\n";
  return 0;
}