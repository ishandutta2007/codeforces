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

constexpr int BLen = 2;
constexpr int B[BLen] = {2020, 20201231};


constexpr int MAX = 1'000'010;
Mint two[MAX + 10], invTwo[MAX + 10];

int N, Q, K, L;
char S[MAX + 10];
char T[MAX + 10];
char W[MAX + 10];

int lens[MAX + 10];
int ns[MAX + 10];

Mint hashesRev[MAX + 10][2], hashes[MAX + 10][2];
Mint head[MAX + 10][2], tail[MAX + 10][2];

Mint sums[100'010][26];

int main() {
  const Mint INV2 = Mint(2).inv();
  two[0] = invTwo[0] = 1;
  for (int i = 1; i <= MAX; ++i) {
    two[i] = two[i - 1] * 2;
    invTwo[i] = invTwo[i - 1] * INV2;
  }
  
  for (; ~scanf("%d%d", &N, &Q); ) {
    scanf("%s", S);
    scanf("%s", T);
    
    string ss = S;
    for (int n = 0; n < N; ++n) {
      ss = ss + T[n] + ss;
      if (ss.size() > MAX) {
        break;
      }
    }
    const int ssLen = ss.size();
// cerr<<"ss = "<<ss<<endl;
    for (int h = 0; h < 2; ++h) {
      Mint bb = 1;
      for (int i = 0; i < MAX; ++i) {
        hashesRev[i + 1][h] = hashesRev[i][h] + bb * ((i < ssLen) ? ss[ssLen - 1 - i] : 0);
        hashes[i + 1][h] = hashes[i][h] + bb * ((i < ssLen) ? ss[i] : 0);
        bb *= B[h];
      }
    }
    
    lens[0] = strlen(S);
    for (int n = 0; n < N; ++n) {
      lens[n + 1] = min(lens[n] * 2 + 1, MAX);
    }
    lens[N + 1] = MAX;
    for (int l = 0, n = 0; n <= N + 1; ++n) {
      for (; l <= lens[n]; ++l) {
        ns[l] = n;
      }
    }
// cerr<<"ns = ";pv(ns,ns+100);
    
    for (int n = 0; n < N; ++n) {
      for (int a = 0; a < 26; ++a) {
        sums[n + 1][a] = sums[n][a] + ((T[n] - 'a' == a) ? invTwo[n + 1] : 0);
      }
    }
    
    for (int q = 0; q < Q; ++q) {
      scanf("%d%s", &K, W);
      L = strlen(W);
      
      for (int h = 0; h < 2; ++h) {
        head[0][h] = 0;
        tail[L][h] = 0;
      }
      for (int i = 0; i < L; ++i) {
        for (int h = 0; h < 2; ++h) {
          head[i + 1][h] = head[i][h] * B[h] + W[i];
        }
      }
      for (int i = L; i--; ) {
        for (int h = 0; h < 2; ++h) {
          tail[i][h] = tail[i + 1][h] * B[h] + W[i];
        }
      }
      
      Mint ans = 0;
      for (int i = 0; i < L; ++i) {
        bool ok = true;
        for (int h = 0; h < 2; ++h) {
          ok = ok && (hashesRev[i][h] == head[i][h]);
          ok = ok && (hashes[L - 1 - i][h] == tail[i + 1][h]);
        }
        if (ok) {
// cerr<<"ok "<<i<<endl;
          const int lb = ns[max(i, L - 1 - i)];
          if (lb < K) {
            const int a = W[i] - 'a';
            ans += (sums[K][a] - sums[lb][a]) * two[K];
          }
        }
      }
      
      int match = 0;
      for (int j = 0; j + L <= lens[0]; ++j) {
        bool ok = true;
        for (int i = 0; i < L; ++i) {
          if (S[j + i] != W[i]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          ++match;
        }
      }
      ans += Mint(match) * two[K];
      
      printf("%d\n", ans.x);
    }
  }
  return 0;
}