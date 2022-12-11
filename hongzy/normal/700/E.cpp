#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4e5 + 10;
int n, nxt[N][26], lnk[N], len[N], pos[N], id, la;
char s[N], pf[N];
void init() { lnk[0] = -1; fill(nxt[0], nxt[0] + 26, -1); }
void extend(int c) {
   int u = ++ id, p = la; fill(nxt[u], nxt[u] + 26, -1); len[u] = len[la] + 1;
   for(; ~ p && -1 == nxt[p][c]; p = lnk[p]) nxt[p][c] = u;
   if(p == -1) lnk[u] = 0;
   else {
      int q = nxt[p][c];
      if(len[p] + 1 == len[q]) lnk[u] = q;
      else {
         int q0 = ++ id; copy(nxt[q], nxt[q] + 26, nxt[q0]); len[q0] = len[p] + 1; lnk[q0] = lnk[q];
         lnk[u] = lnk[q] = q0;
         for(; ~ p && nxt[p][c] == q; p = lnk[p]) nxt[p][c] = q0;
      }
   }
   la = u; pos[u] = len[u]; pf[u] = 1;
}
int rt[N], sz[N * 20], ls[N * 20], rs[N * 20], tr;
void insert(int &u, int l, int r, int x) {
   if(!u) u = ++ tr;
   sz[u] ++;
   if(l == r) return ;
   int mid = (l + r) >> 1;
   x <= mid ? insert(ls[u], l, mid, x) : insert(rs[u], mid + 1, r, x);
}
int merge(int u, int v) {
   if(!u || !v) return u | v;
   int x = ++ tr; sz[x] = sz[u] + sz[v];
   ls[x] = merge(ls[u], ls[v]);
   rs[x] = merge(rs[u], rs[v]);
   return x;
}
bool query(int u, int l, int r, int ql, int qr) {
   if(!u) return 0;
   if(l == ql && r == qr) return sz[u] >= 1;
   int mid = (l + r) >> 1;
   if(qr <= mid) return query(ls[u], l, mid, ql, qr);
   if(ql > mid) return query(rs[u], mid + 1, r, ql, qr);
   return query(ls[u], l, mid, ql, mid) || query(rs[u], mid + 1, r, mid + 1, qr);
}
int main() {
   scanf("%d%s", &n, s + 1); init();
   for(int i = 1; s[i]; i ++) extend(s[i] - 'a');
   static int cnt[N], ord[N];
   for(int i = 1; i <= id; i ++) cnt[len[i]] ++;
   for(int i = 1; i <= n; i ++) cnt[i] += cnt[i - 1];
   for(int i = 1; i <= id; i ++) ord[cnt[len[i]] --] = i;
   for(int i = id; i >= 1; i --) {
      int u = ord[i];
      if(!pos[lnk[u]]) pos[lnk[u]] = pos[u];
      if(pf[u]) {
         insert(rt[u], 1, n, pos[u]);
      }
      if(lnk[u]) {
         rt[lnk[u]] = merge(rt[u], rt[lnk[u]]);
      }
   }
   static int f[N], g[N];
   for(int i = 1; i <= id; i ++) {
      int u = ord[i];
      if(!lnk[u]) {
         g[u] = u; f[u] = 1;
      } else {
         int x = g[lnk[u]];
         if(query(rt[x], 1, n, pos[u] - len[u] + len[x], pos[u] - 1)) {
            g[u] = u; f[u] = f[lnk[u]] + 1;
         } else {
            g[u] = x; f[u] = f[lnk[u]];
         }
      }
   }
   printf("%d\n", *max_element(f + 1, f + id + 1));
   return 0;
}