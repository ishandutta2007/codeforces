// Author:  HolyK
// Created: Thu Sep 22 09:20:45 2022
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

void solve() {
  int m;
  std::cin >> m;

  std::vector<std::vector<int>> fac(m + 1);

  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      fac[j].push_back(i);
    }
  }

  std::vector<int> pr, np(m + 1), mu(m + 1);
  mu[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (!np[i]) {
      pr.push_back(i);
      mu[i] = -1;
    }

    for (int j : pr) {
      if (i * j > m) break;
      np[i * j] = 1;
      if (i % j == 0) {
        mu[i * j] = 0;
        break;
      }
      mu[i * j] = -mu[i];
    }
  }
  
  std::vector<Z> dp(m + 1), sum(m + 1);
  dp[1] = 0;
  
  // \sum_{d | x} dp[d] \sum_{k | x/d} mu(k) m / dk

  // \sum_{dk | x} (m / dk) \sum dp[d]mu(k)
  for (int i = 2; i <= m; i++) {
    for (int j : fac[i]) {
      dp[i] += m / j * sum[j];
    }
    dp[i] = (dp[i] + m) / (m - m / i);
    for (int j = i; j <= m; j += i) {
      sum[j] += dp[i] * mu[j / i];
    }
  }

  for (int i = 1; i <= m; i++) dp[0] += dp[i];
  std::cout << dp[0] / m + 1 << "\n";
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