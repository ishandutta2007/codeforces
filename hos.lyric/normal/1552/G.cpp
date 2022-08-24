#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

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

constexpr int MAX = 45;

int N, K;
int Q[MAX], J[MAX][MAX];

int k0s[MAX];
int as[MAX][MAX];

bool dfs(int k) {
  if (k == K) {
    for (int i = 0; i < N - 1; ++i) {
      if (as[K][i] > as[K][i + 1]) {
        return false;
      }
    }
    return true;
  } else {
    copy(as[k], as[k] + N, as[k + 1]);
    int cnt[3] = {};
    for (int q = 0; q < Q[k]; ++q) {
      ++cnt[as[k][J[k][q]]];
    }
// cerr<<"dfs "<<k<<"; cnt = ";pv(cnt,cnt+3);
    for (int q = 0; q < Q[k]; ++q) {
      as[k + 1][J[k][q]] = (q < cnt[0] + cnt[2]) ? 0 : 1;
    }
    for (int e = 0; ; ++e) {
      if (!dfs(k + 1)) {
        return false;
      }
      if (e == cnt[2]) {
        break;
      }
      as[k + 1][J[k][cnt[0] + cnt[2] - 1 - e]] = 1;
    }
  }
  return true;
}

int main() {
  for (; ~scanf("%d%d", &N, &K); ) {
    for (int k = 0; k < K; ++k) {
      scanf("%d", &Q[k]);
      for (int q = 0; q < Q[k]; ++q) {
        scanf("%d", &J[k][q]);
        --J[k][q];
      }
    }
    
    bool ans = false;
    if (N == 1) {
      ans = true;
    } else {
      fill(k0s, k0s + N, -1);
      for (int k = K; k--; ) {
        for (int q = 0; q < Q[k]; ++q) {
          k0s[J[k][q]] = k;
        }
      }
// cerr<<"k0s = ";pv(k0s,k0s+N);
      bool ok = true;
      for (int i = 0; i < N; ++i) {
        ok = ok && (k0s[i] != -1);
      }
      if (ok) {
        fill(as[0], as[0] + N, 2);
        ans = dfs(0);
      }
    }
    puts(ans ? "ACCEPTED" : "REJECTED");
  }
  return 0;
}