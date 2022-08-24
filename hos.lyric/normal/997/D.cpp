// #pragma GCC optimize ("Ofast")
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
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(long long e) const {
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
  friend ModInt operator+(long long a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(long long a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(long long a, const ModInt &b) { return (ModInt(a) *= b); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

constexpr int MO = 998244353;
using Mint = ModInt<MO>;

constexpr int LIM = 100;
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

int Ns[2], K;
Mint cycs[2][110];

int N;
int U[4010], V[4010];
vector<int> G[4010];
int usLen, vsLen;
int us[4010], vs[4010];
vector<int> gU[4010], gV[4010];
Mint dpU[4010], dpV[4010];

void dfs(int u, int p, int c) {
  ((c == 0) ? us[usLen++] : vs[vsLen++]) = u;
  for (const int v : G[u]) {
    if (v != p) {
      dfs(v, u, c ^ 1);
    }
  }
}

void doIt(int h) {
  N = Ns[h];
  for (int i = 0; i < N - 1; ++i) {
    scanf("%d%d", &U[i], &V[i]);
    --U[i];
    --V[i];
  }
  
  fill(cycs[h], cycs[h] + K + 1, 0);
  if (K % 2 != 0) {
    return;
  }
  
  fill(G, G + N, vector<int>{});
  for (int i = 0; i < N - 1; ++i) {
    G[U[i]].push_back(V[i]);
    G[V[i]].push_back(U[i]);
  }
  usLen = vsLen = 0;
  dfs(0, -1, 0);
  if (usLen > vsLen) {
    usLen = vsLen = 0;
    dfs(0, -1, 1);
  }
  sort(us, us + usLen);
  sort(vs, vs + vsLen);
// cerr<<"us = ";pv(us,us+usLen);
// cerr<<"vs = ";pv(vs,vs+vsLen);
  fill(gU, gU + usLen, vector<int>{});
  fill(gV, gV + vsLen, vector<int>{});
  for (int x = 0; x < usLen; ++x) {
    const int u = us[x];
    for (const int v : G[u]) {
      gU[x].push_back(lower_bound(vs, vs + vsLen, v) - vs);
    }
  }
  for (int y = 0; y < vsLen; ++y) {
    const int v = vs[y];
    for (const int u : G[v]) {
      gV[y].push_back(lower_bound(us, us + usLen, u) - us);
    }
  }
  for (int s = 0; s < usLen; ++s) {
    fill(dpU, dpU + usLen, 0);
    dpU[s] = 1;
    for (int k = 0; k < K; k += 2) {
      cycs[h][k] += dpU[s];
      fill(dpV, dpV + vsLen, 0);
      for (int x = 0; x < usLen; ++x) {
        for (const int y : gU[x]) {
          dpV[y] += dpU[x];
        }
      }
      fill(dpU, dpU + usLen, 0);
      for (int y = 0; y < vsLen; ++y) {
        for (const int x : gV[y]) {
          dpU[x] += dpV[y];
        }
      }
    }
    cycs[h][K] += dpU[s];
  }
  
  cycs[h][0] = N;
  for (int k = 2; k <= K; k += 2) {
    cycs[h][k] *= 2;
  }
// cerr<<"cycs[h] = ";pv(cycs[h],cycs[h]+K+1);
}

int main() {
  prepare();
  for (; ~scanf("%d%d%d", &Ns[0], &Ns[1], &K); ) {
    doIt(0);
    doIt(1);
    Mint ans = 0;
    if (K % 2 == 0) {
      for (int k = 0; k <= K; k += 2) {
        ans += binom(K, k) * cycs[0][k] * cycs[1][K - k];
      }
    }
    printf("%d\n", ans.x);
  }
  return 0;
}