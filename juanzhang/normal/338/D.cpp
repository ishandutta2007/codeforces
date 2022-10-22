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
ll R, C;

int n;
ll A[10010];

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

ll Rpos, Cpos;

vector <ll> fac;

#define quit return puts("NO"), void()

namespace excrt {
  typedef long double db;
  int n;
  ll a[100010], b[100010];
  
  void add(ll x, ll y) {
    a[++n] = x, b[n] = y;
//    printf("(%lld %lld)\n", x, y);
  }

  ll mul(ll a, ll b, ll P) {
    ll res = a * b - ll((db) a * b / P) * P;
    return res < 0 ? res + P : res;
  }

  ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) return x = 1, y = 0, a;
    ll res = exgcd(b, a % b, y, x);
    return y -= a / b * x, res;
  }

  ll excrt() {
    ll lcmtmp = 1;
    rep(i, 1, n) {
      ll tmp = b[i] / gcd(lcmtmp, b[i]);
      if ((long double) C / lcmtmp + 0.5 > tmp) {
        lcmtmp *= tmp;
      } else {
        return -1;
      }
    }
    if (lcmtmp > C) return -1;
//    printf("#%lld\n", lcmtmp);
    ll res = 0, M = 1, x, y;
    for (int i = 1; i <= n; i++) {
      ll g = exgcd(M, b[i], x, y), P = b[i] / g;
      ll ans = (a[i] - res % b[i] + b[i]) % b[i];
      res += M * mul(x, ans / g, P);
      M *= P, res = (res % M + M) % M;
    }
    return res ? res : lcmtmp;
  }

//  int main() {
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) {
//      scanf("%lld %lld", b + i, a + i);
//    }
//    printf("%lld", excrt());
//    return 0;
//  }
}

void solve() {
  cin >> R >> C >> n;
  Rpos = 1;
  rep(i, 1, n) {
    scanf("%lld", &A[i]);
    ll tmp = A[i] / gcd(Rpos, A[i]);
    if ((long double) R / Rpos + 0.5 > tmp) {
      Rpos *= tmp;
    } else {
      quit;
    }
  }
  if (Rpos > R) quit;
  rep(i, 2, sqrt(Rpos) + 0.5) if (Rpos % i == 0) {
    fac.push_back(i), fac.push_back(Rpos / i);
  }
  for (ll val : fac) /*if (val == 2 || (val % 2 == 1 && (val % 6 == 1 || val % 6 == 5)))*/ {
    int pos = -1;
    rep(i, 1, n) if (A[i] % val == 0) {
      pos = i; break;
    }
    if (pos == -1) {
      if (n >= val) quit;
      continue;
    }
    if (pos > val) quit;
    ll cur = pos;
    for (; cur <= n; cur += val) if (A[cur] % val != 0) {
      quit;
    }
    excrt::add((1 - pos + val) % val, val);
  }
  Cpos = excrt::excrt();
  if (Cpos < 1 || Cpos + n - 1 > C) quit;
//  printf("%lld %lld\n", Rpos, Cpos);
//  printf("#(%lld)\n", gcd(Rpos, Cpos));
  rep(i, 1, n) if (gcd(Rpos, Cpos + i - 1) != A[i]) {
//    printf("#%d %lld\n", i, A[i]);
    quit;
  }
  puts("YES");
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}