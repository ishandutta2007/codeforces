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

using Double = double;

constexpr Double INF = 1e20;

Double X, Y;

struct Node {
  Double f[3][3];
  Node() {
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      f[i][j] = -INF;
    }
    for (int i = 0; i < 3; ++i) {
      f[i][i] = 0.0;
    }
  }
  Node(Double val) {
    f[0][0] = f[1][0] = f[2][0] = 0.0;
    f[0][1] = f[1][1] = f[2][1] = val / (X + Y);
    f[0][2] = f[1][2] = f[2][2] = val / Y;
    f[2][1] = -INF;
    f[1][2] = -INF;
    f[2][2] = -INF;
  }
  void merge(const Node &l, const Node &r) {
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      f[i][j] = -INF;
    }
    for (int i = 0; i < 3; ++i) for (int k = 0; k < 3; ++k) for (int j = 0; j < 3; ++j) {
      chmax(f[i][j], l.f[i][k] + r.f[k][j]);
    }
  }
};

////////////////////////////////////////////////////////////////////////////////

int N, Q;
vector<Double> B;

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    {
      int x, y;
      scanf("%d%d", &x, &y);
      if (x > y) {
        swap(x, y);
      }
      X = x;
      Y = y;
    }
    B.resize(N);
    for (int i = 0; i < N; ++i) {
      int b;
      scanf("%d", &b);
      B[i] = b;
    }
// cerr<<"X = "<<X<<", Y = "<<Y<<", B = "<<B<<endl;
    
    SegmentTreePoint<Node> seg(B);
    
    for (; Q--; ) {
      int typ;
      scanf("%d", &typ);
      if (typ == 1) {
        int K, V;
        scanf("%d%d", &K, &V);
        --K;
        seg.change(K, (Double)V);
      } else {
        int L, R;
        scanf("%d%d", &L, &R);
        --L;
// cerr<<"L = "<<L<<", R = "<<R<<endl;
        const auto res = seg.get(L, R);
// for(int i=0;i<3;++i){cerr<<"resf.["<<i<<"] = ";pv(res.f[i],res.f[i]+3);}
        Double ans = -INF;
        for (int j = 0; j < 3; ++j) {
          chmax(ans, res.f[0][j]);
        }
        printf("%.12f\n", (double)ans);
      }
    }
  }
  return 0;
}