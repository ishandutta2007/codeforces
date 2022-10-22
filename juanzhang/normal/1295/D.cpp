#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

typedef long long ll;

inline ll readll() {
  #define nc getchar()
  ll x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

ll getphi(ll x) {
  ll tmp = sqrt(x), res = x;
  rep(i, 2, tmp) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  return x > 1 ? res / x * (x - 1) : res;
}

int main() {
  int T = readll();
  while (T--) {
    ll a = readll(), m = readll();
    printf("%I64d\n", getphi(m / gcd(a, m)));
  }
  return 0;
}