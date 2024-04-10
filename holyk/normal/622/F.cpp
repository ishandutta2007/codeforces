// Author:  HolyK
// Created: Sun Aug 28 02:18:28 2022
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
int interpolateIota(const std::vector<int> &f, int x) {
  int n = f.size();
  std::vector<int> r(n + 1);
  r[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    r[i] = 1LL * (x - i) * r[i + 1] % P;
  }
  int ans = 0, l = 1;
  for (int i = 0; i < n; ++i) {
    ans = (ans + (n - 1 - i & 1 ? -1LL : 1LL) * ifac[i] * ifac[n - 1 - i] % P * f[i] % P * l % P * r[i + 1]) % P;
    l = 1LL * (x - i) * l % P;
  }
  return (ans + P) % P;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  init(k + 2);
  int s = 0;
  std::vector<int> p(k + 2);
  for (int i = 1; i <= k + 2; i++) {
    inc(s, fpow(i, k));
    p[i - 1] = s;
  }
  std::cout << interpolateIota(p, n - 1) << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}