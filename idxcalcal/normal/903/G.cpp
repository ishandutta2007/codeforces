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
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
typedef pair <int, int> pii;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int N = 2e5 + 5;
int n, m, Q, a[N], b[N];
ll C[N];
vector <pii> e[N];
namespace sgt {
  #define lc (p << 1)
  #define rc (p << 1 | 1)
  #define mid ((l + r) >> 1)
  #define qll lc, l, mid
  #define qrr rc, mid + 1, r
  ll mn[N << 2], tg[N << 2];
  int ql, qr;
  inline void pushnow(int p, ll v) {
    mn[p] += v;
    tg[p] += v;
  }
  inline void pushdown(int p) {
    if (tg[p]) {
      pushnow(lc, tg[p]);
      pushnow(rc, tg[p]);
      tg[p] = 0;
      return;
    }
  }
  inline void pushup(int p) {
    mn[p] = min(mn[lc], mn[rc]);
  }
  inline void upd(int p, int l, int r, ll v) {
    if (ql <= l && r <= qr) {
      pushnow(p, v);
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
  inline void upd(int l, int r, ll v) {
    ql = l;
    qr = r;
    upd(1, 1, n, v);
  }
  #undef lc
  #undef rc
  #undef mid
  #undef qll
  #undef qrr
}  //using namespace sgt;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  m = read();
  Q = read();
  for (ri i = 1; i < n; ++i) {
    a[i] = read();
    b[i + 1] = read();
    sgt:: upd(i + 1, i + 1, b[i + 1]);
  }
  for (ri i = 1, x, y, c; i <= m; ++i) {
    x = read();
    y = read();
    c = read();
    e[x].pb(pii(y, c));
  }
  for (ri i = 1; i <= n; ++i) {
    for (ri j = 0; j < e[i].size(); ++j) {
      sgt:: upd(1, e[i][j].fi, e[i][j].se);
    }
    C[i] = sgt:: mn[1];
  }
  memset(sgt:: mn, 0, sizeof(sgt:: mn));
  memset(sgt:: tg, 0, sizeof(sgt:: tg));
  for (ri i = 1; i <= n; ++i) {
    sgt:: upd(i, i, a[i] + C[i]);
  }
  cout << sgt:: mn[1] << '\n';
  for (ri x, y; Q; --Q) {
    x = read();
    y = read();
    sgt:: upd(x, x, y - a[x]);
    a[x] = y;
    cout << sgt:: mn[1] << '\n';
  }
  return 0;
}