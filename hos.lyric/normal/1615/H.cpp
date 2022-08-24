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


namespace MCF {

using Capa = Int;
using Cost = Int;
constexpr int MAX_N = 2'010;
constexpr int MAX_M = 1'002'010;
constexpr int QUE_SIZE = 1 << (32 - __builtin_clz(MAX_N));
constexpr int BELLMAN_FORD_NUM_ITERS = 10;
constexpr int LOG_SCALING = 2;

int n, m, ptr[MAX_N], cur[MAX_N], next[MAX_M << 1], zu[MAX_M << 1];
bool on[MAX_N];
int que[QUE_SIZE], qb, qe;
Capa capa[MAX_M << 1], ex[MAX_N];
Cost cost[MAX_M << 1], pot[MAX_N], pot0[MAX_N];

void init(int n_) {
  n = n_; m = 0; memset(ptr, ~0, n * sizeof(int)); memset(ex, 0, n * sizeof(Capa));
}
void ae(int u, int v, Capa c, Cost d) {
  d *= (n + 1);
  next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = c; cost[m] = d; ++m;
  next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -d; ++m;
}

bool bellmanFord(Cost eps) {
  memcpy(pot0, pot, n * sizeof(Cost));
  for (int iter = 0; iter < BELLMAN_FORD_NUM_ITERS; ++iter) {
    bool upd = false;
    for (int i = 0; i < m; ++i) {
      if (capa[i] > 0) {
        const int u = zu[i ^ 1], v = zu[i];
        if (pot0[v] > pot0[u] + cost[i] + eps) {
          pot0[v] = pot0[u] + cost[i] + eps;
          upd = true;
        }
      }
    }
    if (!upd) {
      memcpy(pot, pot0, n * sizeof(Cost));
      return true;
    }
  }
  return false;
}

Cost solve() {
  Cost minCost = 0;
  for (int i = 0; i < m; i += 2) if (minCost > cost[i]) minCost = cost[i];
  Cost eps = 1;
  for (; eps < -minCost; eps <<= LOG_SCALING) {}
  memset(pot, 0, n * sizeof(Cost));
  for (; eps >>= LOG_SCALING; ) {
    if (bellmanFord(eps)) continue;
    for (int i = 0; i < m; i += 2) {
      const int u = zu[i ^ 1], v = zu[i];
      const Cost d = cost[i] + pot[u] - pot[v];
      if (capa[i] > 0 && d < 0) {
        Capa &c = capa[i]; ex[u] -= c; ex[v] += c; capa[i ^ 1] += c; c = 0;
      } else if (capa[i ^ 1] > 0 && -d < 0) {
        Capa &c = capa[i ^ 1]; ex[v] -= c; ex[u] += c; capa[i] += c; c = 0;
      }
    }
    memcpy(cur, ptr, n * sizeof(int));
    qb = qe = 0;
    for (int u = 0; u < n; ++u) if (ex[u] > 0) {
      que[qe] = u; ++qe &= QUE_SIZE - 1;
    }
    for (; qb != qe; ) {
      const int u = que[qb]; ++qb &= QUE_SIZE - 1;
      for (int &i = cur[u]; ~i; i = next[i]) {
        if (capa[i] > 0) {
          const int v = zu[i];
          if (cost[i] + pot[u] - pot[v] < 0) {
            const Capa c = min(ex[u], capa[i]);
            if (ex[v] <= 0 && ex[v] + c > 0) {
              que[qe] = v; ++qe &= QUE_SIZE - 1;
            }
            ex[u] -= c; ex[v] += c; capa[i] -= c; capa[i ^ 1] += c;
            if (ex[u] == 0) break;
          }
        }
      }
      if (ex[u] > 0) {
        bool relabeled = false;
        for (int i = ptr[u]; ~i; i = next[i]) {
          if (capa[i] > 0) {
            const Cost p = pot[zu[i]] - cost[i] - eps;
            if (!relabeled || pot[u] < p) {
              relabeled = true; pot[u] = p;
            }
          }
        }
        cur[u] = ptr[u]; que[qe] = u; ++qe &= QUE_SIZE - 1;
      }
    }
  }
  Cost totalCost = 0;
  for (int i = 0; i < m; i += 2) totalCost += cost[i] * capa[i ^ 1];
  return totalCost / (n + 1);
}

}  // namespace MCF


constexpr MCF::Capa CAPA_INF = 1001001001LL;
constexpr MCF::Cost COST_INF = 1001001001001001001LL;

int N, M;
vector<Int> A;
vector<int> U, V;

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    A.resize(N);
    for (int u = 0; u < N; ++u) {
      scanf("%lld", &A[u]);
    }
    U.resize(M);
    V.resize(M);
    for (int i = 0; i < M; ++i) {
      scanf("%d%d", &U[i], &V[i]);
      --U[i];
      --V[i];
    }
    
    MCF::init(N + 1);
    for (int u = 0; u < N; ++u) {
      MCF::ae(N, u, 1, A[u]);
      MCF::ae(u, N, 1, -A[u]);
    }
    for (int i = 0; i < M; ++i) {
      // p[u] <= p[v] + 0
      MCF::ae(V[i], U[i], CAPA_INF, 0);
    }
    const MCF::Cost res = MCF::solve();
cerr<<"res = "<<res<<endl;
    vector<Int> ans(N + 1, COST_INF);
    ans[N] = 0;
    for (int h = 0; h < N + 1; ++h) {
      for (int i = 0; i < MCF::m; ++i) if (MCF::capa[i] > 0) {
        const int u = MCF::zu[i ^ 1], v = MCF::zu[i];
        chmin(ans[v], ans[u] + MCF::cost[i] / (MCF::n + 1));
      }
    }
    
    for (int u = 0; u < N; ++u) {
      if (u > 0) printf(" ");
      printf("%lld", ans[u]);
    }
    puts("");
#ifdef LOCAL
Int sol=0;
for(int u=0;u<N;++u)sol+=abs(ans[u]-A[u]);
cerr<<"sol = "<<sol<<endl;
for(int i=0;i<M;++i)assert(ans[U[i]]<=ans[V[i]]);
#endif
  }
  return 0;
}