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
typedef pair <int, int> pii;
#define fi first
#define se second
const int N = 2e5 + 5;
int n, m, ans[N];
pii a[N];
namespace bst {
  #define lc son[p][0]
  #define rc son[p][1]
  int son[N][2], vl1[N], vl2[N], tg1[N], tg2[N], sz[N], rd[N], rt = 0;
  inline void pushadd1(int p, int v) {
    vl1[p] += v;
    tg1[p] += v;
  }
  inline void pushadd2(int p, int v) {
    vl2[p] += v;
    tg2[p] += v;
  }
  inline void pushdown(int p) {
    if (tg1[p]) {
      if (lc) {
        pushadd1(lc, tg1[p]);
      }
      if (rc) {
        pushadd1(rc, tg1[p]);
      }
      tg1[p] = 0;
    }
    if (tg2[p]) {
      if (lc) {
        pushadd2(lc, tg2[p]);
      }
      if (rc) {
        pushadd2(rc, tg2[p]);
      }
      tg2[p] = 0;
    }
  }
  inline void pushup(int p) {
    sz[p] = sz[lc] + 1 + sz[rc];
  }
  inline int merge(int x, int y) {
    if (!x || !y) {
      return x | y;
    }
    pushdown(x);
    pushdown(y);
    if (rd[x] < rd[y]) {
      son[x][1] = merge(son[x][1], y);
      pushup(x);
      return x;
    }
    son[y][0] = merge(x, son[y][0]);
    pushup(y);
    return y;
  }
  inline pii split(int p, int v) {
    if (!p) {
      return pii(0, 0);
    }
    pushdown(p);
    if (vl1[p] >= v) {
      pii res = split(lc, v);
      lc = res.se;
      pushup(p);
      return pii(res.fi, p);
    }
    pii res = split(rc, v);
    rc = res.fi;
    pushup(p);
    return pii(p, res.se);
  }
  inline void ins(int &x, int id) {
    pii t = split(x, vl1[id]);
    x = merge(merge(t.fi, id), t.se);
  }
  inline void dfs1(int p, int &x) {
    if (!p) {
      return;
    }
    pushdown(p);
    dfs1(lc, x);
    dfs1(rc, x);
    lc = rc = 0;
    sz[p] = 1;
    ins(x, p);
  }
  inline void dfs2(int p) {
    if (!p) {
      return;
    }
    pushdown(p);
    dfs2(lc);
    dfs2(rc);
    ans[p] = vl2[p];
  }
}
inline bool cmp(pii a, pii b) {
  return a.fi ^ b.fi ? a.fi > b.fi : a.se < b.se;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  srand(time(NULL));
  n = read();
  for (ri i = 1; i <= n; ++i) {
    a[i].se = read();
    a[i].fi = read();
  }
  sort(a + 1, a + n + 1, cmp);
  m = read();
  for (ri i = 1; i <= m; ++i) {
    bst:: vl1[i] = read();
    bst:: rd[i] = rand();
    bst:: sz[i] = 1;
    bst:: ins(bst:: rt, i);
  }
  for (ri i = 1; i <= n; ++i) {
    pii t = bst:: split(bst:: rt, a[i].se);
    bst:: pushadd1(t.se, -a[i].se);
    bst:: pushadd2(t.se, 1);
    pii tp = bst:: split(t.se, a[i].se);
    bst:: dfs1(tp.fi, t.fi);
    bst:: rt = bst:: merge(t.fi, tp.se);
  }
  bst:: dfs2(bst:: rt);
  for (ri i = 1; i <= m; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}