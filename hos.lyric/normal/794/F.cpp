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
  /*
  T query(int a, int b, const S &s) {
    return query(1, 0, n, a, b, s);
  }
  */
  void queryUpdate(int a, int b, const S &s) {
    return queryUpdate(1, 0, n, a, b, s);
  }
  T queryCalc(int a, int b) {
    return queryCalc(1, 0, n, a, b);
  }

 private:
  /*
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
  */
  void queryUpdate(int u, int l, int r, int a, int b, const S &s) {
    if (a < l) a = l;
    if (b > r) b = r;
    if (a >= b) return;
    if (a == l && b == r) {
      ts[u] = opST(s, ts[u], r - l);
      ss[u] = opSS(s, ss[u]);
      return;
    }
    const int uL = u << 1, uR = u << 1 | 1;
    const int mid = (l + r) >> 1;
    // speed-up: 
    if (ss[u] != idS)
    {
      ts[uL] = opST(ss[u], ts[uL], mid - l);
      ts[uR] = opST(ss[u], ts[uR], r - mid);
      ss[uL] = opSS(ss[u], ss[uL]);
      ss[uR] = opSS(ss[u], ss[uR]);
      ss[u] = idS;
    }
    queryUpdate(uL, l, mid, a, b, s);
    queryUpdate(uR, mid, r, a, b, s);
    ts[u] = opTT(ts[uL], ts[uR]);
  }
  T queryCalc(int u, int l, int r, int a, int b) {
    if (a < l) a = l;
    if (b > r) b = r;
    if (a >= b) return idT;
    if (a == l && b == r) {
      return ts[u];
    }
    const int uL = u << 1, uR = u << 1 | 1;
    const int mid = (l + r) >> 1;
    // speed-up: 
    if (ss[u] != idS)
    {
      ts[uL] = opST(ss[u], ts[uL], mid - l);
      ts[uR] = opST(ss[u], ts[uR], r - mid);
      ss[uL] = opSS(ss[u], ss[uL]);
      ss[uR] = opSS(ss[u], ss[uR]);
      ss[u] = idS;
    }
    const T resL = queryCalc(uL, l, mid, a, b);
    const T resR = queryCalc(uR, mid, r, a, b);
    ts[u] = opTT(ts[uL], ts[uR]);
    return opTT(resL, resR);
  }
};


constexpr int V = 10;
using T = array<Int, V>;
using S = array<int, V>;
T opTT(const T &t0, const T &t1) {
  T ret;
  for (int u = 0; u < V; ++u) {
    ret[u] = t0[u] + t1[u];
  }
  return ret;
}
T opST(const S &s, const T &t, int sz) {
  T ret = {};
  for (int u = 0; u < V; ++u) {
    ret[s[u]] += t[u];
  }
  return ret;
}
S opSS(const S &s0, const S &s1) {
  S ret;
  for (int u = 0; u < V; ++u) {
    ret[u] = s0[s1[u]];
  }
  return ret;
}


int main() {
  T idT = {};
  S idS;
  iota(idS.begin(), idS.end(), 0);
  
  int N, Q;
  for (; ~scanf("%d%d", &N, &Q); ) {
    vector<Int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    
    SegmentTree<T, S, decltype(&opTT), decltype(&opST), decltype(&opSS)> 
        seg(N, opTT, opST, opSS, idT, idS);
    for (int i = 0; i < N; ++i) {
      for (Int a = A[i], ten = 1; a > 0; a /= 10, ten *= 10) {
// cerr<<i<<" "<<a%10<<" "<<ten<<endl;
        seg.at(i)[a % 10] += ten;
      }
    }
    seg.build();
    
    for (int q = 0; q < Q; ++q) {
      int typ;
      scanf("%d", &typ);
      switch (typ) {
        case 1: {
          int l, r, x, y;
          scanf("%d%d%d%d", &l, &r, &x, &y);
          --l;
          S s = idS;
          s[x] = y;
// cerr<<"s = ";pv(s.begin(),s.end());
          seg.queryUpdate(l, r, s);
        } break;
        case 2: {
          int l, r;
          scanf("%d%d", &l, &r);
          --l;
          const T res = seg.queryCalc(l, r);
// cerr<<"res = ";pv(res.begin(),res.end());
          Int ans = 0;
          for (int u = 0; u < V; ++u) {
            ans += res[u] * u;
          }
          printf("%lld\n", ans);
        } break;
        default: assert(false);
      }
    }
  }
  return 0;
}