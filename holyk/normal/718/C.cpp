// Author:  HolyK
// Created: Fri May 20 17:42:17 2022
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

constexpr int N(1e5 + 5);
using V = std::array<Z, 2>;
using M = std::array<V, 2>;
V operator+(const V &a, const V &b) {
  return {a[0] + b[0], a[1] + b[1]};
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

const M F = {V{0, 1}, V{1, 1}}, I = {V{1, 0}, V{0, 1}};
M fpow(M x, int k) {
  M r = I;
  for (; k; k >>= 1, x = x * x) {
    if (k & 1) r = r * x;
  }
  return r;
}

#define ls o << 1
#define rs o << 1 | 1

M mul[N << 2];
V sum[N << 2];

void build(int o, int l, int r) {
  mul[o] = I;
  if (l == r) {
    int x;
    std::cin >> x;
    M u = fpow(F, x);
    sum[o] = {u[0][0], u[1][0]};
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  sum[o] = sum[ls] + sum[rs];
}

#define APPLY(p, x) mul[p] = x * mul[p], sum[p] = x * sum[p]
void pushdown(int o) {
  if (mul[o][0][0].x != 1 || mul[o][0][1].x != 0 || mul[o][1][0].x != 0 || mul[o][1][1].x != 1) {
    APPLY(ls, mul[o]);
    APPLY(rs, mul[o]);
    mul[o] = I;
  }
}

void update(int o, int l, int r, int x, int y, const M &z) {
  if (x <= l && r <= y) {
    APPLY(o, z);
    return;
  }
  pushdown(o);
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  sum[o] = sum[ls] + sum[rs];
}
Z ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return sum[o][1];
  pushdown(o);
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  build(1, 1, n);
  
  while (m--) {
    int opt, l, r, x;
    std::cin >> opt >> l >> r;
    if (opt == 1) {
      std::cin >> x;
      update(1, 1, n, l, r, fpow(F, x));
    } else {
      std::cout << ask(1, 1, n, l, r) << "\n";
    }
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