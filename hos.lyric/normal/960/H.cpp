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


constexpr int MAX = 50005;

int N, M, Q, C;
int F[MAX], P[MAX];
int D[MAX];
int T[MAX], X[MAX], K[MAX];

double anss[MAX];

int f[MAX];
int queriesLen;
// k, time, id, type
pair<pair<int, int>, pair<int, int>> queries[4 * MAX];


// ---------
Int vals[MAX];
void brute() {
  fill(vals, vals + N, 0);
  Int s1 = 0, s2 = 0;
  for (int h = 0; h < queriesLen; ++h) {
    switch (queries[h].second.second) {
      case +1: {
        const int u = queries[h].second.first;
        for (int v = u; v != -1; v = P[v]) {
          ++s1;
          s2 += vals[v];
        }
        for (int v = u; v != -1; v = P[v]) {
          ++vals[v];
        }
      } break;
      case -1: {
        const int u = queries[h].second.first;
        for (int v = u; v != -1; v = P[v]) {
          --vals[v];
        }
        for (int v = u; v != -1; v = P[v]) {
          --s1;
          s2 -= vals[v];
        }
      } break;
      case 0: {
        const int k = queries[h].first.first;
        double ans = 0.0;
        ans += 1.0 * C * C * N;
        ans -= 2.0 * C * D[k] * s1;
        ans += 1.0 * D[k] * D[k] * (s1 + 2.0 * s2);
        ans /= N;
        anss[queries[h].second.first] = ans;
      } break;
      default: assert(false);
    }
  }
  for (int q = 0; q < Q; ++q) {
    if (T[q] == 2) {
      printf("%.10f\n", anss[q]);
    }
  }
}
// ---------


vector<int> G[MAX];
int par[MAX], sz[MAX], dep[MAX];
int O, ord[MAX], head[MAX];

void dfs0(int u, int p) {
  par[u] = p;
  sz[u] = 1;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  for (const int v : G[u]) {
    if (v != p) {
      dfs0(v, u);
      sz[u] += sz[v];
    }
  }
}

void dfs1(int u, int p, int h) {
  ord[u] = O++;
  head[u] = h;
  int vm = -1;
  for (const int v : G[u]) {
    if (v != p) {
      if (vm == -1 || sz[vm] < sz[v]) {
        vm = v;
      }
    }
  }
  if (vm != -1) {
    dfs1(vm, u, h);
    for (const int v : G[u]) {
      if (v != p && v != vm) {
        dfs1(v, u, v);
      }
    }
  }
}

void solve() {
  for (int u = 0; u < N; ++u) {
    G[u].clear();
  }
  for (int u = 1; u < N; ++u) {
    G[P[u]].push_back(u);
  }
  const int rt = 0;
  dfs0(rt, -1);
  O = 0;
  dfs1(rt, -1, 0);
// cerr<<"ord = ";pv(ord,ord+N);
// cerr<<"head = ";pv(head,head+N);
  
  auto opTT = [](Int t0, Int t1) {
    return t0 + t1;
  };
  auto opST = [](Int s, Int t, Int sz) {
    return t + s * sz;
  };
  auto opSS = [](Int s0, Int s1) {
    return s0 + s1;
  };
  SegmentTree<Int, Int, decltype(opTT), decltype(opST), decltype(opSS)>
      seg(N, opTT, opST, opSS, 0, 0);
  
  // add val to the path from u to root
  auto query = [&](int u, int val) {
    Int ret = 0;
    for (; u != -1; ) {
      const Int h = head[u];
      ret += seg.query(ord[h], ord[u] + 1, val);
      u = par[h];
    }
    return ret;
  };
  
  Int s1 = 0, s2 = 0;
  for (int h = 0; h < queriesLen; ++h) {
    switch (queries[h].second.second) {
      case +1: {
        const int u = queries[h].second.first;
        s1 += (dep[u] + 1);
        s2 += query(u, 0);
        query(u, +1);
      } break;
      case -1: {
        const int u = queries[h].second.first;
        s1 -= (dep[u] + 1);
        s2 -= query(u, -1);
      } break;
      case 0: {
        const int k = queries[h].first.first;
        double ans = 0.0;
        ans += 1.0 * C * C * N;
        ans -= 2.0 * C * D[k] * s1;
        ans += 1.0 * D[k] * D[k] * (s1 + 2.0 * s2);
        ans /= N;
        anss[queries[h].second.first] = ans;
      } break;
      default: assert(false);
    }
  }
  for (int q = 0; q < Q; ++q) {
    if (T[q] == 2) {
      printf("%.10f\n", anss[q]);
    }
  }
}

int main() {
  for (; ~scanf("%d%d%d%d", &N, &M, &Q, &C); ) {
    for (int u = 0; u < N; ++u) {
      scanf("%d", &F[u]);
      --F[u];
    }
    P[0] = -1;
    for (int u = 1; u < N; ++u) {
      scanf("%d", &P[u]);
      --P[u];
    }
    for (int k = 0; k < M; ++k) {
      scanf("%d", &D[k]);
    }
    for (int q = 0; q < Q; ++q) {
      scanf("%d", &T[q]);
      if (T[q] == 1) {
        scanf("%d", &X[q]);
        --X[q];
      }
      scanf("%d", &K[q]);
      --K[q];
    }
    
    copy(F, F + N, f);
    queriesLen = 0;
    for (int u = 0; u < N; ++u) {
      queries[queriesLen++] = {{f[u], -1}, {u, +1}};
    }
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 1) {
        const int u = X[q];
        queries[queriesLen++] = {{f[u], q}, {u, -1}};
        f[u] = K[q];
        queries[queriesLen++] = {{f[u], q}, {u, +1}};
      } else {
        queries[queriesLen++] = {{K[q], q}, {q, 0}};
      }
    }
    for (int u = 0; u < N; ++u) {
      queries[queriesLen++] = {{f[u], Q}, {u, -1}};
    }
    sort(queries, queries + queriesLen);
    
    // brute();
    solve();
  }
  return 0;
}