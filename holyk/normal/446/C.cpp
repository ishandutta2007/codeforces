// Author:  HolyK
// Created: Fri May 20 18:48:07 2022
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

constexpr int P(1e9 + 9);
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
  Z() : x(0) {}
  Z(int v) : x(v < 0 ? v + P : v >= P ? v - P : v) {}
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

constexpr int N(3e5 + 5);
using V = std::array<Z, 2>;
using M = std::array<V, 2>;
void operator+=(V &a, const V &b) {
  a[0] += b[0], a[1] += b[1];
}
void operator-=(V &a, const V &b) {
  a[0] -= b[0], a[1] -= b[1];
}
M operator*(const M &a, const M &b) {
  return {V{a[0][0] * b[0][0] + a[0][1] * b[1][0],
            a[0][0] * b[0][1] + a[0][1] * b[1][1]},
          V{a[1][0] * b[0][0] + a[1][1] * b[1][0],
            a[1][0] * b[0][1] + a[1][1] * b[1][1]}};
}
V operator*(const M &a, const V &b) {
  return {a[0][0] * b[0] + a[0][1] * b[1], a[1][0] * b[0] + a[1][1] * b[1]};
}

const M F = {V{0, 1}, V{1, 1}}, I = {V{1, 0}, V{0, 1}}, G = {V{-1, 1}, {1, 0}};
M fpow(M x, int k) {
  M r = I;
  for (; k; k >>= 1, x = x * x) {
    if (k & 1) r = r * x;
  }
  return r;
}

int n, m;
M f[N], g[N];
V c[N][2];
Z a[N];

void add(int p, V x) {
  V y = g[p - 1] * x;
  for (; p <= n; p += p & -p) {
    c[p][0] -= x;
    c[p][1] += y;
  }
}
Z ask(int n) {
  V r[2] = {};
  for (int p = n; p; p -= p & -p) {
    r[0] += c[p][0], r[1] += c[p][1];
  }
  return (f[n] * r[1])[0] + r[0][0];
}

void solve() {
  std::cin >> n >> m;
  f[0] = g[0] = I;
  for (int i = 1; i <= n + 2; i++) {
    f[i] = f[i - 1] * F;
    g[i] = g[i - 1] * G;
  }

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x;
    a[i] += a[i - 1];
  }

  while (m--) {
    int opt, l, r;
    std::cin >> opt >> l >> r;
    if (opt == 1) {
      add(l, V{1, 2});
      add(r + 1, V{-f[r - l + 3][0][1], -f[r - l + 3][1][1]});
    } else {
      std::cout << ask(r) - ask(l - 1) + a[r] - a[l - 1] << "\n";
    }
    // for (int i = 1; i <= n; i++) {
    //   std::cout << ask(i) - ask(i - 1) << " \n"[i == n];
    // }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}