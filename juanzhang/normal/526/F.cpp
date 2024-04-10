#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 3e5 + 10;
int n, A[maxn];

struct node {
  int l, r, x;
  
  bool operator < (const node &o) const {
    return l < o.l;
  }
};

int tmin, tmax;
node Smin[maxn], Smax[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int tag[maxn << 2];
int val[maxn << 2], cnt[maxn << 2];

void pushtag(int k, int x) {
  tag[k] += x, val[k] += x;
}

void pushdown(int k) {
  int &t = tag[k];
  if (!t) return;
  pushtag(k << 1, t), pushtag(k << 1 | 1, t), t = 0;
}

void maintain(int k) {
  int x = val[k << 1], y = val[k << 1 | 1];
  if (x < y) {
    val[k] = x, cnt[k] = cnt[k << 1];
  } else if (x > y) {
    val[k] = y, cnt[k] = cnt[k << 1 | 1];
  } else {
    val[k] = x, cnt[k] = cnt[k << 1] + cnt[k << 1 | 1];
  }
}

void upd(int k, int l, int r, int x) {
  if (l == r) return val[k] = x, cnt[k] = 1, void();
  x <= mid ? upd(lson, x) : upd(rson, x); maintain(k);
}

void add(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    pushtag(k, x); return;
  }
  pushdown(k);
  if (ql <= mid) add(lson, ql, qr, x);
  if (qr > mid) add(rson, ql, qr, x);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin >> n;
  rep(i, 1, n) {
    int x = read();
    A[x] = read();
  }
  ll ans = 0;
  memset(val, 0x3f, sizeof val);
  rep(i, 1, n) {
    for (; tmin && Smin[tmin].x > A[i]; tmin--) {
      add(1, 1, n, Smin[tmin].l, Smin[tmin].r, Smin[tmin].x - A[i]);
    }
    for (; tmax && Smax[tmax].x < A[i]; tmax--) {
      add(1, 1, n, Smax[tmax].l, Smax[tmax].r, A[i] - Smax[tmax].x);
    }
    ++tmin, Smin[tmin] = {Smin[tmin - 1].r + 1, i, A[i]};
    ++tmax, Smax[tmax] = {Smax[tmax - 1].r + 1, i, A[i]};
    upd(1, 1, n, i);
    if (val[1] == i) ans += cnt[1];
//    puts("-----");
//    rep(j, 1, tmin) printf("(%d %d %d)\n", Smin[j].l, Smin[j].r, Smin[j].x);
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}