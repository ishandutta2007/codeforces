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
const char str[] = "codeforces";

void solve() {
  ll k;
  cin >> k;
  rep(i, 1, 50) {
    ll tmp = 1;
    rep(j, 1, 10) {
      tmp *= i;
      if (tmp > k) break;
    }
    int pos = 11;
    per(j, 10, 1) {
      ll t = 1;
      rep(q, 1, 10) {
        if (q < j) t *= i;
        else t *= i - 1;
        if (t > k) break;
      }
      if (t < k) break;
      pos = j;
    }
    if (tmp >= k) {
      rep(p, 0, 9) {
        int cnt = p + 1 >= pos ? i - 1 : i;
        while (cnt--) putchar(str[p]);
      }
      return;
    }
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}