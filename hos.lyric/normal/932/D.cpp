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

#define ws ws__

constexpr Int INF = 1'000'000'000'000'000'000;
constexpr int LIM = 400000 + 10;
constexpr int E = 20;

int N;
int dep[LIM];
Int ws[LIM];
int par[E][LIM], to[E][LIM];
Int mx[E][LIM], sum[E][LIM];

int main() {
  int Q;
  for (; ~scanf("%d", &Q); ) {
cerr<<"case Q = "<<Q<<endl;
    N = 1;
    dep[0] = 0;
    ws[0] = 0;
    for (int e = 0; e < E; ++e) {
      par[e][0] = 0;
      mx[e][0] = -INF;
      to[e][0] = 0;
      sum[e][0] = INF;
    }
    
    Int last = 0;
    for (int i = 0; i < Q; ++i) {
      int typ;
      Int p, q;
      scanf("%d%lld%lld", &typ, &p, &q);
      p ^= last;
      q ^= last;
      --p;
// cerr<<"query "<<typ<<" "<<p<<" "<<q<<endl;
      switch (typ) {
        case 1: {
          const int u = N++;
          dep[u] = dep[p] + 1;
          ws[u] = q;
          par[0][u] = p;
          mx[0][u] = ws[p];
          for (int e = 0; e < E - 1; ++e) {
            par[e + 1][u] = par[e][par[e][u]];
            mx[e + 1][u] = max(mx[e][u], mx[e][par[e][u]]);
          }
          int &t = to[0][u] = u;
          for (int e = E - 1; e >= 0; --e) {
            if (ws[u] > mx[e][t]) {
              t = par[e][t];
            }
          }
          t = par[0][t];
// cerr<<"  to["<<u<<"] = "<<t<<endl;
          sum[0][u] = (ws[u] <= ws[t]) ? ws[t] : INF;
          for (int e = 0; e < E - 1; ++e) {
            to[e + 1][u] = to[e][to[e][u]];
            sum[e + 1][u] = min(sum[e][u] + sum[e][to[e][u]], INF);
          }
        } break;
        case 2: {
          int ans = 0;
          Int x = q;
          if (x >= ws[p]) {
            ans += 1;
            x -= ws[p];
            int u = p;
            for (int e = E - 1; e >= 0; --e) {
              if (x >= sum[e][u]) {
                ans += 1 << e;
                x -= sum[e][u];
                u = to[e][u];
              }
            }
          }
          printf("%d\n", ans);
          last = ans;
        } break;
        default: assert(false);
      }
    }
  }
  return 0;
}