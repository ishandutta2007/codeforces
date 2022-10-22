#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, maxm = 7850, base = 63;
int n, m, tot, lg[maxm], a[maxn];

#define get(x) (((x) + base) >> 6)

struct linear_base {
  int a[20];

  inline void clr() {
    memset(a, 0, sizeof a);
  }

  inline void ins(int x, int lim = 19) {
    for (int i = lim; ~i; --i) {
      if (x >> i & 1) {
        if (!a[i]) { a[i] = x; return; }
        x ^= a[i];
      }
    }
  }

  inline int query() {
    int res = 0;
    for (int i = 19; ~i; --i) {
      if ((res ^ a[i]) > res) res ^= a[i];
    }
    return res;
  }
} null, lef[maxn], rig[maxn], val[13][maxm];

inline linear_base operator + (linear_base A, const linear_base &B) {
  for (int i = 19; ~i; --i) {
    if (B.a[i]) A.ins(B.a[i], i);
  }
  return A;
}

const int maxn_r = maxn * 23, maxn_w = maxn * 8;
char buf_r[maxn_r], *now_r = buf_r;
char buf_w[maxn_w], *now_w = buf_w;

inline int read() {
  int x = 0;
  while (*now_r < 48) ++now_r;
  while (*now_r > 47) x = (x << 3) + (x << 1) + (*now_r ^ 48), ++now_r;
  return x;
}

inline void write(int x) {
  static char *tp, st[7];
  if (!x) *now_w = 48, ++now_w;
  for (tp = st; x; *++tp = x % 10 | 48, x /= 10);
  while (tp != st) *now_w = *tp, ++now_w, --tp;
  *now_w = 10, ++now_w;
}

inline linear_base query(const int &l, const int &r) {
  if (l > r) return null;
  const int k = lg[r - l + 1];
  return val[k][l] + val[k][r - (1 << k) + 1];
}

int main() {
  fread(buf_r, 1, maxn_r, stdin);
  n = read(), tot = get(n);
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    val[0][get(i)].ins(a[i]);
  }
  for (int i = 2; i <= tot; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  linear_base lst;
  lst.clr();
  for (int i = 1; i <= n; ++i) {
    lst.ins(a[i]), lef[i] = lst;
    if (!(i & base)) lst.clr();
  }
  lst.clr();
  for (int i = n; i; --i) {
    if (!(i & base)) lst.clr();
    lst.ins(a[i]), rig[i] = lst;
  }
  for (int i = 1; i <= lg[tot]; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= tot; ++j) {
      val[i][j] = val[i - 1][j] + val[i - 1][j + (1 << (i - 1))];
    }
  }
  m = read();
  register linear_base ans;
  for (int q = 1; q <= m; ++q) {
    const int l = read(), r = read();
    const int L = get(l), R = get(r);
    ans.clr();
    if (L == R) {
      for (register int i = l; i <= r; ++i) {
        ans.ins(a[i]);
      }
    } else {
      ans = rig[l] + lef[r] + query(L + 1, R - 1);
    }
    write(ans.query());
  }
  fwrite(buf_w, 1, now_w - buf_w, stdout);
  return 0;
}