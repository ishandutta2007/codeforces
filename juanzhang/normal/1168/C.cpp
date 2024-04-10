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
int n, q, A[maxn];

int nxt[19][maxn], jump[19][maxn];

void solve() {
  cin >> n >> q;
  rep(i, 1, n) A[i] = read();
  rep(i, 0, 18) nxt[i][n + 1] = jump[i][n + 1] = n + 1;
  per(i, n, 1) {
    rep(j, 0, 18) {
      nxt[j][i] = A[i + 1] >> j & 1 ? i + 1 : nxt[j][i + 1];
    }
    rep(j, 0, 18) {
      if (A[i] >> j & 1) {
        jump[j][i] = i; continue;
      }
      jump[j][i] = n + 1;
      rep(k, 0, 18) if (A[i] >> k & 1) chkmin(jump[j][i], jump[j][nxt[k][i]]);
    }
  }
  while (q--) {
    bool flg = 0;
    int x = read(), y = read();
    rep(i, 0, 18) {
      if ((A[y] >> i & 1) && jump[i][x] <= y) {
        flg = 1; break;
      }
    }
    puts(flg ? "Shi" : "Fou");
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}