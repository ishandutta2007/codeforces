// Author:  HolyK
// Created: Thu Dec 30 21:10:47 2021
#include <algorithm>
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

constexpr int N(1.5e5 + 5);
int n, m, a[N];
Z pw[N];

int get(int l, int r, int k) {
  return std::partition_point(a + l, a + r, [&](int x) {
    return a[l] >> k == x >> k;
  }) - a;
}

int getm(int l, int r, int k) {
  return std::partition_point(a + l, a + r, [&](int x) {
    return ~x >> k & 1;
  }) - a;
}

Z solve(int l1, int r1, int l2, int r2, int k) {
  if (k == -1 || l1 == r1 || l2 == r2) {
    return pw[r1 - l1 + r2 - l2];
  }
  int m1 = getm(l1, r1, k), m2 = getm(l2, r2, k);
  Z ans;
  if (m >> k & 1) {
    ans = solve(l1, m1, m2, r2, k - 1) * solve(m1, r1, l2, m2, k - 1);
  } else {
    ans = solve(l1, m1, l2, m2, k - 1) + solve(m1, r1, m2, r2, k - 1) - 1;
    ans += (pw[m1 - l1] - 1) * (pw[r1 - m1] - 1) + (pw[m2 - l2] - 1) * (pw[r2 - m2] - 1);
  }
  return ans;
}

void solve() {
  std::cin >> n >> m;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = pw[i - 1] * 2;
  }
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::sort(a, a + n);
  Z ans;
  if (!m) {
    for (int i = 0, j; i < n; i = j) {
      j = get(i, n, 0);
      ans += pw[j - i] - 1;
    }
  } else {
    int k = std::__lg(m);
    for (int i = 0, j; i < n; i = j) {
      j = get(i, n, k + 1);
      int m = getm(i, j, k);
      ans += solve(i, m, m, j, k - 1) - 1;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}