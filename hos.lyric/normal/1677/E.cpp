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


// root: max (tie-break: left)
struct MaxCartesianTree {
  int n, rt;
  vector<int> par, lef, rig;
  template <class T> void build(int n_, T *as) {
    assert(n_ >= 1);
    n = n_;
    rt = 0;
    par.assign(n, -1);
    lef.assign(n, -1);
    rig.assign(n, -1);
    int top = 0;
    vector<int> stack(n, 0);
    for (int u = 1; u < n; ++u) {
      if (as[stack[top]] < as[u]) {  // <
        for (; top >= 1 && as[stack[top - 1]] < as[u]; --top) {}  // <
        if (top == 0) {
          rt = par[lef[u] = stack[top]] = u;
        } else {
          par[lef[u] = stack[top]] = u;
          rig[par[u] = stack[top - 1]] = u;
        }
        stack[top] = u;
      } else {
        rig[par[u] = stack[top]] = u;
        stack[++top] = u;
      }
    }
  }
  template <class T> void build(const T &as) {
    build(as.size(), as.data());
  }
};


////////////////////////////////////////////////////////////////////////////////


// T: monoid representing information of an interval.
//   T()  should return the identity.
//   T(S s)  should represent a single element of the array.
//   T::push(T &l, T &r)  should push the lazy update.
//   T::merge(const T &l, const T &r)  should merge two intervals.
template <class T> struct SegmentTreeRange {
  int logN, n;
  vector<T> ts;
  SegmentTreeRange() {}
  explicit SegmentTreeRange(int n_) {
    for (logN = 0, n = 1; n < n_; ++logN, n <<= 1) {}
    ts.resize(n << 1);
  }
  template <class S> explicit SegmentTreeRange(const vector<S> &ss) {
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

  inline void push(int u) {
    ts[u].push(ts[u << 1], ts[u << 1 | 1]);
  }
  inline void merge(int u) {
    ts[u].merge(ts[u << 1], ts[u << 1 | 1]);
  }

  // Applies T::f(args...) to [a, b).
  template <class F, class... Args>
  void ch(int a, int b, F f, Args &&... args) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return;
    a += n; b += n;
    for (int h = logN; h; --h) {
      const int aa = a >> h, bb = b >> h;
      if (aa == bb) {
        if ((aa << h) != a || (bb << h) != b) push(aa);
      } else {
        if ((aa << h) != a) push(aa);
        if ((bb << h) != b) push(bb);
      }
    }
    for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1) {
      if (aa & 1) (ts[aa++].*f)(args...);
      if (bb & 1) (ts[--bb].*f)(args...);
    }
    for (int h = 1; h <= logN; ++h) {
      const int aa = a >> h, bb = b >> h;
      if (aa == bb) {
        if ((aa << h) != a || (bb << h) != b) merge(aa);
      } else {
        if ((aa << h) != a) merge(aa);
        if ((bb << h) != b) merge(bb);
      }
    }
  }

  // Calculates the product for [a, b).
  T get(int a, int b) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return T();
    a += n; b += n;
    for (int h = logN; h; --h) {
      const int aa = a >> h, bb = b >> h;
      if (aa == bb) {
        if ((aa << h) != a || (bb << h) != b) push(aa);
      } else {
        if ((aa << h) != a) push(aa);
        if ((bb << h) != b) push(bb);
      }
    }
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
    for (int h = logN; h; --h) {
      const int aa = a >> h, bb = b >> h;
      if (aa == bb) {
        if ((aa << h) != a || (bb << h) != b) push(aa);
      } else {
        if ((aa << h) != a) push(aa);
        if ((bb << h) != b) push(bb);
      }
    }
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
    for (int h = logN; h; --h) push(a >> h);
    for (; ; a >>= 1) if (a & 1) {
      if ((ts[a].*f)(args...)) {
        for (; a < n; ) {
          push(a);
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
    for (int h = logN; h; --h) push((b - 1) >> h);
    for (; ; b >>= 1) if ((b & 1) || b == 2) {
      if ((ts[b - 1].*f)(args...)) {
        for (; b <= n; ) {
          push(b - 1);
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


template <class T> struct RectAddRectSum {
  struct Rect {
    int x0, x1, y0, y1;
  };
  int m, n;
  vector<Rect> as, bs;
  vector<T> vals, anss;
  RectAddRectSum() {}
  RectAddRectSum(int m_, int n_) : m(m_), n(n_), as(), bs(), anss() {
    assert(m >= 0);
    assert(n >= 0);
  }
  void add(int x0, int x1, int y0, int y1, const T &val) {
// cerr<<"add "<<x0<<" "<<x1<<" "<<y0<<" "<<y1<<" "<<val<<endl;
    assert(0 <= x0); assert(x0 <= x1); assert(x1 <= m);
    assert(0 <= y0); assert(y0 <= y1); assert(y1 <= n);
    as.push_back(Rect{x0, x1, y0, y1});
    vals.push_back(val);
  }
  void get(int x0, int x1, int y0, int y1) {
    assert(0 <= x0); assert(x0 <= x1); assert(x1 <= m);
    assert(0 <= y0); assert(y0 <= y1); assert(y1 <= n);
    bs.push_back(Rect{x0, x1, y0, y1});
  }

  // range add range sum (deg <= 1)
  struct Node {
    int sz;
    T sum0, sum1;
    T lz0, lz1;
    Node() : sz(0), sum0(0), sum1(0), lz0(0), lz1(0) {}
    Node(int) : sz(1), sum0(0), sum1(0), lz0(0), lz1(0) {}
    void push(Node &l, Node &r) {
      l.add(lz0, lz1);
      r.add(lz0, lz1);
      lz0 = lz1 = 0;
    }
    void merge(const Node &l, const Node &r) {
      sz = l.sz + r.sz;
      sum0 = l.sum0 + r.sum0;
      sum1 = l.sum1 + r.sum1;
    }
    void add(const T &val0, const T &val1) {
      sum0 += val0 * sz;
      sum1 += val1 * sz;
      lz0 += val0;
      lz1 += val1;
    }
  };
  void run() {
    const int asLen = as.size(), bsLen = bs.size();
    vector<vector<int>> addss(m + 1), remss(m + 1);
    vector<vector<pair<int, int>>> getss(m + 1);
    for (int i = 0; i < asLen; ++i) {
      addss[as[i].x0].push_back(i);
      remss[as[i].x1].push_back(i);
    }
    for (int j = 0; j < bsLen; ++j) {
      getss[bs[j].x0].emplace_back(j, -1);
      getss[bs[j].x1].emplace_back(j, +1);
    }
    SegmentTreeRange<Node> seg(vector<T>(n, 0));
    anss.assign(bsLen, 0);
    for (int x = 0; x <= m; ++x) {
      for (const int i : remss[x]) {
        seg.ch(as[i].y0, as[i].y1, &Node::add, vals[i] * x, -vals[i]);
      }
      for (const auto &e : getss[x]) {
        const int j = e.first;
        const Node res = seg.get(bs[j].y0, bs[j].y1);
        anss[j] += e.second * (res.sum0 + res.sum1 * x);
      }
      for (const int i : addss[x]) {
        seg.ch(as[i].y0, as[i].y1, &Node::add, -vals[i] * x, vals[i]);
      }
    }
  }
};


int N, Q;
vector<int> P;
vector<int> L, R;

vector<int> poss;
vector<vector<int>> dss;
MaxCartesianTree ct;
RectAddRectSum<Int> dat;

void dfs(int u, int l, int r) {
  if (!~u) {
    return;
  }
  vector<pair<int, int>> fs;
  for (const int d : dss[P[u]]) {
    const int e = P[u] / d;
    if (d < e) {
      const int ll = min({u, poss[d], poss[e]});
      const int rr = max({u, poss[d], poss[e]}) + 1;
      if (l <= ll && rr <= r) {
// cerr<<l<<" "<<ll<<" "<<rr<<" "<<r<<endl;
        fs.emplace_back(ll + 1, rr);
      }
    }
  }
  /*
    r   ** 
        *  
    u+1    
        l u
  */
// cerr<<"fs = ";pv(fs.begin(),fs.end());
  sort(fs.begin(), fs.end());
  const int fsLen = fs.size();
  for (int j = fsLen - 1; --j >= 0; ) {
    chmin(fs[j].second, fs[j + 1].second);
  }
  int bef = l;
  for (int j = 0; j < fsLen; ++j) {
    if (bef < fs[j].first) {
      dat.add(bef, fs[j].first, fs[j].second, r + 1, 1);
    }
    bef = fs[j].first;
  }
  
  dfs(ct.lef[u], l, u);
  dfs(ct.rig[u], u + 1, r);
}

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    P.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
    }
    L.resize(Q);
    R.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d", &L[q], &R[q]);
      --L[q];
    }
    
    poss.assign(N + 1, -1);
    for (int i = 0; i < N; ++i) {
      poss[P[i]] = i;
    }
    dss.assign(N + 1, {});
    for (int d = 1; d <= N; ++d) {
      for (int c = d; c <= N; c += d) {
        dss[c].push_back(d);
      }
    }
    ct.build(P);
    dat = RectAddRectSum<Int>(N + 1, N + 1);
    dfs(ct.rt, 0, N);
    
    for (int q = 0; q < Q; ++q) {
      dat.get(L[q], R[q] + 1, L[q], R[q] + 1);
    }
    dat.run();
    
    for (int q = 0; q < Q; ++q) {
      printf("%lld\n", dat.anss[q]);
    }
#ifdef LOCAL
vector<Int>slw(Q,0);
for(int q=0;q<Q;++q)for(int i=0;i<(int)dat.as.size();++i){
 const int x0=max(L[q],dat.as[i].x0);
 const int x1=min(R[q]+1,dat.as[i].x1);
 const int y0=max(L[q],dat.as[i].y0);
 const int y1=min(R[q]+1,dat.as[i].y1);
 if(x0<x1&&y0<y1)slw[q]+=dat.vals[i]*(x1-x0)*(y1-y0);
}
cerr<<"slw = ";pv(slw.begin(),slw.end());
vector<Int>brt(Q,0);
for(int q=0;q<Q;++q){
 for(int l=L[q];l<=R[q];++l)for(int r=l+1;r<=R[q];++r){
  const int c=*max_element(P.begin()+l,P.begin()+r);
  bool ok=false;
  for(int i=l;i<r;++i)for(int j=i+1;j<r;++j)ok=ok||(P[i]*P[j]==c);
  if(ok)++brt[q];
 }
}
cerr<<"brt = ";pv(brt.begin(),brt.end());
cerr<<"========"<<endl;
#endif
  }
  return 0;
}