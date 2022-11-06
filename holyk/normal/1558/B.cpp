// Author:  HolyK
// Created: Tue Aug 24 22:57:53 2021
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
int P;
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
constexpr int N(4e6 + 5);
int f[N], g[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n >> P;
  f[1] = 1;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    inc(f[i], s);
    inc(g[i], g[i - 1]);
    inc(f[i], g[i]);
    for (int j = 2; 1LL * i * j <= n; j++) {
      inc(g[i * j], f[i]);
      if ((i + 1LL) * j <= n) inc(g[(i + 1) * j], P - f[i]);
    }
    inc(s, f[i]);
  }
  
  std::cout << (f[n] + P) % P << "\n";
  return 0;
}