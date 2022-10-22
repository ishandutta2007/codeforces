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
const int maxn = 3e5 + 10;
int n, A[maxn], mp[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int tag[maxn << 2], val[maxn << 2];

void pushtag(int k, int x) {
  tag[k] += x, val[k] += x;
}

void pushdown(int k) {
  int &x = tag[k];
  if (x) pushtag(k << 1, x), pushtag(k << 1 | 1, x), x = 0;
}

void add(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) return pushtag(k, x), void();
  pushdown(k);
  if (ql <= mid) add(lson, ql, qr, x);
  if (qr > mid) add(rson, ql, qr, x);
  val[k] = max(val[k << 1], val[k << 1 | 1]);
}

#undef mid
#undef lson
#undef rson

int main() {
  cin >> n;
  rep(i, 1, n) A[i] = read(), mp[A[i]] = i;
  int ans = n;
  add(1, 1, n, 1, mp[n], 1);
  rep(i, 1, n) {
    int pos = read();
    printf("%d ", ans);
    if (i == n) break;
    add(1, 1, n, 1, pos, -1);
    while (ans > 1 && val[1] <= 0) {
      add(1, 1, n, 1, mp[--ans], 1);
    }
  }
  return 0;
}