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
int n, a[maxn];

int sz[maxn]; ll sum[maxn];

int main() {
  n = read();
  rep(i, 1, n) a[i] = read();
  int tot = 0;
  for (int i = n; i; i--) {
    int cnt = 1; ll val = a[i];
    while (tot && 1.0 * val / cnt > 1.0 * sum[tot] / sz[tot]) {
      cnt += sz[tot], val += sum[tot], tot--;
    }
    tot++, sz[tot] = cnt, sum[tot] = val;
  }
  per(i, tot, 1) {
    rep(j, 1, sz[i]) {
      printf("%.10lf\n", (double) sum[i] / sz[i]);
    }
  }
  return 0;
}