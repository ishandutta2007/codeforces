#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
const int M = N * 64;
int la, id, lnk[N], len[N], edp[N], ch[N][26], w[N];
vector<int> G[N];
void init() { lnk[0] = -1; id = la = 0; fill(ch[0], ch[0] + 26, -1); }
void extend(int c) {
  int u = ++ id, p = la;
  fill(ch[u], ch[u] + 26, -1); len[u] = len[la] + 1;
  for(; ~ p && ch[p][c] == -1; p = lnk[p]) ch[p][c] = u;
  if(p == -1) lnk[u] = 0;
  else {
    int q = ch[p][c];
    if(len[q] == len[p] + 1) lnk[u] = q;
    else {
      int q0 = ++ id;
      copy(ch[q], ch[q] + 26, ch[q0]);
      len[q0] = len[p] + 1; lnk[q0] = lnk[q];
      lnk[u] = lnk[q] = q0;
      for(; ~ p && ch[p][c] == q; p = lnk[p])
        ch[p][c] = q0;
    }
  }
  la = u; w[u] = 1; edp[u] = len[u];
}
int rt[N], ls[M], rs[M], sz[M], seg_id;
void insert(int &u, int l, int r, int x) {
  u = ++ seg_id; sz[u] = 1;
  if(l == r) return ;
  int mid = (l + r) >> 1;
  if(x <= mid) insert(ls[u], l, mid, x);
  else insert(rs[u], mid + 1, r, x);
}
bool query(int u, int l, int r, int ql, int qr) {
  if(l == ql && r == qr) return sz[u] >= 1;
  int mid = (l + r) >> 1;
  if(qr <= mid) return query(ls[u], l, mid, ql, qr);
  if(ql > mid) return query(rs[u], mid + 1, r, ql, qr);
  return query(ls[u], l, mid, ql, mid) || query(rs[u], mid + 1, r, mid + 1, qr);
}
int smerge(int u, int v) {
  if(!u && !v) return 0;
  int x = ++ seg_id;
  if(!u || !v) {
    u |= v; sz[x] = sz[u]; ls[x] = ls[u]; rs[x] = rs[u];
    return x;
  }
  sz[x] = sz[u] + sz[v];
  ls[x] = smerge(ls[u], ls[v]);
  rs[x] = smerge(rs[u], rs[v]);
  return x;
}
char s[N];
int n;
void dfs(int u) {
  if(w[u]) insert(rt[u], 1, n, edp[u]);
  for(int v : G[u]) {
    dfs(v);
    rt[u] = smerge(rt[u], rt[v]);
  }
}
bool pd(int u, int len, int l, int r) {
  if(r - l + 1 < len) return 0;
  return query(rt[u], 1, n, l + len - 1, r);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  init();
  rep(i, 1, n) extend(s[i] - 'a');
  rep(i, 1, id) G[lnk[i]].pb(i);
  dfs(0);
  int q; scanf("%d", &q);
  while(q --) {
    static char t[N];
    static int pos[N];
    int l, r;
    scanf("%d%d%s", &l, &r, t + 1);
    int m = strlen(t + 1), u = 0, k; pos[0] = 0;
    for(k = 1; k <= m; k ++) {
      if(!~ch[u][t[k] - 'a']) break ;
      pos[k] = u = ch[u][t[k] - 'a'];
    }
    k --;
    bool ok = 0;
    for(; k >= 0 && !ok; k --) {
      for(int c = t[k + 1] ? t[k + 1] - 'a' + 1 : 0; c < 26; c ++) {
        if(~ch[pos[k]][c] && pd(ch[pos[k]][c], k + 1, l, r)) {
          t[k + 1] = 'a' + c; t[k + 2] = 0; puts(t + 1); ok = 1;
          break ;
        }
      }
    }
    if(!ok) puts("-1");
  }
  return 0;
}