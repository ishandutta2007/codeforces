#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
typedef long long ll;
typedef pair <ll, int> pli;
inline int read() {
  static int ans;
  static char ch;
  for (ch = gc(); !isdigit(ch); ch = gc());
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
  return ans;
}
const int N = 3e5 + 5;
int n, m, a[N], L = 300000, ps[N];
ll ans[N];
inline pli operator + (pli a, pli b) {
  return pli(a.fi + b.fi, a.se + b.se);
}
namespace sgt1 {
  #define lc (p << 1)
  #define rc (p << 1 | 1)
  #define mid (l + r >> 1)
  #define qll lc, l, mid
  #define qrr rc, mid + 1, r
  int ql, qr;
  pli ss[N << 2];
  inline void pushup(int p) {
    ss[p] = ss[lc] + ss[rc];
  }
  inline void upd(int p, int l, int r, int k) {
    if (l == r) {
      ss[p] = pli(k, 1);
      return;
    }
    k <= mid ? upd(qll, k) : upd(qrr, k);
    pushup(p);
  }
  inline pli qry(int p, int l, int r) {
    if (ql <= l && r <= qr) {
      return ss[p];
    }
    if (qr <= mid) {
      return qry(qll);
    }
    if (ql > mid) {
      return qry(qrr);
    }
    return qry(qll) + qry(qrr);
  }
  inline pli qry(int l, int r) {
    ql = l;
    qr = r;
    return qry(1, 0, L);
  }
}
namespace sgt2 {
  int ql, qr;
  ll tga1[N << 2], tgd[N << 2];
  inline void pushnow(int p, ll a1, ll d) {
    tga1[p] += a1;
    tgd[p] += d;
  }
  inline void pushdown(int p, int l, int r) {
    if (tga1[p] || tgd[p]) {
      pushnow(lc, tga1[p], tgd[p]);
      pushnow(rc, tga1[p] + (mid + 1 - l) * tgd[p], tgd[p]);
      tga1[p] = tgd[p] = 0;
    }
  }
  inline void upd(int p, int l, int r, ll a1, ll d) {
    if (ql <= l && r <= qr) {
      pushnow(p, a1 + (l - ql) * d, d);
      return;
    }
    pushdown(p, l, r);
    if (qr <= mid) {
      upd(qll, a1, d);
    } else if (ql > mid) {
      upd(qrr, a1, d);
    } else {
      upd(qll, a1, d);
      upd(qrr, a1, d);
    }
  }
  inline void upd(int l, int r, ll a1, ll d) {
    ql = l;
    qr = r;
    upd(1, 0, L, a1, d);
  }
  inline void fix(int p, int l, int r, int k) {
    if (l == r) {
      tga1[p] = tgd[p] = 0;
      return;
    }
    pushdown(p, l, r);
    k <= mid ? fix(qll, k) : fix(qrr, k);
  }
  inline void dfs(int p, int l, int r) {
    if (l == r) {
      ans[ps[l]] += tga1[p];
      return;
    }
    pushdown(p, l, r);
    dfs(qll);
    dfs(qrr);
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
    for (ri l = 0, r = a[i] - 1; l <= L; l += a[i], r += a[i]) {
      r = min(r, L);
      pli t = sgt1:: qry(l, r);
      ans[i] += t.fi - (ll) t.se * l;
    }
    sgt1:: upd(1, 0, L, a[i]);
  }
  for (ri i = n; i; --i) {
    ps[a[i]] = i;
    for (ri l = 0, r = a[i] - 1; l <= L; l += a[i], r += a[i]) {
      r = min(r, L);
      sgt2:: upd(l, r, 0, 1);
    }
    sgt2:: fix(1, 0, L, a[i]);
  }
  sgt2:: dfs(1, 0, L);
  ans[0] = 0;
  for (ri i = 1; i <= n; ++i) {
    ans[i] += ans[i - 1];
    cout << ans[i] << ' ';
  }
  return 0;
}