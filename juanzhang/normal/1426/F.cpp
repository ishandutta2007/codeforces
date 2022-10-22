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
const int maxn = 2e5 + 10, P = 1e9 + 7;
int n, t[3];
char str[maxn];

void solve() {
  scanf("%d %s", &n, str + 1);
  int res = 0,tp = 1;
  rep(i, 1, n) {
    //per(c, 2, 0) if (str[i] == '?' || str[i] == 'a' + c) {
      if (str[i] == 'c') {
        res = (res + t[1]) % P;
      } else if (str[i] == 'b') {
        t[1] = (t[1] + t[0]) % P;
      } else if (str[i] == 'a') {
        t[0] = (t[0] + tp) % P;
      }
      else
      {
        res = (3ll * res + t[1]) % P;
        t[1] = (3ll * t[1] + t[0]) % P;
        t[0] = (3ll * t[0] + tp) % P;
        tp = 3ll * tp % P;
      }
    //}
  }
  cout << res << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}