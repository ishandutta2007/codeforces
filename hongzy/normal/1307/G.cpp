#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
typedef double db;
const int N = 52;
const int M = 2e6 + 10;
const int INF = 1 << 30;
struct Edge {
   int v, w, f, c, nxt;
} e[M];
int hd[N], ec, n, m, d[N], p[N];
void clr() { fill(hd + 1, hd + n + 1, -1); ec = 0; }
void add(int u, int v, int c, int w) {
   e[ec] = {v, w, 0, c, hd[u]}; hd[u] = ec ++;
   e[ec] = {u, -w, 0, 0, hd[v]}; hd[v] = ec ++;
}
int uni_flow() {
   static bool inq[N];
   fill(d + 1, d + n + 1, INF);
   queue<int> q; q.push(1); d[1] = 0; inq[1] = 1;
   while(q.size()) {
      int u = q.front(); q.pop(); inq[u] = 0;
      for(int i = hd[u]; ~ i; i = e[i].nxt) {
         auto e = ::e[i];
         if(e.f < e.c && d[e.v] > d[u] + e.w) {
            d[e.v] = d[u] + e.w; p[e.v] = i;
            if(!inq[e.v]) {
               inq[e.v] = 1; q.push(e.v);
            }
         }
      }
   }
   if(d[n] < INF) {
      for(int u = n; u > 1; u = e[p[u] ^ 1].v) {
         e[p[u]].f ++; e[p[u] ^ 1].f --;
      }
   }
   return d[n];
}
int main() {
   scanf("%d%d", &n, &m); clr();
   int u, v, w;
   rep(i, 1, m) {
      scanf("%d%d%d", &u, &v, &w); add(u, v, 1, w);
   }
   int f = 0;
   static int res[M];
   while(1) {
      int z = uni_flow();
      if(z == INF) break ;
      f ++; res[f] = res[f - 1] + z;
   }
   int q, x; scanf("%d", &q);
   while(q --) {
      scanf("%d", &x);
      db ans = INF;
      rep(i, 1, f) {
         ans = min(ans, (x + res[i]) * 1.0 / i);
      }
      printf("%.10lf\n", ans);
   }
   return 0;
}