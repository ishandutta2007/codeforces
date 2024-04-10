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
ll n, k;

ll calc1(ll mid) {
  ll res = 0;
  for (ll x = mid, l = 1; x <= n; x <<= 1, l <<= 1) {
    res += min(l, n - x + 1);
  }
  return res;
}

ll calc2(ll mid) {
  ll res = 0;
  for (ll x = mid, l = 2; x <= n; x <<= 1, l <<= 1) {
    res += min(l, n - x + 1);
  }
  return res;
}

int main() {
  scanf("%I64d %I64d", &n, &k);
  ll l = 1, r = (n + 1) / 2, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    calc1(mid * 2 - 1) < k ? r = mid - 1 : l = (ans = mid) + 1;
  }
  ll res = ans * 2 - 1;
  l = 1, r = n / 2, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    calc2(mid * 2) < k ? r = mid - 1 : l = (ans = mid) + 1;
  }
  chkmax(res, ans * 2);
  printf("%I64d", res);
  return 0;
}