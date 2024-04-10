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


// [0, n), 1 <= n <= 2^(6D)
template <int D> struct Set {
  int n;
  vector<uint64_t> a[D];
  Set() {}
  Set(int n_) : n(n_) {
    static_assert(1 <= D && D <= 6, "Set: 1 <= D <= 6 must hold");
    assert(1 <= n_ && n_ <= 1LL << (6 * D));
    for (int d = 0; d < D; ++d) {
      n_ = (n_ + 63) >> 6;
      a[d].assign(n_, 0);
    }
  }
  bool empty() const {
    return !a[D - 1][0];
  }
  bool contains(int x) const {
    return (a[0][x >> 6] >> (x & 63)) & 1;
  }
  void insert(int x) {
    for (int d = 0; d < D; ++d) {
      const int q = x >> 6, r = x & 63;
      a[d][q] |= 1ULL << r;
      x = q;
    }
  }
  void erase(int x) {
    for (int d = 0; d < D; ++d) {
      const int q = x >> 6, r = x & 63;
      if ((a[d][q] &= ~(1ULL << r))) break;
      x = q;
    }
  }
  // min s.t. >= x
  int next(int x) const {
    for (int d = 0; d < D; ++d) {
      const int q = x >> 6, r = x & 63;
      if (static_cast<size_t>(q) >= a[d].size()) break;
      const uint64_t upper = a[d][q] >> r;
      if (upper) {
        x += __builtin_ctzll(upper);
        for (int e = d - 1; e >= 0; --e) x = x << 6 | __builtin_ctzll(a[e][x]);
        return x;
      }
      x = q + 1;
    }
    return n;
  }
  // max s.t. <= x
  int prev(int x) const {
    for (int d = 0; d < D; ++d) {
      if (x < 0) break;
      const int q = x >> 6, r = x & 63;
      const uint64_t lower = a[d][q] << (63 - r);
      if (lower) {
        x -= __builtin_clzll(lower);
        for (int e = d - 1; e >= 0; --e) x = x << 6 | (63 - __builtin_clzll(a[e][x]));
        return x;
      }
      x = q - 1;
    }
    return -1;
  }
};


#ifdef LOCAL
constexpr int BUCKET = 3;
#else
constexpr int BUCKET = 183;
#endif

constexpr int INF = 1001001001;

int N;
vector<int> A;
int M;
vector<int> L, R;

int main() {
  for (; ~scanf("%d", &N); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    L.resize(M);
    R.resize(M);
    for (int j = 0; j < M; ++j) {
      scanf("%d%d", &L[j], &R[j]);
      --L[j];
    }
    
    vector<pair<int, int>> ps(N);
    for (int i = 0; i < N; ++i) {
      ps[i] = {A[i], i};
    }
    sort(ps.begin(), ps.end());
    vector<int> poss(N);
    for (int i = 0; i < N; ++i) {
      poss[ps[i].second] = i;
    }
    
    vector<int> ans(M);
    
    const int numBuckets = (N + BUCKET - 1) / BUCKET;
    vector<vector<int>> queriess(numBuckets);
    for (int j = 0; j < M; ++j) {
      queriess[L[j] / BUCKET].push_back(j);
    }
    for (int k = 0; k < numBuckets; ++k) {
      auto &queries = queriess[k];
      sort(queries.begin(), queries.end(), [](const int j0, const int j1) {
        return (R[j0] < R[j1]);
      });
      Set<5> ss(N);
      int cost = INF;
      auto add = [&](int i) {
        const int nx = ss.next(poss[i]);
        if (nx < N) {
          chmin(cost, ps[nx].first - A[i]);
        }
        const int pr = ss.prev(poss[i]);
        if (pr >= 0) {
          chmin(cost, A[i] - ps[pr].first);
        }
        ss.insert(poss[i]);
      };
      const int lim = (k + 1) * BUCKET;
      int r = lim;
      for (const int j : queries) {
        for (; r < R[j]; add(r++)) {}
        const int save = cost;
        for (int i = L[j]; i < R[j] && i < lim; ++i) {
          add(i);
        }
        ans[j] = cost;
        for (int i = L[j]; i < R[j] && i < lim; ++i) {
          ss.erase(poss[i]);
        }
        cost = save;
      }
    }
    
    for (int j = 0; j < M; ++j) {
      printf("%d\n", ans[j]);
    }
  }
  return 0;
}