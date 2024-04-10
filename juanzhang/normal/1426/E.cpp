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
int n;

void solve(int a1, int a2, int a3, int b1, int b2, int b3, int flg) {
  int res = 0;
  
  if (flg == 1) {
    int tmp = 0;
    tmp=max(tmp,a1+b3-n);
    tmp=max(tmp,a2+b1-n);
    tmp=max(tmp,a3+b2-n);
    printf("%d ",tmp);
  } else {
  int t = min(a1, b2);
  res += t, a1 -= t, b2 -= t;
  t = min(a2, b3);
  res += t, a2 -= t, b3 -= t;
  t = min(a3, b1);
  res += t, a3 -= t, b1 -= t;
    printf("%d", res);
  }
}

void solve() {
  n = read();
  int a1, a2, a3, b1, b2, b3;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
  solve(b1, b2, b3, a1, a2, a3, 1);
  solve(a1, a2, a3, b1, b2, b3, 2);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}