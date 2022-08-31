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


template<class T> void bitAdd(vector<T> &bit, int pos, const T &val) {
  const int bitN = bit.size();
  for (int x = pos; x < bitN; x |= x + 1) bit[x] += val;
}
template<class T> T bitSum(const vector<T> &bit, int pos) {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
  return ret;
}
template<class T> T bitSum(const vector<T> &bit, int pos0, int pos1) {
  return bitSum(bit, pos1) - bitSum(bit, pos0);
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


constexpr Int INF = 1'000'000'000'000'000'000LL;

using T = pair<Int, int>;
T opTT(const T &t0, const T &t1) {
  return max(t0, t1);
}
T opST(Int s, const T & t, Int sz) {
  return make_pair(s + t.first, t.second);
}
Int opSS(Int s0, Int s1) {
  return s0 + s1;
}


int N, Q;
vector<int> A;
vector<int> X, Y;

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    X.resize(Q);
    Y.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d", &X[q], &Y[q]);
    }
    
    vector<vector<int>> qss(N);
    for (int q = 0; q < Q; ++q) {
      qss[X[q]].push_back(q);
    }
    
    vector<int> ans(Q);
    vector<int> bit(N, 0);
    
    SegmentTree<T, Int, decltype(&opTT), decltype(&opST), decltype(&opSS)>
        seg(N, opTT, opST, opSS, make_pair(-INF, -1), 0);
    for (int i = 0; i < N; ++i) {
      seg.at(i) = make_pair(0, i);
    }
    seg.build();
    
    for (int i = N; i--; ) {
// cerr<<"i = "<<i<<endl;
      const int b = A[i] - (i + 1);
      if (b <= 0) {
        seg.query(i, i + 1, b);
      } else {
        seg.query(i, i + 1, -2 * N);
      }
      for (; ; ) {
        const T res = seg.query(i, N, 0);
        if (res.first >= 0) {
// cerr<<"  res = "<<res<<endl;
          const int j = res.second;
          bitAdd(bit, j, +1);
          seg.query(j, j + 1, -2 * N - res.first);
          seg.query(j + 1, N, 1);
        } else {
          break;
        }
      }
      for (const int q : qss[i]) {
        ans[q] = bitSum(bit, N - Y[q]);
      }
    }
    
    for (int q = 0; q < Q; ++q) {
      printf("%d\n", ans[q]);
    }
  }
  return 0;
}