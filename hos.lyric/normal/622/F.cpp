#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")

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
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

template<int_fast64_t M_> struct ModInt {
  static constexpr int_fast64_t M = M_;
  int_fast64_t x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(int_fast64_t x_) { x = x_ % M; if (x < 0) x += M; }
  ModInt &operator+=(const ModInt &a) { x += a.x; if (x >= M) x -= M; return *this; }
  ModInt &operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += M; return *this; }
  ModInt &operator*=(const ModInt &a) { x *= a.x; x %= M; return *this; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(int_fast64_t e) const {
    ModInt x2 = x, xe = 1;
    for (; e; e >>= 1) {
      if (e & 1) xe *= x2;
      x2 *= x2;
    }
    return xe;
  }
  ModInt inv() const {
    Int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  friend ModInt operator+(int_fast64_t a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(int_fast64_t a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(int_fast64_t a, const ModInt &b) { return (ModInt(a) *= b); }
  friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }
};

using Mint = ModInt<1000000007>;
constexpr int LIM = 1000005;

Mint inv[LIM], fac[LIM], invFac[LIM];

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    inv[i] = -(Mint::M / i) * inv[Mint::M % i];
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
  \sum[0 <= i < n] a^i f(i)
  f: poly of deg <= d
  f(i) = y[i] (i = 0, 1, ..., d)

  https://min-25.hatenablog.com/entry/2015/04/24/031413
*/
Mint sumPowerPoly(int d, const vector<Mint> &y, Mint a, Int n) {
  assert(d + 1 < LIM);
  assert((int)y.size() >= d + 1);
  if (n <= d + 1) {
    Mint sum = 0, aa = 1;
    for (int i = 0; i < n; ++i) {
      sum += aa * y[i];
      aa *= a;
    }
    return sum;
  } else {
    // a^i, a^(n-i), binom(n, i), binom(n - 1 - i, d - i)
    vector<Mint> a0(d + 1), a1(d + 1), c0(d + 2), c1(d + 2);
    a0[0] = 1;
    for (int i = 1; i <= d; ++i) a0[i] = a0[i - 1] * a;
    a1[d] = a.pow(n - d);
    for (int i = d - 1; i >= 0; --i) a1[i] = a1[i + 1] * a;
    c0[0] = 1;
    for (int i = 1; i <= d + 1; ++i) c0[i] = c0[i - 1] * (n + 1 - i) * inv[i];
    c1[d + 1] = 0; c1[d] = 1;
    for (int i = d - 1; i >= 0; --i) c1[i] = c1[i + 1] * (n - 1 - i) * inv[d - i];
    Mint b = 0;
    if (a.x == 1) {
      b = c0[d] * (n - d) * inv[d + 1];
    } else {
      b = 1;
      for (int i = 0; i <= d; ++i) {
        b -= c0[i] * c1[i] * (((d - i) % 2 != 0) ? -1 : +1) * a1[i];
      }
      b *= (1 - a).inv().pow(d + 1);
    }
    Mint ret = 0, sum = 0;
    for (int i = 1; i <= d + 1; ++i) {
      sum += a0[i - 1] * y[i - 1];
      ret += (b * binom(d + 1, i) * (((d + 1 - i) % 2 != 0) ? -1 : +1) * a0[d + 1 - i] +
          c0[i] * c1[i] * (((d - i) % 2 != 0) ? -1 : +1) * a1[i]) * sum;
    }
    return ret;
  }
}

int main() {
  prepare();
  Int N;
  int K;
  for (; ~scanf("%lld%d", &N, &K); ) {
    vector<Mint> ys(K + 1);
    for (int x = 0; x <= K; ++x) {
      ys[x] = Mint(x).pow(K);
    }
// cerr<<"ys = ";pv(ys.begin(),ys.end());
    Mint ans = sumPowerPoly(K, ys, 1, N + 1);
    ans -= Mint(0).pow(K);
    cout << ans << endl;
  }
  return 0;
}