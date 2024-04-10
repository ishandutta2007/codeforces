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
  // ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (x * a.x) % M; return *this; }
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

constexpr unsigned MO = 31607;
using Mint = ModInt<MO>;

constexpr int LIM = MO;
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


constexpr int MAX_N = 22;

Mint EXP[MO + 10];
int LOG[MO + 10];

int N;
Mint A[MAX_N][MAX_N];
int logA[MAX_N][MAX_N];

int main() {
  prepare();
  
  EXP[0] = 1;
  for (int i = 1; i < (int)MO; ++i) {
    EXP[i] = EXP[i - 1] * 5;
  }
  for (int i = 1; i < (int)MO; ++i) {
    LOG[EXP[i].x] = i;
  }
  
  for (; ~scanf("%d", &N); ) {
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      scanf("%u", &A[x][y].x);
      A[x][y] *= inv[10000];
    }
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      logA[x][y] = LOG[A[x][y].x];
    }
    
    Mint ans = 0;
    for (int s = 0; s < 2; ++s) for (int t = 0; t < 2; ++t) {
      for (int p = 0; p < 1 << N; ++p) {
        Mint prod = 1;
        for (int x = 0; x < N; ++x) {
          int pp = p;
          if (s) pp |= 1 << x;
          if (t) pp |= 1 << (N - 1 - x);
          // Mint tmp = 1;
          int s = 0, t = 0;
          for (int y = 0; y < N; ++y) {
            if (pp & 1 << y) {
              // prod *= A[x][y];
              s += logA[x][y];
            } else {
              // tmp *= A[x][y];
              t += logA[x][y];
            }
          }
          // prod *= (1 - tmp);
          prod *= EXP[s % (MO - 1)];
          prod *= (1 - EXP[t % (MO - 1)]);
        }
        ans += (((s ^ t ^ __builtin_parity(p)) & 1) ? -1 : +1) * prod;
      }
    }
    ans = 1 - ans;
    printf("%u\n", ans.x);
  }
  return 0;
}