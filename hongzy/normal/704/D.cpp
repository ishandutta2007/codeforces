#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <queue>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;

const int N = 2e5 + 20;
const int M = N * 8 + 20;
const int INF = 2147483647;

struct Network {

struct Edge {
   int v, c, f, nxt;
} e[M];
int ec, hd[N], n, s, t, real_s, real_t;
void init() { fill(hd + 1, hd + n + 1, -1); ec = 0; }
void add(int u, int v, int c) {
   e[ec] = (Edge) {v, c, 0, hd[u]}; hd[u] = ec ++;
   e[ec] = (Edge) {u, 0, 0, hd[v]}; hd[v] = ec ++;
}
int dis[N], cur[N];
bool bfs() {
   fill(dis + 1, dis + n + 1, -1);
   queue<int> q; q.push(real_s); dis[real_s] = 0;
   while(q.size()) {
      int u = q.front(); q.pop();
      for(int i = hd[u]; ~ i; i = e[i].nxt) {
         int v = e[i].v;
         if(e[i].f < e[i].c && -1 == dis[v]) {
            dis[v] = dis[u] + 1; q.push(v);
         }
      }
   }
   return ~ dis[real_t];
}
int dfs(int u, int a) {
   if(u == real_t || a == 0) return a;
   int ans = 0, f;
   for(int &i = cur[u]; ~ i; i = e[i].nxt) {
      int v = e[i].v;
      if(dis[v] == dis[u] + 1 && (f = dfs(v, min(a, e[i].c - e[i].f))) > 0) {
         ans += f; e[i].f += f; e[i ^ 1].f -= f;
         if((a -= f) == 0) break ;
      }
   }
   return ans;
}
int dinic(int s, int t) {
   real_s = s; real_t = t; int ans = 0;
   while(bfs()) {
      copy(hd + 1, hd + n + 1, cur + 1);
      ans += dfs(real_s, INF);
   }
   return ans;
}

} net;

struct node { int x, y; } a[N];
int n, m, r, b, numx[N], numy[N], lx, ly, limx[N], limy[N], cntx[N], cnty[N];
void nores() { puts("-1"); exit(0); }
int main() {
   scanf("%d%d%d%d", &n, &m, &r, &b);
   rep(i, 1, n) { scanf("%d%d", &a[i].x, &a[i].y); numx[i] = a[i].x; numy[i] = a[i].y; }
   sort(numx + 1, numx + n + 1); lx = unique(numx + 1, numx + n + 1) - numx - 1;
   sort(numy + 1, numy + n + 1); ly = unique(numy + 1, numy + n + 1) - numy - 1;
   rep(i, 1, n) {
      a[i].x = lower_bound(numx + 1, numx + lx + 1, a[i].x) - numx;
      a[i].y = lower_bound(numy + 1, numy + ly + 1, a[i].y) - numy;
      cntx[a[i].x] ++; cnty[a[i].y] ++;
   }
   rep(i, 1, lx) limx[i] = INF;
   rep(i, 1, ly) limy[i] = INF;
   int op, x, d;
   rep(i, 1, m) {
      scanf("%d%d%d", &op, &x, &d);
      if(op == 1) {
         int z = lower_bound(numx + 1, numx + lx + 1, x) - numx;
         if(z <= lx && numx[z] == x)
            limx[z] = min(limx[z], d);
      } else if(op == 2) {
         int z = lower_bound(numy + 1, numy + ly + 1, x) - numy;
         if(z <= ly && numy[z] == x)
            limy[z] = min(limy[z], d);
      }
   }
   static ll val[N];
   int s = lx + ly + 1, t = s + 1, ss = t + 1, tt = ss + 1;
   net.n = tt; net.init();
   rep(i, 1, n) net.add(a[i].x, lx + a[i].y, 1);
   rep(i, 1, lx) {
      if(limx[i] == INF) {
         net.add(s, i, INF);
      } else {
         int L = max(0, (cntx[i] - limx[i] + 1) / 2), R = min(cntx[i], (cntx[i] + limx[i]) / 2);
         if(L > R) nores();
         net.add(s, i, R - L); val[s] -= L; val[i] += L;
      }
   }
   rep(i, 1, ly) {
      if(limy[i] == INF) {
         net.add(lx + i, t, INF);
      } else {
         int L = max(0, (cnty[i] - limy[i] + 1) / 2), R = min(cnty[i], (cnty[i] + limy[i]) / 2);
         if(L > R) nores();
         net.add(lx + i, t, R - L); val[lx + i] -= L; val[t] += L;
      }
   }
   ll flow = 0;
   rep(i, 1, lx + ly + 2) {
      if(val[i] > 0) net.add(ss, i, val[i]), flow += val[i];
      if(val[i] < 0) net.add(i, tt, - val[i]);
   }
   net.add(t, s, INF);
   if(flow != net.dinic(ss, tt)) nores();
   ll c = net.dinic(s, t);
   // printf("c = %d\n", c);
   printf("%lld\n", c * min(r, b) + (n - c) * max(r, b));
   rep(i, 0, n - 1) putchar(((r <= b) ^ net.e[i << 1].f) ? 'b' : 'r');
   putchar('\n');
   return 0;
}