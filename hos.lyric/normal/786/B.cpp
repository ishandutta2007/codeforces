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

constexpr Int INF = 1'000'000'000'000'000'000LL;

int N, Q, S;
vector<int> T, V, U, L, R;
vector<Int> W;

int main() {
  for (; ~scanf("%d%d%d", &N, &Q, &S); ) {
    --S;
    T.resize(Q);
    V.resize(Q);
    U.resize(Q);
    L.resize(Q);
    R.resize(Q);
    W.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d", &T[q]);
      if (T[q] == 1) {
        scanf("%d%d%lld", &V[q], &U[q], &W[q]);
        --V[q];
        --U[q];
      } else {
        scanf("%d%d%d%lld", &V[q], &L[q], &R[q], &W[q]);
        --V[q];
        --L[q];
      }
    }
    
    int segN;
    for (segN = 1; segN < N; segN <<= 1) {}
    
    vector<vector<pair<Int, int>>> graph(segN * 3);
    auto ae = [&](int u, int v, Int c) {
      if (u >= segN * 3) u -= segN * 2;
      if (v >= segN * 3) v -= segN * 2;
// cerr<<"ae "<<u<<" "<<v<<" "<<c<<endl;
      graph[u].emplace_back(c, v);
    };
    
    for (int a = 1; a < segN; ++a) {
      ae(a, a << 1, 0);
      ae(a, a << 1 | 1, 0);
      ae(segN * 2 + (a << 1), segN * 2 + a, 0);
      ae(segN * 2 + (a << 1 | 1), segN * 2 + a, 0);
    }
    for (int q = 0; q < Q; ++q) {
      switch (T[q]) {
        case 1: {
          ae(segN + V[q], segN + U[q], W[q]);
        } break;
        case 2: {
          for (int a = L[q] + segN, b = R[q] + segN; a < b; a >>= 1, b >>= 1) {
            if (a & 1) ae(segN + V[q], a++, W[q]);
            if (b & 1) ae(segN + V[q], --b, W[q]);
          }
        } break;
        case 3: {
          for (int a = L[q] + segN, b = R[q] + segN; a < b; a >>= 1, b >>= 1) {
            if (a & 1) ae(segN * 2 + a++, segN + V[q], W[q]);
            if (b & 1) ae(segN * 2 + --b, segN + V[q], W[q]);
          }
        } break;
        default: assert(false);
      }
    }
    
    using Node = pair<Int, int>;
    priority_queue<Node, vector<Node>, greater<Node>> que;
    vector<Int> dist(segN * 3, INF);
    dist[segN + S] = 0;
    que.emplace(0, segN + S);
    for (; !que.empty(); ) {
      const Int c = que.top().first;
      const int a = que.top().second;
      que.pop();
      if (dist[a] == c) {
        for (const auto &edge : graph[a]) {
          const Int cc = c + edge.first;
          const int b = edge.second;
          if (chmin(dist[b], cc)) {
            que.emplace(cc, b);
          }
        }
      }
    }
    
    for (int u = 0; u < N; ++u) {
      if (u > 0) printf(" ");
      printf("%lld", (dist[segN + u] >= INF) ? -1 : dist[segN + u]);
    }
    puts("");
  }
  return 0;
}