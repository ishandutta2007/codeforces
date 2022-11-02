#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m; ll k;
ll g, l; pair<ll, ll> r;
int b[500005], o[1000005]; ll c[500005];

pair<ll, ll> exgcd(ll a, ll b) {
  if (b == 0) return {1ll, 0ll};
  const auto& r = exgcd(b, a%b);
  return {r.second, r.first-a/b*r.second};
}

ll crt(ll a, ll b) {
  __int128 t1 = a*m/g%(l/g), t2 = b*n/g%(l/g);
  return (t1*r.second + t2*r.first) % (l/g);
}

bool ok(ll t) {
  const ll tdl = t/l, tml = t%l;
  ll x = 0;
  for (int i = 0; i < m; i++)
    if (b[i] != -1)
      x += tdl + (c[i] < tml);
  return t-x < k;
}

int main() {
  // init
  scanf("%d%d%lld", &n, &m, &k);
  g = __gcd(n, m);
  l = n/g*m;
  r = exgcd(n/g, m/g);
  r = {(r.first%(l/g)+l/g)%(l/g), (r.second%(l/g)+l/g)%(l/g)};

  // input
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    o[x] = i+1;
  }
  for (int i = 0; i < m; i++) {
    int x; scanf("%d", &x);
    b[i] = o[x]-1;
  }

  // crt
  for (int i = 0; i < m; i++)
    if (b[i] != -1 && i%g == b[i]%g) {
      c[i] = crt(b[i]/g, i/g)*g + i%g;
      if (!(c[i] >= 0 && c[i] < l && c[i]%n == b[i] && c[i]%m == i)) {
        fprintf(stderr, "fail %d %d %lld\n", b[i], i, c[i]);
        return 1;
      }
    } else
      b[i] = -1;

  // solve
  ll lo = 0, hi = 1ll << 62;
  while (lo+1 < hi) {
    ll mid = (lo+hi) >> 1;
    (ok(mid) ? lo : hi) = mid;
  }

  printf("%lld\n", hi);
  return 0;
}