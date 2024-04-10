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
const int maxn = 2010, P = 1e9 + 7;

int Inc(int x, int y) {
  return x + y < P ? x + y : x + y - P;
}

int n, k, L;

struct node {
  int x, y, col;
} A[maxn];

vector <int> data[maxn][maxn];
int totx, toty, arr[maxn], Vx[maxn], Vy[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int cov[maxn << 2], mn[maxn << 2], mx[maxn << 2], sum[maxn << 2];

void pushtag(int k, int x, int l, int r) {
  mn[k] = mx[k] = cov[k] = x, sum[k] = 1ll * (Vy[r + 1] - Vy[l]) * x % P;
}

void pushdown(int k, int l, int r) {
  int &t = cov[k];
  if (t == -1) return;
  pushtag(k << 1, t, l, mid), pushtag(k << 1 | 1, t, mid + 1, r), t = -1;
}

void maintain(int k) {
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
  mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
  sum[k] = Inc(sum[k << 1], sum[k << 1 | 1]);
}

void build(int k, int l, int r) {
  cov[k] = -1;
  if (l == r) {
    mn[k] = mx[k] = Vy[arr[l]];
    sum[k] = 1ll * (Vy[l + 1] - Vy[l]) * mn[k] % P; return;
  }
  build(lson), build(rson), maintain(k);
}

void upd(int k, int l, int r, int ql, int qr, int x) {
  if (l == r) {
    if (mn[k] >= x && mx[k] <= Vy[ql]) mn[k] = mx[k] = x, sum[k] = 1ll * (Vy[l + 1] - Vy[l]) * x % P;
    return;
  }
  if (ql <= l && r <= qr && mn[k] >= x && mx[k] <= Vy[ql]) {
    pushtag(k, x, l, r); return;
  }
  pushdown(k, l, r);
  if (ql <= mid) upd(lson, ql, qr, x);
  if (qr > mid) upd(rson, ql, qr, x);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin >> n >> k >> L;
  rep(i, 1, n) {
    int x = read() + 1, y = read() + 1;
    Vx[i] = x, Vy[i] = y, A[i] = {x, y, read()};
  }
  sort(Vx + 1, Vx + n + 1);
  totx = unique(Vx + 1, Vx + n + 1) - Vx - 1;
  sort(Vy + 1, Vy + n + 1);
  toty = unique(Vy + 1, Vy + n + 1) - Vy - 1;
  rep(i, 1, n) {
    A[i].x = lower_bound(Vx + 1, Vx + totx + 1, A[i].x) - Vx;
    A[i].y = lower_bound(Vy + 1, Vy + toty + 1, A[i].y) - Vy;
    data[A[i].x][A[i].y].push_back(A[i].col);
  }
  Vx[totx + 1] = Vy[toty + 1] = L + 1;
  sort(A + 1, A + n + 1, [] (node P, node Q) {
    return P.x < Q.x || (P.x == Q.x && P.y < Q.y);
  });
//  putchar('X');
//  rep(i, 1, totx) Sx[i] = Sx[i - 1] + Vx[i], printf("%d%c", Vx[i], "\n "[i < totx]);
//  putchar('Y');
//  rep(i, 1, toty) Sy[i] = Sy[i - 1] + Vy[i], printf("%d%c", Vy[i], "\n "[i < toty]);
//  rep(i, 1, n) printf("#(%d %d %d)\n", A[i].x, A[i].y, A[i].col);
  int ans = 0;
  static set <int> pos[maxn];
  static map <int, int> seq[maxn];
  rep(D, 1, totx) {
    rep(i, 1, maxn - 1) {
      pos[i].clear(), seq[i].clear();
      pos[i].insert(0), pos[i].insert(toty + 1);
    }
    rep(i, 1, n) {
      if (A[i].x > D) break;
      seq[A[i].y][A[i].col]++;
      pos[A[i].col].insert(A[i].y);
    }
    int now = 0;
    static int cnt[maxn];
    memset(cnt, 0, sizeof cnt);
    auto it = seq[0].begin();
    for (int i = 1, j = 0; i <= toty; arr[i++] = j) {
      for (pii p : seq[i]) {
        int c = p.first, s = p.second;
        now += !cnt[c], cnt[c] += s;
        bool flg = now == k;
        while (flg && j < i) {
          if (it == seq[j].end()) it = seq[++j].begin();
          while (it != seq[j].end()) {
            int tc = it -> first, ts = it -> second;
            if (cnt[tc] <= ts) {
              flg = 0; break;
            }
            cnt[tc] -= ts, ++it;
          }
        }
      }
    }
    build(1, 1, toty);
    for (int U = 1, i = 1; U <= D; U++) {
      for (; i <= n && A[i].x < U; i++) {
        if (--seq[A[i].y][A[i].col] > 0) continue;
        pos[A[i].col].erase(A[i].y);
        int prep = *--pos[A[i].col].lower_bound(A[i].y), nxtp = *pos[A[i].col].upper_bound(A[i].y);
        upd(1, 1, toty, A[i].y, nxtp - 1, Vy[prep]);
//        rep(j, A[i].y, nxtp - 1) {
//          if (arr[j] > A[i].y) break;
//          chkmin(arr[j], prep);
//        }
      }
//      int tmp = 0;
//      rep(j, 1, toty) {
//        tmp = (tmp + 1ll * Vy[arr[j]] * (Vy[j + 1] - Vy[j])) % ::P;
//      }
      int tmp = sum[1];
      ans = (ans + 1ll * (Vx[U] - Vx[U - 1]) * (Vx[D + 1] - Vx[D]) % ::P * tmp) % ::P;
    }
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}