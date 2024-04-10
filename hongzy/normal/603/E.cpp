#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef pair<int, int> pii;
const int N = 4e5 + 10, INF = 2e9 + 10;
priority_queue<pii> pq;
int n, m, cnt, u[N], v[N], w[N], l[N], mp[N], ch[N][2], fa[N], sz[N], siz[N];
bool rev[N], del[N];
#define ls ch[u][0]
#define rs ch[u][1]
//n + m&<=n
int dir(int u) { return ch[fa[u]][0] == u ? 0 : (ch[fa[u]][1] == u ? 1 : -1); }
int maxe(int u, int v) { return l[u] < l[v] ? v : u; } //[n+1,n+m]
void upd(int u) {
   mp[u] = maxe(u, maxe(mp[ls], mp[rs]));
   sz[u] = sz[ls] + sz[rs] + siz[u] + (u <= n);
}
void rot(int u) {
   int f = fa[u], d = dir(u);
   if(fa[u] = fa[f], ~ dir(f)) ch[fa[u]][dir(f)] = u;
   if(ch[f][d] = ch[u][d ^ 1]) fa[ch[f][d]] = f;
   fa[ch[u][d ^ 1] = f] = u; upd(f); upd(u);
}
void pd(int u) {
   if(rev[u]) { swap(ls, rs); rev[ls] ^= 1; rev[rs] ^= 1; rev[u] = 0; }
}
int st[N];
void sp(int u) {
   int v, t = 0;
   for(v = u; ~ dir(v); v = fa[v]) st[t ++] = v;
   pd(v);
   while(t --) pd(st[t]);
   for(; ~ dir(u); rot(u)) if(~ dir(fa[u]))
      rot(dir(u) == dir(fa[u]) ? fa[u] : u);
}
void acc(int u) {
   for(int v = 0; u; v = u, u = fa[u]) {
      sp(u); siz[u] += sz[rs] - sz[v]; rs = v; upd(u);
   }
}
void mkr(int u) {
   acc(u); sp(u); rev[u] ^= 1;
}
void spi(int u, int v) {
   mkr(u); acc(v); sp(v);
}
void lnk(int u, int v) {
   spi(u, v);
   cnt -= sz[u] & 1; cnt -= sz[v] & 1;
   //assert(fa[u] == 0);
   fa[u] = v; siz[v] += sz[u]; upd(v);
   cnt += sz[v] & 1;
}
void cut(int u, int v) {
   spi(u, v);
   cnt -= sz[v] & 1;
   //assert(ch[v][0] == u);
   ch[v][0] = fa[u] = 0;
   upd(v);
   cnt += sz[v] & 1; cnt += sz[u] & 1;
}
int add(int id, int u, int v, int w) {
   l[n + id] = w;
   spi(u, v);
   if(fa[u]) {
      if(::w[mp[v] - n] > w) {
         int x = mp[v] - n;
         cut(::u[x], n + x); cut(::v[x], n + x); del[x] = 1;
         lnk(u, n + id); lnk(v, n + id); pq.push(pii(w, id));
      }
   } else {
      lnk(u, n + id); lnk(v, n + id); pq.push(pii(w, id));
   }
   if(cnt) return -1;
   while(pq.size()) {
      //puts("!");
      pii tp = pq.top(); pq.pop(); int x = tp.second;
      if(del[x]) continue ;
      cut(::u[x], n + x); cut(::v[x], n + x);
      if(cnt) {
         lnk(::u[x], n + x); lnk(::v[x], n + x);
         pq.push(tp);
         return ::w[x];
      }
   }
   return 0;
}
int main() {
   scanf("%d%d", &n, &m);
   if(n & 1) {
      rep(i, 1, m) puts("-1");
      return 0;
   }
   cnt = n;
   rep(i, 1, n) sz[i] = 1;
   rep(i, 1, m) {
      scanf("%d%d%d", u + i, v + i, w + i);
      printf("%d\n", add(i, u[i], v[i], w[i]));
   }
   return 0;
}