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
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


constexpr Int MO = 998244353;
constexpr Int BIG = 1'000'000 * MO;
inline Int mod(Int x) {
  return (x >= BIG) ? (BIG + (x - BIG) % MO) : x;
}

int N, M;
vector<Int> C;
vector<int> A, B;

vector<vector<int>> graph;
vector<int> vis;
vector<int> us;
vector<pair<Int, Int>> dp[1010];

void dfs(int u) {
  if (vis[u]) {
    return ;
  }
  vis[u] = 1;
  for (const int v : graph[u]) {
    dfs(v);
  }
  us.push_back(u);
}

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d%d", &N, &M);
    C.resize(N);
    for (int u = 0; u < N; ++u) {
      scanf("%lld", &C[u]);
    }
    A.resize(M);
    B.resize(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    
    graph.assign(N, {});
    for (int i = 0; i < M; ++i) {
      graph[B[i]].push_back(A[i]);
    }
    vis.assign(N, 0);
    us.clear();
    for (int u = 0; u < N; ++u) {
      dfs(u);
    }
// cerr<<"us = "<<us<<endl;
    
    for (const int u : us) {
      vector<pair<Int, Int>> ps;
      if (C[u] > 0) {
        ps.emplace_back(0, C[u]);
      }
      for (const int v : graph[u]) {
        for (const auto &p : dp[v]) {
          ps.emplace_back(p.first + 1, p.second);
        }
      }
      sort(ps.begin(), ps.end());
      dp[u].clear();
      for (const auto &p : ps) {
        if (!dp[u].empty() && dp[u].back().first + dp[u].back().second >= p.first) {
          dp[u].back().second = mod(dp[u].back().second + p.second);
        } else {
          dp[u].push_back(p);
        }
      }
// cerr<<"dp["<<u<<"] = "<<dp[u]<<endl;
    }
    
    Int ans = 0;
    if (!dp[us.back()].empty()) {
      const auto &p0 = dp[us.back()].back();
      ans = p0.first + p0.second;
    }
    ans %= MO;
    printf("%lld\n", ans);
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}