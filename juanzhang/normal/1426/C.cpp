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

void solve() {
  int n;
  scanf("%d",&n);
  int tp=sqrt(n);
  if(tp*tp==n)printf("%d\n",2*tp-2);
  else if(tp*(tp+1)>=n)printf("%d\n",2*tp-1);
  else printf("%d\n",2*tp);
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}