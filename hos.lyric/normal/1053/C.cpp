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
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
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

constexpr unsigned MO = 1000000007;
using Mint = ModInt<MO>;


// T: monoid representing information of an interval.
//   T()  should return the identity.
//   T(S s)  should represent a single element of the array.
//   T::merge(const T &l, const T &r)  should merge two intervals.
template <class T> struct SegmentTreePoint {
  int logN, n;
  vector<T> ts;
  SegmentTreePoint() {}
  explicit SegmentTreePoint(int n_) {
    for (logN = 0, n = 1; n < n_; ++logN, n <<= 1) {}
    ts.resize(n << 1);
  }
  template <class S> explicit SegmentTreePoint(const vector<S> &ss) {
    const int n_ = ss.size();
    for (logN = 0, n = 1; n < n_; ++logN, n <<= 1) {}
    ts.resize(n << 1);
    for (int i = 0; i < n_; ++i) at(i) = T(ss[i]);
    build();
  }
  T &at(int i) {
    return ts[n + i];
  }
  void build() {
    for (int u = n; --u; ) merge(u);
  }

  inline void merge(int u) {
    ts[u].merge(ts[u << 1], ts[u << 1 | 1]);
  }

  // Changes the value of point a to s.
  template <class S> void change(int a, const S &s) {
    assert(0 <= a); assert(a < n);
    ts[a += n] = T(s);
    for (; a >>= 1; ) merge(a);
  }

  // Applies T::f(args...) to point a.
  template <class F, class... Args>
  void ch(int a, F f, Args &&... args) {
    assert(0 <= a); assert(a < n);
    (ts[a += n].*f)(args...);
    for (; a >>= 1; ) merge(a);
  }

  // Calculates the product for [a, b).
  T get(int a, int b) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return T();
    a += n; b += n;
    T prodL, prodR, t;
    for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1) {
      if (aa & 1) { t.merge(prodL, ts[aa++]); prodL = t; }
      if (bb & 1) { t.merge(ts[--bb], prodR); prodR = t; }
    }
    t.merge(prodL, prodR);
    return t;
  }

  // Calculates T::f(args...) of a monoid type for [a, b).
  //   op(-, -)  should calculate the product.
  //   e()  should return the identity.
  template <class Op, class E, class F, class... Args>
#if __cplusplus >= 201402L
  auto
#else
  decltype((std::declval<T>().*F())())
#endif
  get(int a, int b, Op op, E e, F f, Args &&... args) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return e();
    a += n; b += n;
    auto prodL = e(), prodR = e();
    for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1) {
      if (aa & 1) prodL = op(prodL, (ts[aa++].*f)(args...));
      if (bb & 1) prodR = op((ts[--bb].*f)(args...), prodR);
    }
    return op(prodL, prodR);
  }

  // Find min b s.t. T::f(args...) returns true,
  // when called for the partition of [a, b) from left to right.
  //   Returns n + 1 if there is no such b.
  template <class F, class... Args>
  int findRight(int a, F f, Args &&... args) {
    assert(0 <= a); assert(a <= n);
    if ((T().*f)(args...)) return a;
    if (a == n) return n + 1;
    a += n;
    for (; ; a >>= 1) if (a & 1) {
      if ((ts[a].*f)(args...)) {
        for (; a < n; ) {
          if (!(ts[a <<= 1].*f)(args...)) ++a;
        }
        return a - n + 1;
      }
      ++a;
      if (!(a & (a - 1))) return n + 1;
    }
  }

  // Find max a s.t. T::f(args...) returns true,
  // when called for the partition of [a, b) from right to left.
  //   Returns -1 if there is no such a.
  template <class F, class... Args>
  int findLeft(int b, F f, Args &&... args) {
    assert(0 <= b); assert(b <= n);
    if ((T().*f)(args...)) return b;
    if (b == 0) return -1;
    b += n;
    for (; ; b >>= 1) if ((b & 1) || b == 2) {
      if ((ts[b - 1].*f)(args...)) {
        for (; b <= n; ) {
          if (!(ts[(b <<= 1) - 1].*f)(args...)) --b;
        }
        return b - n - 1;
      }
      --b;
      if (!(b & (b - 1))) return -1;
    }
  }
};

////////////////////////////////////////////////////////////////////////////////

struct Node {
  Int w;
  Mint aw;
  Node() : w(0), aw(0) {}
  Node(const pair<Int, Mint> val) : w(val.first), aw(val.second) {}
  void merge(const Node &l, const Node &r) {
    w = l.w + r.w;
    aw = l.aw + r.aw;
  }
  bool accW(Int &acc, Int tar) const {
    if (acc + w >= tar) return true;
    acc += w;
    return false;
  }
};


int N, Q;
vector<Int> A, W;

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    A.resize(N); for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
    W.resize(N); for (int i = 0; i < N; ++i) scanf("%lld", &W[i]);
    
    for (int i = 0; i < N; ++i) {
      A[i] -= i;
    }
    
    vector<pair<Int, Mint>> ini(N);
    for (int i = 0; i < N; ++i) {
      ini[i] = make_pair(W[i], Mint(A[i] * W[i]));
    }
    SegmentTreePoint<Node> seg(ini);
    
    for (; Q--; ) {
      int l;
      scanf("%d", &l);
      if (l < 0) {
        const int i = (-l) - 1;
        Int w;
        scanf("%lld", &w);
        
        W[i] = w;
        seg.change(i, make_pair(w, Mint(A[i] * w)));
      } else {
        --l;
        int r;
        scanf("%d", &r);
// cerr<<"W = "<<W<<", l = "<<l<<", r = "<<r<<endl;
        
        const Node all = seg.get(l, r);
        const Int half = (all.w + 1) / 2;
        Int acc = 0;
        const int pos = seg.findRight(l, &Node::accW, acc, half);
        assert(l < pos);
        assert(pos <= r);
        const Node resL = seg.get(l, pos);
        const Mint goal = A[pos - 1];
// cerr<<"  pos = "<<pos<<", goal = "<<goal<<endl;
        
        Mint ans = 0;
        ans += (goal * resL.w - resL.aw);
        ans += ((all.aw - resL.aw) - goal * (all.w - resL.w));
        printf("%u\n", ans.x);
      }
    }
  }
  return 0;
}