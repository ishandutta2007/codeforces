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

// O~(N 2^E + Q N / 2^E)
#ifdef LOCAL
constexpr int E = 2;
#else
constexpr int E = 11;
#endif
constexpr int L = 16;

struct Tree {
  Tree *child[2];
  int val;
  Tree() : val(-1) {
    child[0] = child[1] = nullptr;
  }
};
string toString(Tree *x) {
  return x ? ("(" + toString(x->child[0]) + toString(x->child[1]) + ")") : "";
}

int N, Q;
vector<int> C;
vector<int> A, B;
vector<int> U, V;

vector<vector<int>> G;
vector<vector<int>> par;
vector<int> dep;

void dfs(int u, int p) {
  par[0][u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  for (const int i : G[u]) {
    const int v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
    }
  }
}

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    C.resize(N);
    for (int u = 0; u < N; ++u) {
      scanf("%d", &C[u]);
    }
    A.resize(N - 1);
    B.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    U.resize(Q);
    V.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d", &U[q], &V[q]);
      --U[q];
      --V[q];
    }
    
    G.assign(N, {});
    for (int i = 0; i < N - 1; ++i) {
      G[A[i]].push_back(i);
      G[B[i]].push_back(i);
    }
    par.assign(E + 1, vector<int>(N));
    dep.resize(N);
    dfs(0, -1);
    for (int e = 0; e < E; ++e) {
      for (int u = 0; u < N; ++u) {
        par[e + 1][u] = (par[e][u] == -1) ? -1 : par[e][par[e][u]];
      }
    }
    
    // 2^E
    vector<Tree *> ts(N, nullptr);
    for (int u = 0; u < N; ++u) {
      if (dep[u] - (1 << E) >= -1) {
        ts[u] = new Tree;
        int v = u;
        for (int j = 0; j < 1 << E; ++j) {
          const int val = C[v] ^ j;
          Tree *x = ts[u];
          for (int l = L; --l >= E; ) {
            const int s = (val >> l) & 1;
            if (!x->child[s]) {
              x->child[s] = new Tree;
            }
            x = x->child[s];
          }
          chmax(x->val, val & ((1 << E) - 1));
          v = par[0][v];
        }
      }
    }
    
    for (int q = 0; q < Q; ++q) {
      int ans = 0;
      int val = 0;
      int u = V[q];
      for (; u != -1 && dep[u] - (1 << E) >= dep[U[q]] - 1; u = par[E][u], val += (1 << E)) {
        int score = 0;
        Tree *x = ts[u];
        for (int l = L; --l >= E; ) {
          const int s = (val >> l) & 1;
          if (x->child[s ^ 1]) {
            score ^= 1 << l;
            x = x->child[s ^ 1];
          } else {
            x = x->child[s];
          }
        }
        score |= x->val;
        chmax(ans, score);
      }
      for (; u != -1 && dep[u] >= dep[U[q]]; u = par[0][u], ++val) {
        chmax(ans, C[u] ^ val);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}