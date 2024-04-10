// Author:  HolyK
// Created: Fri May 20 16:28:10 2022
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
int c[N], mu[N], lpf[N], pw[N];
std::vector<int> primes;
void solve() {
  int n;
  std::cin >> n;
  for (int i = 0, x; i < n; i++) {
    std::cin >> x;
    c[x]++;
  }
  n = 1e5;
  
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!lpf[i]) {
      mu[i] = -1;
      lpf[i] = i;
      primes.push_back(i);
    }
    for (int j : primes) {
      if (1LL * i * j > n) break;
      lpf[i * j] = j;
      if (lpf[i] == j) {
        mu[i * j] = 0;
        break;
      }
      mu[i * j] = -mu[i];
    }
  }

  for (int i : primes) {
    for (int j = n / i; j; j--) {
      c[j] += c[j * i];
    }
  }

  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = pw[i - 1] * 2LL % P;
  }

  Z ans;
  for (int i = 1; i <= n; i++) {
    if (!mu[i] || !c[i]) continue;
    ans += (pw[c[i]] - 1) * mu[i];
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}