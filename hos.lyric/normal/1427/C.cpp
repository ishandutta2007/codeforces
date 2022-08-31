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

constexpr int MAX_N = 100'010;
constexpr int INF = 1'000'000'000;

int R, N;
int T[MAX_N], X[MAX_N], Y[MAX_N];

int dp[MAX_N];

int main() {
  for (; ~scanf("%d%d", &R, &N); ) {
    for (int i = 1; i <= N; ++i) {
      scanf("%d%d%d", &T[i], &X[i], &Y[i]);
    }
    T[0] = 0;
    X[0] = 1;
    Y[0] = 1;
    
    fill(dp, dp + N + 1, -INF);
    dp[0] = 0;
    int mx = -INF;
    for (int i = 1; i <= N; ++i) {
      chmax(dp[i], mx + 1);
      for (int j = max(i - R - R, 0); j < i; ++j) {
        if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T[i] - T[j]) {
          chmax(dp[i], dp[j] + 1);
        }
      }
      if (i - R - R >= 0) {
        chmax(mx, dp[i - R - R]);
      }
    }
    
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
      chmax(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}