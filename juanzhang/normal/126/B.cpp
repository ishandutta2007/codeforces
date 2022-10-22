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
const int maxn = 1e6 + 10;
char A[maxn];
int n, ext[maxn];

void solve() {
  scanf("%s", A + 1);
  n = strlen(A + 1);
  int pos = -1, mx = 0;
  ext[1] = n;
  rep(i, 2, n) {
    if (i <= mx) ext[i] = min(mx - i + 1, ext[i - pos + 1]);
    while (A[ext[i] + 1] == A[ext[i] + i]) ext[i]++;
    if (mx < i + ext[i] - 1) pos = i, mx = i + ext[i] - 1;
  }
  mx = -1;
  rep(i, 2, n - 1) {
    chkmax(mx, i + ext[i] - 1 < n ? ext[i] : ext[i] - 1);
  }
  if (mx == -1) return puts("Just a legend"), void();
  int mx2 = -1;
  rep(i, n - mx + 1, n) if (i + ext[i] - 1 == n) {
    chkmax(mx2, ext[i]);
  }
  if (mx2 < 1) return puts("Just a legend"), void();
  rep(i, 1, mx2) putchar(A[i]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}