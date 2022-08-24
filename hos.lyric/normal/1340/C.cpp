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

constexpr int MAX_M = 10010;
constexpr int MAX_G = 1010;
constexpr int INF = 1'000'000'000;
constexpr Int INFLL = 1'000'000'000'000'000'000LL;

int N, M;
int D[MAX_M];
int G, R;

bool vis[MAX_M * MAX_G];
int dist[MAX_M * MAX_G];

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    for (int i = 0; i < M; ++i) {
      scanf("%d", &D[i]);
    }
    scanf("%d%d", &G, &R);
    sort(D, D + M);
    assert(D[0] == 0);
    assert(D[M - 1] == N);
    
    deque<int> que;
    fill(vis, vis + M * (G + 1), false);
    fill(dist, dist + M * (G + 1), INF);
    dist[0] = 0;
    que.push_back(0);
    for (; !que.empty(); ) {
      const int u = que.front();
      que.pop_front();
      if (!vis[u]) {
        vis[u] = true;
        const int i = u / (G + 1);
        const int x = u % (G + 1);
        // -1
        if (0 <= i - 1) {
          const int xx = x + (D[i] - D[i - 1]);
          if (xx <= G) {
            const int v = (i - 1) * (G + 1) + xx;
            if (chmin(dist[v], dist[u])) {
              que.push_front(v);
            }
          }
        }
        // +1
        if (i + 1 < M) {
          const int xx = x + (D[i + 1] - D[i]);
          if (xx <= G) {
            const int v = (i + 1) * (G + 1) + xx;
            if (chmin(dist[v], dist[u])) {
              que.push_front(v);
            }
          }
        }
        // red signal
        if (x == G) {
          const int v = i * (G + 1) + 0;
          if (chmin(dist[v], dist[u] + 1)) {
            que.push_back(v);
          }
        }
      }
    }
    Int ans = INFLL;
    for (int x = 0; x <= G; ++x) {
      const int u = (M - 1) * (G + 1) + x;
      if (dist[u] < INF) {
        chmin(ans, (Int)(G + R) * dist[u] + x);
      }
    }
    printf("%lld\n", (ans >= INFLL) ? -1 : ans);
  }
  return 0;
}