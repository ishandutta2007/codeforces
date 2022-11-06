// Author:  HolyK
// Created: Thu May 19 14:07:53 2022
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

constexpr int Primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

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

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n, {}) {}
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

int n, m;
int val[303][62], a[400005];
void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= 300; i++) {
    for (int x = i, j = 0; j < 62 && x > 1; j++) {
      while (x % Primes[j] == 0) {
        x /= Primes[j];
        val[i][j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::array<int, 3>> q(m);
  std::vector<int> ans(m, 1);
  for (int i = 0; i < m; i++) {
    std::string s;
    int l, r, x = 0;
    std::cin >> s >> l >> r;
    if (s[0] == 'M') std::cin >> x;
    q[i] = {l - 1, r, x};
  }

  for (int k = 0; k < 62; k++) {
    Fenwick<LL> t1(n), t2(n);
    for (int i = 0; i < n; i++) {
      t1.add(i, val[a[i]][k]);
      t1.add(i + 1, -val[a[i]][k]);
      t2.add(i, 1LL * val[a[i]][k] * i);
      t2.add(i + 1, -1LL * val[a[i]][k] * (i + 1));
    }
    for (int i = 0; i < m; i++) {
      auto &[l, r, x] = q[i];
      if (x) {
        t1.add(l, val[x][k]);
        t1.add(r, -val[x][k]);
        t2.add(l, 1LL * val[x][k] * l);
        t2.add(r, -1LL * val[x][k] * r);
      } else {
        LL v = t1.ask(r) * r - t2.ask(r) - t1.ask(l) * l + t2.ask(l);
        assert(v >= 0);
        if (v > 0) {
          ans[i] = 1LL * ans[i] * (Primes[k] - 1) % P * fpow(Primes[k], (v - 1) % (P - 1)) % P;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) if (!q[i][2]) std::cout << ans[i] << "\n";
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