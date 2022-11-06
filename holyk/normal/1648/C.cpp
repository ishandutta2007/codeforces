// Author:  HolyK
// Created: Sun Mar  6 18:18:46 2022
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

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r = 0;
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
  T ask(int l, int r) { return ask(r) - ask(l); }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> c(2e5);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x--;
    c[x]++;
  }

  std::vector<int> a(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  init(n);

  // int s = 1 << std::__lg(400000 - 1);
  // std::vector<Z> val(s * 2, 1);
  // auto update = [&](int i, Z x) {
  //   val[i += s] = x;
  //   while (i > 1) {
  //     i /= 2;
  //     val[i] = val[i * 2] * val[i * 2 + 1];
  //   }
  // };
  // auto ask = [&](int l, int r) {
  //   Z ans = 1;
  //   for (l += s, r += s; l < r; l >>= 1, r >>= 1) {
  //     if (l & 1) ans *= val[l++];
  //     if (r & 1) ans *= val[--r];
  //   }
  //   return ans;
  // };

  Fenwick<int> fen(2e5);
  for (int i = 0; i < 2e5; i++) {
    // val[i + s] = ifac[c[i]];
    fen.add(i, c[i]);
  }
  // for (int i = s - 1; i >= 1; i--) {
  //   val[i] = val[i * 2] * val[i * 2 + 1];
  // }

  Z ans = 0, mul = 1;
  for (int i = 0; i < 2e5; i++) {
    mul *= ifac[c[i]];
  }

  for (int i = 0; i < m && i <= n; i++) {
    if (i == n) {
      ans += 1;
      break;
    }
    int k = fen.ask(a[i]);
    ans += mul * k * fac[n - i - 1];
    if (c[a[i]] == 0) {
      break;
    }
    mul *= fac[c[a[i]]--];
    mul *= ifac[c[a[i]]];
    fen.add(a[i], -1);
  }
  std::cout << ans << "\n";
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