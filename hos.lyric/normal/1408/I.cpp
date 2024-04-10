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
  friend ModInt operator+(long long a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(long long a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(long long a, const ModInt &b) { return (ModInt(a) *= b); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

constexpr int MO = 998244353;
using Mint = ModInt<MO>;

constexpr int LIM = (1 << 16) + 10;
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


constexpr int MAX_M = 1010;
constexpr int MAX_K = 16;
constexpr int MAX_C = 16;
using Arr = array<int, MAX_K + 1>;

int N, K, C;
vector<int> A;

int M;
vector<int> ns;
vector<Arr> bss;

map<int, Mint> css[MAX_M][MAX_K + 1];

void dfs(int i, int len, int sum, int last, int key, Mint val) {
  if (len <= ns[i]) {
    css[i][sum][key] += val * invFac[ns[i] - len] * fac[ns[i]];
  }
  for (int a = last - 1; a >= 1; --a) {
    for (int b = 1; sum + a * b <= K; ++b) {
      dfs(i, len + b, sum + a * b, a, (b & 1) ? (key ^ bss[i][a]) : key, val * invFac[b] * invFac[a].pow(b));
    }
  }
}

Mint dp[MAX_K + 1][1 << (MAX_C - 1)];

int main() {
  prepare();
  
  for (; ~scanf("%d%d%d", &N, &K, &C); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    
    vector<Arr> seqs(N);
    for (int i = 0; i < N; ++i) {
      fill(seqs[i].begin(), seqs[i].end(), 0);
      for (int k = 0; k <= K; ++k) {
        seqs[i][k] = A[i] ^ (A[i] - k);
      }
    }
    sort(seqs.begin(), seqs.end());
    M = 0;
    ns.clear();
    bss.clear();
    for (int i = 0, j; i < N; i = j) {
      for (j = i; j < N && seqs[i] == seqs[j]; ++j) {}
      ++M;
      ns.push_back(j - i);
      bss.push_back(seqs[i]);
    }
// cerr<<"M = "<<M<<endl;
// for(int i=0;i<M;++i){cerr<<ns[i]<<"; ";pv(bss[i].begin(),bss[i].end());}
    
    for (int i = 0; i < M; ++i) for (int k = 0; k <= K; ++k) {
      css[i][k].clear();
    }
    for (int i = 0; i < M; ++i) {
      dfs(i, 0, 0, K + 1, 0, 1);
// for(int k=0;k<=K;++k){cerr<<i<<" "<<k<<": "<<css[i][k].size()<<"; ";pv(css[i][k].begin(),css[i][k].end());}
    }
    
    for (int k = 0; k <= K; ++k) {
      fill(dp[k], dp[k] + (1 << (C - 1)), 0);
    }
    dp[0][0] = 1;
    for (int i = 0; i < M; ++i) {
      for (int k = K; k >= 0; --k) {
        for (int dk = 1; k + dk <= K; ++dk) {
          for (int x = 0; x < 1 << (C - 1); ++x) {
            if (dp[k][x].x) {
              for (const auto &kv : css[i][dk]) {
                dp[k + dk][x ^ (kv.first >> 1)] += dp[k][x] * kv.second;
              }
            }
          }
        }
      }
    }
    int ini = 0;
    for (int i = 0; i < N; ++i) {
      ini ^= A[i];
    }
    const Mint coef = fac[K] / Mint(N).pow(K);
    vector<Mint> ans(1 << C);
    for (int x = 0; x < 1 << (C - 1); ++x) {
      ans[ini ^ (x << 1 | (K & 1))] = coef * dp[K][x];
    }
    for (int x = 0; x < 1 << C; ++x) {
      if (x > 0) printf(" ");
      printf("%d", ans[x].x);
    }
    puts("");
  }
  return 0;
}