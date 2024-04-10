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
  template <class S> void ch(int a, const S &s) {
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

constexpr Int INF = 1001001001001001001LL;

struct NodeMax {
  Int mx;
  NodeMax() : mx(-INF) {}
  NodeMax(Int val) : mx(val) {}
  void merge(const NodeMax &l, const NodeMax &r) {
    mx = max(l.mx, r.mx);
  }
  void ch(Int val) {
    mx = val;
  }
  void chmax(Int val) {
    if (mx < val) mx = val;
  }
};

////////////////////////////////////////////////////////////////////////////////


int N;
vector<Int> A;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) for (; numCases--; ) {
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    
    vector<Int> ASum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
      ASum[i + 1] = ASum[i] + A[i];
    }
    auto xs = ASum;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    const int xsLen = xs.size();
    
    SegmentTreePoint<NodeMax> segM(xsLen), seg0(xsLen), segP(xsLen);
    
    vector<Int> dp(N + 1, -INF);
    for (int i = 0; i <= N; ++i) {
      const int pos = lower_bound(xs.begin(), xs.end(), ASum[i]) - xs.begin();
      if (i == 0) {
        dp[i] = 0;
      } else {
        chmax(dp[i], segM.get(0, pos).mx + i);
        chmax(dp[i], seg0.get(pos, pos + 1).mx);
        chmax(dp[i], segP.get(pos + 1, xsLen).mx - i);
      }
      segM.ch(pos, &NodeMax::chmax, dp[i] - i);
      seg0.ch(pos, &NodeMax::chmax, dp[i]);
      segP.ch(pos, &NodeMax::chmax, dp[i] + i);
    }
    
    printf("%lld\n", dp[N]);
  }
  return 0;
}