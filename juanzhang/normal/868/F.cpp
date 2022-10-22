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
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1e5 + 10;
ll dp[21][maxn];
int n, m, a[maxn];

ll nowAns;
int nowL, nowR, cnt[maxn];

void add(int x) { nowAns += cnt[x]++; }
void del(int x) { nowAns -= --cnt[x]; }

ll query(int l, int r) {
  while (nowL < l) del(a[nowL++]);
  while (nowL > l) add(a[--nowL]);
  while (nowR < r) add(a[++nowR]);
  while (nowR > r) del(a[nowR--]);
  return nowAns;
}

ll *Lst, *Ans;

void divide(int l, int r, int ql, int qr) {
  if (l > r) return;
  int mid = (l + r) >> 1, pos;
  Ans[mid] = 1e18;
  rep(i, ql, min(qr, mid - 1)) {
    ll v = Lst[i] + query(i + 1, mid);
    if (Ans[mid] > v) {
      Ans[mid] = v, pos = i;
    }
  }
  divide(l, mid - 1, ql, pos);
  divide(mid + 1, r, pos, qr);
}

int main() {
  n = read(), m = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) {
    dp[1][i] = dp[1][i - 1] + cnt[a[i]]++;
  }
  nowL = 1, nowR = 0;
  memset(cnt, 0, sizeof cnt);
  rep(i, 2, m) {
    Lst = dp[i - 1], Ans = dp[i];
    divide(i, n, 1, n);
  }
  printf("%I64d", dp[m][n]);
  return 0;
}