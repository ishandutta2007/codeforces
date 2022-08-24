#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

////////////////////////////////////////////////////////////////////////////////
struct ModInt {
  static unsigned M;
  unsigned x;
  ModInt() : x(0U) {}
  ModInt(unsigned x_) : x(x_ % M) {}
  ModInt(unsigned long long x_) : x(x_ % M) {}
  ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};
unsigned ModInt::M;
////////////////////////////////////////////////////////////////////////////////

using Mint = ModInt;

constexpr int LIM = 110;
Mint fac[LIM], bn[LIM][LIM];

int N, M, K;
Mint dp[LIM][LIM][LIM];
Mint sub[LIM];

int main() {
  for (; ~scanf("%d%d%d%u", &N, &M, &K, &Mint::M); ) {
    fac[0] = 1;
    for (int i = 1; i < LIM; ++i) {
      fac[i] = fac[i - 1] * i;
    }
    for (int n = 0; n < LIM; ++n) {
      bn[n][0] = bn[n][n] = 1;
      for (int k = 1; k < n; ++k) {
        bn[n][k] = bn[n - 1][k - 1] + bn[n - 1][k];
      }
    }
    
    memset(dp, 0, sizeof(dp));
    for (int n = 0; n <= N; ++n) {
      for (int m = 1; m <= M; ++m) {
        if (n == 0 || n < m) {
          dp[n][m][0] = fac[n];
        } else if (m == 1) {
          dp[n][m][1] = fac[n];
        } else {
          for (int i = 0; i < n; ++i) {
            const int limA = (i < m - 1) ? 0 : i;
            const int limB = (n - 1 - i < m - 1) ? 0 : (n - 1 - i);
            fill(sub, sub + limA + limB + 1, 0);
            for (int a = 0; a <= limA; ++a) for (int b = 0; b <= limB; ++b) {
              sub[a + b] += dp[i][m - 1][a] * dp[n - 1 - i][m - 1][b];
            }
            for (int k = 0; k <= limA + limB; ++k) {
              dp[n][m][k] += bn[n - 1][i] * sub[k];
            }
          }
        }
      }
    }
    
    const Mint ans = dp[N][M][K];
    printf("%u\n", ans.x);
  }
  return 0;
}