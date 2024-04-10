#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
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
typedef long long ll;
const int N = 150005;
int n, a[N], id[N];
ll ans[N];
template <typename T> inline void ckmax(T &a, T b) {
  a < b ? a = b : 0;
}
namespace sgt {
  #define lc (p << 1)
  #define rc (p << 1 | 1)
  #define mid ((l + r) >> 1)
  #define qll lc, l, mid
  #define qrr rc, mid + 1, r
  int ql, qr;
  int mx[N << 2], smx[N << 2], cmx[N << 2], sz[N << 2];
  ll tg[N << 2], mtg[N << 2], vl[N << 2];
  inline void pushup(int p) {
    vl[p] = vl[lc] + vl[rc];
    mx[p] = max(mx[lc], mx[rc]);
    cmx[p] = smx[p] = 0;
    if (mx[p] == mx[lc]) {
      cmx[p] += cmx[lc];
      ckmax(smx[p], smx[lc]);
    } else {
      ckmax(smx[p], mx[lc]);
    }
    if (mx[p] == mx[rc]) {
      cmx[p] += cmx[rc];
      ckmax(smx[p], smx[rc]);
    } else {
      ckmax(smx[p], mx[rc]);
    }
  }
  inline void pushadd(int p, int v) {
    vl[p] += (ll) v * sz[p];
    tg[p] += v;
    if (sz[p]) {
      mx[p] += v;
      if (sz[p] > cmx[p]) {
        smx[p] += v;
      }
    }
  }
  inline void pushmad(int p, int v) {
    vl[p] += (ll) v * cmx[p];
    mtg[p] += v;
    if (sz[p]) {
      mx[p] += v;
    }
  }
  inline void pushdown(int p) {
    if (tg[p]) {
      pushadd(lc, tg[p]);
      pushadd(rc, tg[p]);
      tg[p] = 0;
    }
    if (mtg[p]) {
      if (mx[lc] + mtg[p] == mx[p]) {
        pushmad(lc, mtg[p]);
      }
      if (mx[rc] + mtg[p] == mx[p]) {
        pushmad(rc, mtg[p]);
      }
      mtg[p] = 0;
    }
  }
  inline void build(int p, int l, int r) {
    mx[p] = smx[p] = 0;
    sz[p] = cmx[p] = 0;
    tg[p] = mtg[p] = 0;
    vl[p] = 0;
    if (l < r) {
      build(qll);
      build(qrr);
    }
  }
  inline void upd(int p, int l, int r, int v) {
    if (ql <= l && r <= qr) {
      pushadd(p, v);
      return;
    }
    pushdown(p);
    if (qr <= mid) {
      upd(qll, v);
    } else if (ql > mid) {
      upd(qrr, v);
    } else {
      upd(qll, v);
      upd(qrr, v);
    }
    pushup(p);
  }
  inline void upd(int p, int l, int r, int k, int v) {
    if (l == r) {
      sz[p] = cmx[p] = 1;
      vl[p] = mx[p] = v;
      return;
    }
    pushdown(p);
    k <= mid ? upd(qll, k, v) : upd(qrr, k, v);
    pushup(p);
    sz[p] = sz[lc] + sz[rc];
  }
  inline void ckm(int p, int l, int r, int v) {
    if (mx[p] <= v) {
      return;
    }
    if (ql <= l && r <= qr && smx[p] <= v) {
      pushmad(p, v - mx[p]);
      return;
    }
    pushdown(p);
    if (qr <= mid) {
      ckm(qll, v);
    } else if (ql > mid) {
      ckm(qrr, v);
    } else {
      ckm(qll, v);
      ckm(qrr, v);
    }
    pushup(p);
  }
  inline int qry(int p, int l, int r) {
    if (ql <= l && r <= qr) {
      return sz[p];
    }
    pushdown(p);
    if (qr <= mid) {
      return qry(qll);
    }
    if (ql > mid) {
      return qry(qrr);
    }
    return qry(qll) + qry(qrr);
  }
  inline void upd(int l, int r, int v) {
    if (l > r) {
      return;
    }
    ql = l;
    qr = r;
    upd(1, 1, n, v);
  }
  inline void upd(int k, int v) {
    return upd(1, 1, n, k, v);
  }
  inline void ckm(int l, int r, int v) {
    if (l > r) {
      return;
    }
    ql = l;
    qr = r;
    ckm(1, 1, n, v);
  }
  inline int qry(int l, int r) {
    if(l > r) {
      return 0;
    }
    ql = l;
    qr = r;
    return qry(1, 1, n);
  }
  #undef lc
  #undef rc
  #undef mid
  #undef qll
  #undef qrr
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (ri tt = 2; tt; --tt) {
    for (ri i = 1; i <= n; ++i) {
      id[a[i]] = i;
    }
    sgt:: build(1, 1, n);
    for (ri ps, i = 1; i <= n; ++i) {
      ps = sgt:: qry(1, id[i] - 1) + 1;
      sgt:: ckm(1, id[i] - 1, ps - 1);
      sgt:: upd(id[i], i);
      sgt:: upd(id[i] + 1, n, 1);
      ans[i] += sgt:: vl[1];
    }
    reverse(a + 1, a + n + 1);
  }
  for (ri i = 1; i <= n; ++i) {
    ans[i] -= (ll) i * i;
    cout << ans[i] << '\n';
  }
  return 0;
}