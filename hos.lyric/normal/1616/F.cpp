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


pair<vector<int>, bool> solve(int n, vector<vector<int>> &a) {
  const int m = a.size();
  int r = 0;
  vector<int> hs;
  for (int h = 0; h < n; ++h) if (r < m) {
    for (int i = r; i < m; ++i) if (a[i][h]) {
      swap(a[r], a[i]);
      break;
    }
    if (a[r][h]) {
      if (a[r][h] == 2) {
        for (int j = h; j <= n; ++j) {
          a[r][j] = a[r][j] ? (3 - a[r][j]) : a[r][j];
        }
      }
      for (int i = r + 1; i < m; ++i) {
        if (a[i][h] == 1) {
          for (int j = h; j <= n; ++j) {
            if ((a[i][j] -= a[r][j]) < 0) {
              a[i][j] += 3;
            }
          }
        } else if (a[i][h] == 2) {
          for (int j = h; j <= n; ++j) {
            if ((a[i][j] += a[r][j]) >= 3) {
              a[i][j] -= 3;
            }
          }
        }
      }
      ++r;
      hs.push_back(h);
    }
  }
  for (int i = r; i < m; ++i) {
    if (a[i][n]) {
      return make_pair(vector<int>{}, false);
    }
  }
  vector<int> xs(n, 0);
  for (int i = r; --i >= 0; ) {
    const int h = hs[i];
    xs[h] = a[i][n];
    for (int j = h + 1; j < n; ++j) {
      xs[h] -= a[i][j] * xs[j];
    }
    if ((xs[h] %= 3) < 0) {
      xs[h] += 3;
    }
  }
  return make_pair(xs, true);
}

int N, M;
vector<int> A, B, C;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) {
    for (; numCases--; ) {
      scanf("%d%d", &N, &M);
      A.resize(M);
      B.resize(M);
      C.resize(M);
      for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        --A[i];
        --B[i];
        --C[i];
      }
// cerr<<"N = "<<N<<", M = "<<N<<endl;
// cerr<<"A = ";pv(A.begin(),A.end());
// cerr<<"B = ";pv(B.begin(),B.end());
// cerr<<"C = ";pv(C.begin(),C.end());
      
      vector<vector<int>> ids(N, vector<int>(N, -1));
      for (int i = 0; i < M; ++i) {
        ids[A[i]][B[i]] = i;
        ids[B[i]][A[i]] = i;
      }
// cerr<<"ids = "<<endl;for(int u=0;u<N;++u)pv(ids[u].begin(),ids[u].end());
      vector<vector<int>> a;
      for (int i = 0; i < M; ++i) if (C[i] >= 0) {
        a.emplace_back(M + 1, 0);
        a.back()[i] = 1;
        a.back()[M] = C[i];
      }
// cerr<<"waf"<<__LINE__<<endl;
      for (int u = 0; u < N; ++u) for (int v = u + 1; v < N; ++v) for (int w = v + 1; w < N; ++w) {
        if (~ids[u][v] && ~ids[u][w] && ~ids[v][w]) {
// cerr<<u<<" "<<v<<" "<<w<<"; "<<ids[u][v]<<" "<<ids[u][w]<<" "<<ids[v][w]<<endl;
          a.emplace_back(M + 1, 0);
          a.back()[ids[u][v]] = 1;
          a.back()[ids[u][w]] = 1;
          a.back()[ids[v][w]] = 1;
        }
      }
// cerr<<"a = "<<endl;for(const auto&row:a)pv(row.begin(),row.end());
      
      const auto res = solve(M, a);
      if (res.second) {
        for (int i = 0; i < M; ++i) {
          if (i) printf(" ");
          printf("%u", res.first[i] + 1);
        }
        puts("");
      } else {
        puts("-1");
      }
    }
#ifndef LOCAL
    break;
#endif
  }
  return 0;
}