#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

typedef long long ll;
const int maxn = 1e5 + 10;

int main() {
  int a, b, c, d, e, f;
  cin>>a>>b>>c>>d>>e>>f;
  ll ans = 0;
  rep(i, 0, min(a, d)) {
    chkmax(ans, 1ll * i * e + 1ll * f * max(0, min(b, min(c, d - i))));
  }
  printf("%I64d", ans);
  return 0;
}