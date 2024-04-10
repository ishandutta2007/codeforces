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

const int maxn = 4e4 + 10;
char str[maxn];
int n, m, a[2][maxn], par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

int main() {
  scanf("%d %d", &n, &m);
  int ans = 0;
  rep(i, 1, m) par[i] = i;
  rep(T, 1, n) {
    int sel = T & 1;
    scanf("%s", str + 1);
    rep(i, 1, m / 4) {
      int val = str[i] < 58 ? str[i] - 48 : 10 + str[i] - 'A';
      a[sel][i << 2] = val & 1, val >>= 1;
      a[sel][(i - 1) << 2 | 3] = val & 1, val >>= 1;
      a[sel][(i - 1) << 2 | 2] = val & 1, val >>= 1;
      a[sel][(i - 1) << 2 | 1] = val & 1;
    }
    rep(i, 1, m) {
      ans += a[sel][i];
      int x = sel * m + i;
      if (i > 1 && a[sel][i] && a[sel][i - 1]) {
        par[x] = find(x - 1), --ans;
      } else {
        par[x] = x;
      }
    }
    rep(i, 1, m) {
      int x = sel * m + i;
      int y = (sel ^ 1) * m + i;
      if (a[sel][i] && a[sel ^ 1][i]) {
        x = find(x), y = find(y);
        if (x != y) par[y] = x, --ans;
      }
    }
  }
  cout << ans;
  return 0;
}