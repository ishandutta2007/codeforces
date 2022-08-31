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

int N, M;
int A[6010], B[6010];

vector<vector<int>> G;
Int sz[6010];
Int dp[6010][6010];

Int calcSize(int i) {
  Int &ret = sz[i];
  if (ret == -1) {
    ret = 1;
    for (const int j : G[B[i]]) {
      if (j != (i ^ 1)) {
        ret += calcSize(j);
      }
    }
  }
  return ret;
}

Int calc(int i, int j) {
  if (i > j) {
    swap(i, j);
  }
  Int &ret = dp[i][j];
  if (ret == -1) {
    ret = 0;
    for (const int k : G[B[i]]) {
      if (k != (i ^ 1)) {
        chmax(ret, calc(k, j));
      }
    }
    for (const int k : G[B[j]]) {
      if (k != (j ^ 1)) {
        chmax(ret, calc(i, k));
      }
    }
    ret += sz[i] * sz[j];
  }
  return ret;
}

int main() {
  for (; ~scanf("%d", &N); ) {
    M = (N - 1) * 2;
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u;
      --v;
      A[i * 2 + 0] = u; B[i * 2 + 0] = v;
      A[i * 2 + 1] = v; B[i * 2 + 1] = u;
    }
    
    G.assign(N, {});
    for (int i = 0; i < M; ++i) {
      G[A[i]].push_back(i);
    }
    fill(sz, sz + M, -1);
    for (int i = 0; i < M; ++i) {
      calcSize(i);
    }
// cerr<<"sz = ";pv(sz,sz+M);
    for (int i = 0; i < M; ++i) {
      fill(dp[i], dp[i] + M, -1);
    }
    Int ans = 0;
    for (int i = 0; i < M; i += 2) {
      chmax(ans, calc(i, i ^ 1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}