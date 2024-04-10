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

struct Node {
  int a, b, c;
  Node() : a(0), b(0), c(0) {}
  Node(int s) {
    if (s) {
      a = 0;
      b = 1;
      c = 0;
    } else {
      a = 1;
      b = 0;
      c = 0;
    }
  }
  void merge(const Node &l, const Node &r) {
    const int d = l.c + r.a;
    if (d == 0) {
      a = l.a;
      b = l.b + r.b;
      c = r.c;
    } else {
      if (l.b == 0) {
        a = l.a + d;
        b = r.b;
        c = r.c;
      } else if (r.b == 0) {
        a = l.a;
        b = l.b;
        c = d + r.c;
      } else {
        if (d & 1) {
          const int mn = min(l.b, r.b);
          // l.a, l.b-mn, 1, r.b-mn, r.c
          a = l.a;
          b = (l.b - mn) + (r.b - mn);
          c = r.c;
          (l.b == mn) ? ++a : ++c;
        } else {
          a = l.a;
          b = l.b + r.b;
          c = r.c;
        }
      }
    }
    if (b == 0) {
      a += c;
      c = 0;
    }
  }
};


int N, Q;
char A[200'010];

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    scanf("%s", A);
    
    vector<char> as(N);
    for (int i = 0; i < N; ++i) {
      as[i] = A[i] ^ (i & 1);
    }
    vector<int> xs, ss;
    for (int i = 0, j; i < N; i = j) {
      for (j = i; j < N && as[i] == as[j]; ++j) {}
      xs.push_back(i);
      ss.push_back((j - i) & 1);
    }
    xs.push_back(N);
// cerr<<"xs = ";pv(xs.begin(),xs.end());
// cerr<<"ss = ";pv(ss.begin(),ss.end());
    
    SegmentTreePoint<Node> seg(ss);
    
    for (; Q--; ) {
      int L, R;
      scanf("%d%d", &L, &R);
      --L;
      
      const int l = lower_bound(xs.begin(), xs.end(), L) - xs.begin();
      const int r = upper_bound(xs.begin(), xs.end(), R) - xs.begin() - 1;
      int ans = 0;
      if (l <= r) {
        int bef = r - l;
        Node f = seg.get(l, r);
// cerr<<"f = "<<f.a<<" "<<f.b<<" "<<f.c<<endl;
        if (L < xs[l]) {
          ++bef;
          Node g((xs[l] - L) & 1);
          Node ff;
          ff.merge(g, f);
          f = ff;
        }
        if (xs[r] < R) {
          ++bef;
          Node g((R - xs[r]) & 1);
          Node ff;
          ff.merge(f, g);
          f = ff;
        }
// cerr<<"f = "<<f.a<<" "<<f.b<<" "<<f.c<<endl;
        const int aft = f.a + f.b + f.c;
        assert((bef - aft) % 2 == 0);
        ans = (bef - aft) / 2;
        int a = f.a, c = f.c;
        if (f.b > 0) {
          ans += a / 2; a %= 2;
          ans += c / 2; c %= 2;
        }
        ans += f.b;
        if (a + c > 0) {
          ans += (a + c) / 2 + 1;
        }
      } else {
        ans = 1;
      }
      printf("%d\n", ans);
      
#ifdef LOCAL
const string s(A+L,A+R);
const int n=s.size();
vector<int>dp(1<<n,n);
dp[0]=0;
for(int p=1;p<1<<n;++p){
 for(int i=0;i<=n;++i)for(int j=i+1;j<=n;++j){
  int pp=p;
  int last=-1;
  bool ok=true;
  for(int k=i;k<j;++k)if(p>>k&1){
   pp^=1<<k;
   ok=ok&&(last!=s[k]);
   last=s[k];
  }
  if(ok)chmin(dp[p],1+dp[pp]);
 }
}
const int brt=dp.back();
cerr<<"brt = "<<brt<<endl;
if(brt!=ans){
 cerr<<"A = "<<A<<endl;
 cerr<<"s = "<<s<<endl;
 assert(false);
}
#endif
    }
#ifdef LOCAL
cerr<<"========"<<endl;
#endif
  }
  return 0;
}