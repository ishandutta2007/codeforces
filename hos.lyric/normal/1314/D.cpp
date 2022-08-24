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

constexpr int INF = 1001001001;

int N, K;
int A[110][110];

pair<int, int> costs[110][110][10];
int us[10];
bool has[110];

int main() {
  for (; ~scanf("%d%d", &N, &K); ) {
    for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
      scanf("%d", &A[u][v]);
    }
    K /= 2;
    
    for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
      fill(costs[u][v], costs[u][v] + K + 1, make_pair(INF, -1));
      for (int w = 0; w < N; ++w) {
        if (u != w && w != v) {
          pair<int, int> tmp = {A[u][w] + A[w][v], w};
          for (int k = 0; k < K + 1; ++k) {
            if (costs[u][v][k] > tmp) {
              swap(costs[u][v][k], tmp);
            }
          }
        }
      }
    }
    int nk = 1;
    for (int i = 1; i < K; ++i) {
      nk *= N;
    }
    int ans = INF;
    for (int p = 0; p < nk; ++p) {
      us[0] = us[K] = 0;
      int pp = p;
      for (int i = 1; i < K; ++i) {
        us[i] = pp % N;
        pp /= N;
      }
// cerr<<"us = ";pv(us,us+K+1);
      int best = 0;
      for (int i = 0; i < K; ++i) {
        chmin(best += costs[us[i]][us[i + 1]][0].first, INF);
      }
      if (ans <= best) {
        continue;
      }
      for (int i = 0; i < K; ++i) {
        has[us[i]] = true;
      }
      int cost = 0;
      for (int i = 0; i < K; ++i) {
        bool found = false;
        auto cs = costs[us[i]][us[i + 1]];
        for (int k = 0; k < K + 1 && cs[k].second != -1; ++k) {
          if (!has[cs[k].second]) {
            found = true;
            cost += cs[k].first;
            break;
          }
        }
        if (!found) {
          goto failed;
        }
      }
      chmin(ans, cost);
     failed:{}
      for (int i = 0; i < K; ++i) {
        has[us[i]] = false;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}