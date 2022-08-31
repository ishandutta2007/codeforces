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


constexpr int LIM = 110;
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


constexpr int MAX_N = 42;

int uf[MAX_N];
int root(int u) {
  return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
bool connect(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


int N;
Mint pre[MAX_N][MAX_N][MAX_N][MAX_N];

map<vector<int>, Mint> cache[LIM];
Mint calc(int l, const vector<int> &cs) {
  auto it = cache[l].find(cs);
  if (it != cache[l].end()) {
    return it->second;
  }
  
  Mint ret = 0;
  const int csLen = cs.size();
  if (csLen == 0) {
    ret = 1;
  } else {
    int n = 0;
    for (int i = 0; i < csLen; ++i) {
      n += cs[i];
    }
    vector<pair<int, int>> ps;
    for (int i = 0, j; i < csLen; i = j) {
      for (j = i; j < csLen && cs[i] == cs[j]; ++j) {}
      ps.emplace_back(cs[i], j - i);
    }
    const int psLen = ps.size();
    vector<int> prods(psLen + 1);
    prods[0] = 1;
    for (int k = 0; k < psLen; ++k) {
      prods[k + 1] = prods[k] * (ps[k].second + 1);
    }
    for (int p = 1; p < prods[psLen]; ++p) {
      int m = 0;
      vector<int> ccs;
      Mint prod = 1;
      for (int k = 0; k < psLen; ++k) {
        const int c = ps[k].first;
        const int d = p / prods[k] % (ps[k].second + 1);
        m += c * d;
        for (int i = 0; i < ps[k].second - d; ++i) {
          ccs.push_back(c);
        }
        prod *= binom(ps[k].second, d);
        prod *= pre[n][l][c][d];
      }
      prod *= calc(m, ccs);
      ret += prod;
    }
  }
// cerr<<"ret = "<<ret<<"; l = "<<l<<", cs = ";pv(cs.begin(),cs.end());
  
  return cache[l][cs] = ret;
}

int main() {
  prepare();
  
  for (; ~scanf("%d", &N); ) {
    vector<int> P(N);
    for (int u = 0; u < N; ++u) {
      scanf("%d", &P[u]);
      --P[u];
    }
    
    for (int n = 1; n <= N; ++n) {
      for (int c = 1; c <= n; ++c) for (int d = 0; c * d <= n; ++d) {
        pre[n][0][c][d] = (fac[N] * inv[n]).pow(c).pow(d);
      }
      for (int l = 1; n + l <= N; ++l) {
        for (int c = 1; c <= n; ++c) for (int d = 0; c * d <= n; ++d) {
          pre[n][l][c][d] = ((fac[N] * inv[n]).pow(c) - (fac[N] * inv[n + l]).pow(c)).pow(d);
        }
      }
    }
    
    fill(uf, uf + N, -1);
    for (int u = 0; u < N; ++u) {
      connect(u, P[u]);
    }
    vector<int> cs;
    for (int u = 0; u < N; ++u) {
      if (uf[u] < 0) {
        cs.push_back(-uf[u]);
      }
    }
    sort(cs.begin(), cs.end(), greater<int>());
    
    for (int l = 0; l <= N; ++l) {
      cache[l].clear();
    }
    const Mint ans = calc(0, cs);
    printf("%d\n", ans.x);
  }
  return 0;
}