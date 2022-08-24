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

constexpr int MO = 1000000007;
using Mint = ModInt<MO>;


template <class T> void bAdd(vector<T> &bit, int pos, T val) {
  for (int x = pos; x < (int)bit.size(); x |= x + 1) {
    bit[x] += val;
  }
}

template <class T> T bSum(const vector<T> &bit, int pos) {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


template <class T, class S, class OpTT, class OpST, class OpSS>
struct SegmentTree {
  const OpTT opTT;
  const OpST opST;
  const OpSS opSS;
  const T idT;
  const S idS;

  int n;
  vector<T> ts;
  vector<S> ss;
  SegmentTree(int n_, const OpTT opTT, const OpST opST, const OpSS opSS,
              const T &idT, const S &idS)
      : opTT(opTT), opST(opST), opSS(opSS), idT(idT), idS(idS) {
    for (n = 1; n < n_; n <<= 1) {}
    ts.assign(n << 1, idT);
    ss.assign(n << 1, idS);
  }
  T &at(int a) {
    return ts[n + a];
  }
  void build() {
    for (int a = n; --a; ) ts[a] = opTT(ts[a << 1], ts[a << 1 | 1]);
  }
  T query(int a, int b, const S &s) {
    return query(1, 0, n, a, b, s);
  }

 private:
  T query(int u, int l, int r, int a, int b, const S &s) {
    if (a < l) a = l;
    if (b > r) b = r;
    if (a >= b) return idT;
    if (a == l && b == r) {
      ts[u] = opST(s, ts[u], r - l);
      ss[u] = opSS(s, ss[u]);
      return ts[u];
    }
    const int uL = u << 1, uR = u << 1 | 1;
    const int mid = (l + r) >> 1;
    // speed-up: if (ss[u] != idS)
    {
      ts[uL] = opST(ss[u], ts[uL], mid - l);
      ts[uR] = opST(ss[u], ts[uR], r - mid);
      ss[uL] = opSS(ss[u], ss[uL]);
      ss[uR] = opSS(ss[u], ss[uR]);
      ss[u] = idS;
    }
    const T resL = query(uL, l, mid, a, b, s);
    const T resR = query(uR, mid, r, a, b, s);
    ts[u] = opTT(ts[uL], ts[uR]);
    return opTT(resL, resR);
  }
};


int N;
vector<Int> A;
int M;
vector<int> T, X;

int main() {
  for (; ~scanf("%d", &N); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    scanf("%d", &M);
    T.resize(M);
    X.resize(M);
    for (int m = 0; m < M; ++m) {
      scanf("%d%d", &T[m], &X[m]);
      --X[m];
    }
    
    auto as = A;
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    const int asLen = as.size();
    vector<vector<int>> iss(asLen);
    vector<int> es(N), fs(N);
    for (int i = 0; i < N; ++i) {
      const int e = lower_bound(as.begin(), as.end(), A[i]) - as.begin();
      es[i] = e;
      fs[i] = iss[e].size();
      iss[e].push_back(i);
    }
    
    vector<Int> ls(N), rs(N);
    {
      vector<Int> bit(asLen);
      fill(bit.begin(), bit.end(), 0);
      for (int i = 0; i < N; ++i) {
        ls[i] = bSum(bit, es[i] + 1);
        bAdd<Int>(bit, es[i], 1);
      }
      fill(bit.begin(), bit.end(), 0);
      for (int i = N; i--; ) {
        rs[i] = bSum(bit, es[i] + 1);
        bAdd<Int>(bit, es[i], 1);
      }
    }
    
    vector<vector<Int>> bits1(asLen);
    vector<vector<Int>> bitsL(asLen);
    vector<vector<Int>> bitsR(asLen);
    
    using Entry = pair<Int, Int>;
    auto opTT = [](const Entry &ta, const Entry &tb) {
      return Entry(ta.first + tb.first, ta.second + tb.second);
    };
    auto opST = [](const Entry &s, const Entry &t, int sz) {
      return Entry(t.first + s.first * (t.second + s.second), t.second + s.second);
    };
    using ST = SegmentTree<Entry, Entry, decltype(opTT), decltype(opST), decltype(opTT)>;
    vector<ST *> segL(asLen);
    vector<ST *> segR(asLen);
    for (int e = 0; e < asLen; ++e) {
      bits1[e].assign(iss[e].size(), 0);
      bitsL[e].assign(iss[e].size(), 0);
      bitsR[e].assign(iss[e].size(), 0);
      segL[e] = new ST(iss[e].size(), opTT, opST, opTT, Entry(0, 0), Entry(0, 0));
      segR[e] = new ST(iss[e].size(), opTT, opST, opTT, Entry(0, 0), Entry(0, 0));
    }
    
    auto calc = [&](int i) {
      Mint ret = 0;
      const int e = es[i], f = fs[i];
      const Mint x = bSum(bits1[e], f);
      const Mint ll = bSum(bitsL[e], f);
      const Mint rr = bSum(bitsR[e], iss[e].size()) - bSum(bitsR[e], f);
      const Mint sl = segL[e]->query(0, f, Entry(0, 0)).first;
      const Mint sr = segR[e]->query(f + 1, iss[e].size(), Entry(0, 0)).first;
      // i * *
      ret += ls[i] * (sr - x * rr);
      // * i *
      ret += ll * rr;
      // * * i
      ret += ((x - 1) * ll - sl) * rs[i];
      return ret;
    };
    
    Mint ans = 0;
    auto add = [&](int i) {
      ans += calc(i);
      const int e = es[i], f = fs[i];
      const Int x = bSum(bits1[e], f);
      bAdd<Int>(bits1[e], f, 1);
      bAdd<Int>(bitsL[e], f, ls[i]);
      bAdd<Int>(bitsR[e], f, rs[i]);
      segL[e]->query(f, f + 1, Entry(0, ls[i]));
      segL[e]->query(f, f + 1, Entry(x, 0));
      segL[e]->query(f + 1, iss[e].size(), Entry(1, 0));
      segR[e]->query(f, f + 1, Entry(x, rs[i]));
      segR[e]->query(f + 1, iss[e].size(), Entry(1, 0));
    };
    auto rem = [&](int i) {
      const int e = es[i], f = fs[i];
      const Int x = bSum(bits1[e], f);
      bAdd<Int>(bits1[e], f, -1);
      bAdd<Int>(bitsL[e], f, -ls[i]);
      bAdd<Int>(bitsR[e], f, -rs[i]);
      segL[e]->query(f, f + 1, Entry(-x, 0));
      segL[e]->query(f, f + 1, Entry(0, -ls[i]));
      segL[e]->query(f + 1, iss[e].size(), Entry(-1, 0));
      segR[e]->query(f, f + 1, Entry(-x, 0));
      segR[e]->query(f, f + 1, Entry(0, -rs[i]));
      segR[e]->query(f + 1, iss[e].size(), Entry(-1, 0));
      ans -= calc(i);
    };
    
    for (int i = 0; i < N; ++i) {
      add(i);
    }
    for (int m = 0; m < M; ++m) {
      if (T[m] == 1) {
        rem(X[m]);
      } else {
        add(X[m]);
      }
      printf("%d\n", ans.x);
    }
  }
  return 0;
}