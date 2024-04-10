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
const int maxn = 2e5 + 10;
int n, cnt[31], a[maxn], b[maxn], c[maxn];

#define Exit return puts("-1"), 0;

int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", b + i);
  rep(i, 1, n) scanf("%d", c + i);
  ll sum = 0;
  rep(i, 1, n) {
    sum += b[i] + c[i];
    if (b[i] > c[i]) Exit;
  }
  if (sum % (2 * n) != 0) Exit;
  sum /= 2 * n;
  rep(i, 1, n) {
    ll tmp = b[i] + c[i] - sum;
    if (tmp % n != 0) Exit;
    a[i] = tmp / n;
    rep(j, 0, 29) {
      cnt[j] += a[i] >> j & 1;
    }
  }
  rep(i, 1, n) {
    ll x = 0, y = 0;
    rep(j, 0, 29) {
      if (a[i] >> j & 1) {
        x += (ll) cnt[j] << j;
        y += (ll) n << j;
      } else {
        y += (ll) cnt[j] << j;
      }
    }
    if (x != b[i] || y != c[i]) Exit;
  }
  rep(i, 1, n) printf("%d ", a[i]);
  return 0;
}