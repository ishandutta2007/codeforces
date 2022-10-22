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
const int maxn = 35010, base = 1e7 + 19, P = 1e9 + 7;
int n, m, q, tot, pw[1010];

int st[35000], ed[35000];

struct node {
  int val, cost;
} A[35000];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int dp[17][1010];
vector <int> vec[maxn << 2];

void add(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) return vec[k].push_back(x), void();
  if (ql <= mid) add(lson, ql, qr, x);
  if (qr > mid) add(rson, ql, qr, x);
}

void divide(int k, int l, int r, int dep) {
  memcpy(dp[dep], dp[dep - 1], (m + 1) << 2);
  for (int pos : vec[k]) {
    int val = A[pos].val, cost = A[pos].cost;
    per(i, m, cost) chkmax(dp[dep][i], dp[dep][i - cost] + val);
  }
  if (l == r) {
    int res = 0;
    rep(i, 1, m) res = (res + 1ll * dp[dep][i] * pw[i - 1]) % P;
    printf("%d\n", res);
    return;
  }
  divide(lson, dep + 1), divide(rson, dep + 1);
}

#undef mid
#undef lson
#undef rson

int main() {
  pw[0] = 1;
  rep(i, 1, 1000) pw[i] = 1ll * base * pw[i - 1] % P;
  cin >> n >> m;
  rep(i, 1, n) {
    A[i].val = read(), A[i].cost = read(), st[i] = 1;
  }
  memset(ed, 0x3f, sizeof ed);
  tot = n;
  cin >> q;
  int now = 0;
  rep(i, 1, q) {
    int op = read();
    if (op == 1) {
      tot++, A[tot].val = read(), A[tot].cost = read(), st[tot] = now + 1;
    } else if (op == 2) {
      ed[read()] = now;
    } else {
      now++;
    }
  }
  rep(i, 1, tot) if (st[i] <= ed[i]) {
    add(1, 1, now, st[i], ed[i], i);
  }
  divide(1, 1, now, 1);
  return 0;
}