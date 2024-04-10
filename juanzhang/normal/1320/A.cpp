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
const int maxn = 1e6 + 10;
ll ans[maxn];
int n, a[maxn];

int main() {
  int delta = 4e5;
  n = read();
  rep(i, 1, n) a[i] = read() - i;
  rep(i, 1, n) ans[a[i] + delta] += a[i] + i;
  ll res = 0;
  rep(i, 0, maxn - 1) chkmax(res, ans[i]);
  printf("%I64d", res);
  return 0;
}