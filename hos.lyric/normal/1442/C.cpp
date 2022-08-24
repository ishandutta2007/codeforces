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


constexpr int MO = 998244353;

constexpr int MAX = 200'010;

// 2^18 + 400000 < 2^20
constexpr int E = 20;

constexpr int INF = 1'000'000'000;


int N, M;
int A[MAX], B[MAX];

vector<int> G[2][MAX];

pair<int, int> dist[MAX][E];

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    
    for (int s = 0; s < 2; ++s) {
      fill(G[s], G[s] + N, vector<int>{});
    }
    for (int i = 0; i < M; ++i) {
      G[0][A[i]].push_back(i);
      G[1][B[i]].push_back(i);
    }
    
    using Node = pair<pair<int, int>, pair<int, int>>;
    priority_queue<Node, vector<Node>, greater<Node>> que;
    for (int u = 0; u < N; ++u) {
      fill(dist[u], dist[u] + E, make_pair(INF, INF));
    }
    dist[0][0] = make_pair(0, 0);
    que.emplace(make_pair(0, 0), make_pair(0, 0));
    for (; !que.empty(); ) {
      const auto c = que.top().first;
      const int u = que.top().second.first;
      const int e = que.top().second.second;
      que.pop();
      if (dist[u][e] == c) {
        // move
        for (const int i : G[e & 1][u]) {
          const int v = A[i] ^ B[i] ^ u;
          auto cc = c;
          ++cc.second;
          if (chmin(dist[v][e], cc)) {
            que.emplace(cc, make_pair(v, e));
          }
        }
        // transpose
        {
          int ee = e + 1;
          if (ee >= E) {
            ee -= 2;
          }
          auto cc = c;
          ++cc.first;
          if (chmin(dist[u][ee], cc)) {
            que.emplace(cc, make_pair(u, ee));
          }
        }
      }
    }
    
    auto mn = make_pair(INF, INF);
    for (int e = 0; e < E; ++e) {
      auto c = dist[N - 1][e];
      if (c.first < E) {
        c.second += (1 << c.first) - 1;
        c.first = 0;
      }
      chmin(mn, c);
    }
    assert(mn < make_pair(INF, INF));
    
    Int ans = 1;
    for (int _ = 0; _ < mn.first; ++_) {
      (ans *= 2) %= MO;
    }
    (ans += MO - 1) %= MO;
    (ans += mn.second) %= MO;
    printf("%lld\n", ans);
  }
  return 0;
}