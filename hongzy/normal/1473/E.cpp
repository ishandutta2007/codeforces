#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const ll INF = 1e16;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
struct Edge { int v, w; };
struct Graph {
   vector<Edge> G[N];
   void add(int u, int v, int w) {
      G[u].pb({v, w});
   }
   struct Node {
      int u; ll d;
      bool operator < (const Node &b) const {
         return d > b.d;
      }
   };
   ll dis[N];
   void Dijkstra(int s, int n) {
      fill(dis + 1, dis + n + 1, INF);
      priority_queue<Node> pq; pq.push({s, dis[s] = 0});
      while(pq.size()) {
         int u = pq.top().u; ll d = pq.top().d; pq.pop();
         if(dis[u] < d) continue ;
         for(auto e : G[u]) if(dis[e.v] > d + e.w) {
            dis[e.v] = d + e.w; pq.push({e.v, dis[e.v]});
         }
      }
   }
} G;
int n, m;
int id[N / 4][2][2], ID;
void add(int u, int v, int w) {
   G.add(id[u][0][0], id[v][0][0], w);
   G.add(id[u][0][1], id[v][0][1], w);
   G.add(id[u][1][0], id[v][1][0], w);
   G.add(id[u][1][1], id[v][1][1], w);

   G.add(id[u][0][0], id[v][1][0], 0); //free
   G.add(id[u][0][1], id[v][1][1], 0);

   G.add(id[u][0][0], id[v][0][1], 2 * w); //change
   G.add(id[u][1][0], id[v][1][1], 2 * w);

   G.add(id[u][0][0], id[v][1][1], w); //change & free
}
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) rep(j, 0, 1) rep(k, 0, 1) id[i][j][k] = ++ ID;
   rep(i, 1, m) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w); add(v, u, w);
   }
   G.Dijkstra(id[1][0][0], ID);
   rep(i, 2, n) printf("%lld ", G.dis[ id[i][1][1] ]);
   return 0;
}