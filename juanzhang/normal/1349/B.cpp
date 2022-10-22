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
const int maxn = 1e5 + 10;
int n, k, A[maxn], val[maxn], sum[maxn];

void solve() {
  cin >> n >> k;
  bool flg = 0;
  rep(i, 1, n) A[i] = read(), val[i] = A[i] < k ? -1 : 1, sum[i] = sum[i - 1] + val[i], flg |= A[i] == k;
  if (!flg) {
    puts("no"); return;
  }
  if (n == 1) {
    puts("yes"); return;
  }
  int res = 0, tmp = 0;
  rep(i, 2, n) {
    chkmax(res, sum[i] - tmp), chkmin(tmp, sum[i - 1]);
  }
  puts(res > 0 ? "yes" : "no");
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}