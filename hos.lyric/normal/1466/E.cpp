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


template<int M_> struct ModInt {
  static constexpr int M = M_;
  int x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(long long x_) : x(x_ % M) { if (x < 0) x += M; }
  ModInt &operator+=(const ModInt &a) { x += a.x; if (x >= M) x -= M; return *this; }
  ModInt &operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += M; return *this; }
  ModInt &operator*=(const ModInt &a) { x = static_cast<int>((static_cast<long long>(x) * a.x) % M); return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt x2 = x, xe = 1;
    for (; e; e >>= 1) {
      if (e & 1) xe *= x2;
      x2 *= x2;
    }
    return xe;
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
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
  explicit operator bool() const { return (x != 0); }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  friend ModInt operator+(long long a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(long long a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(long long a, const ModInt &b) { return (ModInt(a) *= b); }
  friend ModInt operator/(long long a, const ModInt &b) { return (ModInt(a) /= b); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

constexpr int MO = 1'000'000'007;
using Mint = ModInt<MO>;


constexpr int E = 60;

int N;
vector<Int> X;

int main() {
  int numCases;
  for (; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      scanf("%d", &N);
      X.resize(N);
      for (int i = 0; i < N; ++i) {
        scanf("%lld", &X[i]);
      }
      
      vector<Int> cnt(E, 0);
      for (int i = 0; i < N; ++i) {
        for (int e = 0; e < E; ++e) {
          if ((X[i] >> e) & 1) {
            ++cnt[e];
          }
        }
      }
      
      Mint ans = 0;
      for (int i = 0; i < N; ++i) {
        Mint a = 0, o = 0;
        for (int e = 0; e < E; ++e) {
          if ((X[i] >> e) & 1) {
            a += Mint(cnt[e]) * Mint(1LL << e);
            o += Mint(N) * Mint(1LL << e);
          } else {
            o += Mint(cnt[e]) * Mint(1LL << e);
          }
        }
        ans += a * o;
      }
      printf("%d\n", ans.x);
    }
  }
  return 0;
}