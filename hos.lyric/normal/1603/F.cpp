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

constexpr unsigned MO = 998244353;
using Mint = ModInt<MO>;

constexpr int LIM = 10'000'010;
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
  if (n < 0) {
    if (k >= 0) {
      return ((k & 1) ? -1 : +1) * binom(-n + k - 1, k);
    } else if (n - k >= 0) {
      return (((n - k) & 1) ? -1 : +1) * binom(-k - 1, n - k);
    } else {
      return 0;
    }
  } else {
    if (0 <= k && k <= n) {
      assert(n < LIM);
      return fac[n] * invFac[k] * invFac[n - k];
    } else {
      return 0;
    }
  }
}


Mint two[LIM], invTwo[LIM];
// Mint two2[LIM], invTwo2[LIM];

Mint ls[LIM + 1], rs[LIM + 1], fs[LIM];

int main() {
  prepare();
  two[0] = invTwo[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    two[i] = two[i - 1] * 2;
    invTwo[i] = invTwo[i - 1] * inv[2];
  }
  /*
  two2[0] = invTwo2[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    two2[i] = two2[i - 1] * two[i - 1];
    invTwo2[i] = invTwo2[i - 1] * invTwo[i - 1];
  }
  */
  ls[1] = rs[LIM] = 1;
  for (int i = 1; i < LIM; ++i) {
    ls[i + 1] = ls[i] * (two[i] - 1);
  }
  for (int i = LIM; --i >= 1; ) {
    rs[i] = (two[i] - 1) * rs[i + 1];
  }
  const Mint waf = ls[LIM].inv();
  for (int i = 1; i < LIM; ++i) {
    fs[i] = waf * ls[i] * rs[i + 1];
  }
  
  for (int numCases; ~scanf("%d", &numCases); ) for (; numCases--; ) {
    int N, K, X;
    scanf("%d%d%d", &N, &K, &X);
    
    Mint ans = 0;
    if (X == 0) {
      if (N <= K) {
        ans = 1;
        for (int i = 0; i < N; ++i) {
          ans *= (two[K] - two[i]);
        }
      }
    } else {
      // 0
      ans = 1;
      Mint twoN = Mint(2).pow(N);
      Mint prod = 1;
      Mint surj = 1;
      for (int d = 1; d < K; ++d) {
        prod *= (two[K] - two[d - 1]);
        prod *= invTwo[d - 1];
        prod *= fs[d];
        if (N >= d) {
          const Mint num = prod - prod * fs[K] * (two[d] - 1);
          
          /*
          Mint brt = 1;
          for (int i = 0; i < d; ++i) brt *= (two[d] - two[i]);
          for (int i = 0; i < N - d; ++i) brt *= (two[N] - two[i]);
          for (int i = 0; i < N - d; ++i) brt /= (two[N - d] - two[i]);
          //*/
          surj *= (twoN - 1); twoN *= inv[2];
          surj *= (two[d] - 1);
          surj *= fs[d];
          surj *= two[d - 1];
// cerr<<d<<": "<<brt<<" "<<surj<<endl;
          
          ans += num * surj;
        }
      }
    }
    printf("%u\n", ans.x);
  }
  return 0;
}