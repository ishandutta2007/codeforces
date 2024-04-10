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

constexpr int MAX_N = 100005;
constexpr int MAX_K = 12;
constexpr int MAX_Q = 100005;

int N, K, Q;
int A[MAX_N][MAX_K];
int T[MAX_Q], X[MAX_Q], Y[MAX_Q];

int V;
bitset<(1 << MAX_K)> bs[MAX_K + MAX_Q];

pair<int, int> pss[MAX_N][MAX_K];
int fs[MAX_N][MAX_K];

int main() {
  for (; ~scanf("%d%d%d", &N, &K, &Q); ) {
    for (int k = 0; k < K; ++k) {
      for (int n = 0; n < N; ++n) {
        scanf("%d", &A[n][k]);
      }
    }
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d%d", &T[q], &X[q], &Y[q]);
      --X[q];
      --Y[q];
    }
    
    for (int k = 0; k < K; ++k) {
      bs[k].reset();
      for (int p = 0; p < 1 << K; ++p) {
        if (p & 1 << k) {
          bs[k][p] = true;
        }
      }
    }
    V = K;
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 1) {
        bs[V++] = bs[X[q]] | bs[Y[q]];
      } else if (T[q] == 2) {
        bs[V++] = bs[X[q]] & bs[Y[q]];
      }
    }
// for(int u=0;u<V;++u){for(int p=0;p<1<<K;++p){cerr<<bs[u][p];}cerr<<endl;}
    
    for (int n = 0; n < N; ++n) {
      for (int k = 0; k < K; ++k) {
        pss[n][k] = {A[n][k], k};
      }
      sort(pss[n], pss[n] + K);
      for (int l = 0; l < K; ++l) {
        fs[n][l] = 1 << pss[n][l].second;
      }
      for (int l = K - 2; l >= 0; --l) {
        fs[n][l] |= fs[n][l + 1];
      }
// cerr<<"pss["<<n<<"] = ";pv(pss[n],pss[n]+K);
// cerr<<"fs["<<n<<"] = ";pv(fs[n],fs[n]+K);
    }
    
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 3) {
        const int u = X[q];
        const int n = Y[q];
        int lo = 0, hi = K;
        for (; lo + 1 < hi; ) {
          const int mid = (lo + hi) / 2;
          (bs[u][fs[n][mid]] ? lo : hi) = mid;
        }
        printf("%d\n", pss[n][lo].first);
      }
    }
  }
  return 0;
}