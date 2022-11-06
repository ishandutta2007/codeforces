#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5, inf = 0x3f3f3f3f;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
typedef pair <int, int> pii;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int N = 1e5 + 5;
int n, m;
int sz[N], hson[N], dep[N], top[N], fa[N], in[N], out[N], pred[N], tot = 0;
vector <int> e[N];
void dfs1(int p) {
  sz[p] = 1;
  hson[p] = 0;
  for (ri i = 0, v; i < e[p].size(); ++i) {
    dep[v = e[p][i]] = dep[p] + 1;
    dfs1(v);
    sz[p] += sz[v];
    if (sz[v] > sz[hson[p]]) {
      hson[p] = v;
    }
  }
}
void dfs2(int p, int tp) {
  top[p] = tp;
  pred[in[p] = ++tot] = p;
  if (hson[p]) {
    dfs2(hson[p], tp);
  }
  for (ri i = 0, v; i < e[p].size(); ++i) {
    v = e[p][i];
    if (v != hson[p]) {
      dfs2(v, v);
    }
  }
  out[p] = tot;
}
namespace sgt {
  #define lc (p << 1)
  #define rc (p << 1 | 1)
  #define mid ((l + r) >> 1)
  #define qll lc, l, mid
  #define qrr rc, mid + 1, r
  int mx[N << 2], ad[N << 2], cov[N << 2], mxd[N << 2];
  int ql, qr;
  inline void pushadd(int p, int v) {
    mx[p] += v;
    ad[p] += v;
  }
  inline void pushcov(int p, int v) {
    ad[p] = 0;
    cov[p] = v;
    mx[p] = mxd[p] + v;
  }
  inline void pushdown(int p) {
    if (cov[p] != inf) {
      pushcov(lc, cov[p]);
      pushcov(rc, cov[p]);
      cov[p] = inf;
    }
    if (ad[p]) {
      pushadd(lc, ad[p]);
      pushadd(rc, ad[p]);
      ad[p] = 0;
    }
  }
  inline void pushup(int p) {
    mx[p] = max(mx[lc], mx[rc]);
  }
  inline void updadd(int p, int l, int r, int v) {
    if (ql <= l && r <= qr) {
      pushadd(p, v);
      return;
    }
    pushdown(p);
    if (qr <= mid) {
      updadd(qll, v);
    } else if (ql > mid) {
      updadd(qrr, v);
    } else {
      updadd(qll, v);
      updadd(qrr, v);
    }
    pushup(p);
  }
  inline void updcov(int p, int l, int r, int v) {
    if (ql <= l && r <= qr) {
      pushcov(p, v);
      return;
    }
    pushdown(p);
    if (qr <= mid) {
      updcov(qll, v);
    } else if (ql > mid) {
      updcov(qrr, v);
    } else {
      updcov(qll, v);
      updcov(qrr, v);
    }
    pushup(p);
  }
  inline void build(int p, int l, int r) {
    if (l == r) {
      mx[p] = dep[pred[l]];
      mxd[p] = mx[p];
      return;
    }
    build(qll);
    build(qrr);
    pushup(p);
    mxd[p] = max(mxd[lc], mxd[rc]);
  }
  inline int qry(int p, int l, int r) {
    if (ql <= l && r <= qr) {
      return mx[p];
    }
    pushdown(p);
    if (qr <= mid) {
      return qry(qll);
    }
    if (ql > mid) {
      return qry(qrr);
    }
    return max(qry(qll), qry(qrr));
  }
  inline void updadd(int l, int r, int v) {
    ql = l;
    qr = r;
    updadd(1, 1, n, v);
  }
  inline void updcov(int l, int r, int v) {
    ql = l;
    qr = r;
    updcov(1, 1, n, v);
  }
  inline int qry(int l, int r) {
    ql = l;
    qr = r;
    return qry(1, 1, n);
  }
  #undef lc
  #undef rc
  #undef mid
  #undef qll
  #undef qrr
}  //using namespace sgt;
inline int qry(int p) {
  int res = -1;
  while (p) {
    res = max(res, sgt:: qry(in[top[p]], in[p]));
    p = fa[top[p]];
  }
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  m = read();
  for (ri i = 2; i <= n; ++i) {
    fa[i] = read();
    e[fa[i]].pb(i);
  }
  dfs1(1), dfs2(1, 1);
  sgt:: build(1, 1, n);
  for (ri op, x; m; --m) {
    op = read();
    x = read();
    if (op == 1) {
      sgt:: updadd(in[x], out[x], -1);
    } else if (op == 2) {
      sgt:: updcov(in[x], out[x], -(dep[x] - qry(fa[x]) - 1));
    }
    else {
      puts(qry(fa[x]) >= sgt:: qry(in[x], in[x]) ? "black" : "white");
    }
  }
  return 0;
}