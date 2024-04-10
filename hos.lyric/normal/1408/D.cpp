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

constexpr int LIM = 1'000'010;

int M, N;
vector<int> A, B, C, D;

int main() {
  for (; ~scanf("%d%d", &M, &N); ) {
    A.resize(M);
    B.resize(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &A[i], &B[i]);
    }
    C.resize(N);
    D.resize(N);
    for (int j = 0; j < N; ++j) {
      scanf("%d%d", &C[j], &D[j]);
    }
    
    vector<int> ys(LIM, 0);
    for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) {
      /*
        if A[i] + x <= C[j], then B[i] + y >= D[j] + 1 must hold
      */
      if (A[i] <= C[j]) {
        chmax(ys[C[j] - A[i]], D[j] + 1 - B[i]);
      }
    }
    for (int x = LIM - 1; x >= 1; --x) {
      chmax(ys[x - 1], ys[x]);
    }
    
    int ans = LIM + LIM;
    for (int x = 0; x < LIM; ++x) {
      chmin(ans, x + ys[x]);
    }
    printf("%d\n", ans);
  }
  return 0;
}