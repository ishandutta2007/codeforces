#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}

template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 55, INF = 1e9 + 10;
struct Edge { int v, w; };
vector<Edge> G[N];
int n, m, s, sz[N], f[N][N][N][N], deg[N], a[N][N];
void dfs(int u, int fa = 0) {
   for(auto e : G[u]) if(e.v ^ fa)
      dfs(e.v, u), sz[u] += sz[e.v];
}
int F(int u, int v, int s1, int s2) {
   if(s1 + s2 == 0) return 0;
   int &val = f[u][v][s1][s2];
   if(~ val) return val;
   if(deg[v] == 1) return val = s2 ? a[u][v] + F(v, u, s2, 0) : 0;
   int g[N]; g[0] = INF; fill(g + 1, g + s1 + 1, -INF);
   for(auto e : G[v]) if(e.v ^ u) {
      per(i, s1, 0) per(j, s1 - i, 1) {
         chkmax(g[i + j], min(g[i], e.w + F(v, e.v, j, s1 + s2 - j)));
      }
   }
   return val = g[s1];
}
int main() {
   scanf("%d", &n);
   int u, v, w;
   rep(i, 1, n - 1) {
      scanf("%d%d%d", &u, &v, &w);
      G[u].pb({v, w}); G[v].pb({u, w});
      a[u][v] = a[v][u] = w; deg[u] ++; deg[v] ++;
   }
   scanf("%d%d", &s, &m);
   rep(i, 1, m) scanf("%d", &u), sz[u] ++;
   dfs(s); memset(f, -1, sizeof f); int res = INF;
   for(auto e : G[s]) {
      res = min(res, e.w + F(s, e.v, sz[e.v], m - sz[e.v]));
   }
   printf("%d\n", res);
   return 0;
}