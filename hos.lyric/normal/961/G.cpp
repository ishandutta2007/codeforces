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
template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
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
////////////////////////////////////////////////////////////////////////////////

constexpr unsigned MO = 1'000'000'007;
using Mint = ModInt<MO>;


constexpr int LIM = 200'010;
Mint inv[LIM], fac[LIM], invFac[LIM];

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    inv[i] = -((Mint::M / i) * inv[Mint::M % i]);
  }
  fac[0] = invFac[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(Int n, Int k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[n] * invFac[k] * invFac[n - k];
  } else {
    return 0;
  }
}


/*
  \sum_{1<=i<=n} i binom(n-1, i-1) S(n-i, K-1)
  = \sum_{0<=i<=n} binom(n, i) (i^2/n) S(n-i, K-1)
  = (1/n) n! [x^n] (x + x^2) e^x (e^x - 1)^(K-1) / (K-1)!
*/

int N, K;
vector<int> W;

int main() {
  prepare();
  
  for (; ~scanf("%d%d", &N, &K); ) {
    W.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &W[i]);
    }
    
    Mint ans = 0;
    for (int k = 0; k <= K - 1; ++k) {
      // e^((k+1)x)
      for (int l = 1; l <= 2; ++l) {
        if (N >= l) {
          ans += (((K - 1 - k) & 1) ? -1 : +1) * binom(K - 1, k) * Mint(k + 1).pow(N - l) * invFac[N - l];
        }
      }
    }
    ans *= fac[N - 1];
    ans *= invFac[K - 1];
    
    Mint sumW = 0;
    for (int i = 0; i < N; ++i) {
      sumW += W[i];
    }
    ans *= sumW;
    
    printf("%u\n", ans.x);
  }
  return 0;
}