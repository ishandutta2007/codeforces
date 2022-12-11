#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
ll n, m, a[N], ai[N];
int k;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y): x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
void exgcd(ll a, ll b, ll &x, ll &y, ll &g) {
  if(!b) { x = 1, y = 0, g = a; }
  else exgcd(b, a % b, y, x, g), y -= a / b * x;
}
ll mul(ll a, ll b, ll p) {
  ll r = a * b - (ll)(a / (long double)p * b + 0.5) * p;
  return r < 0 ? r + p : r;
}
ll excrt(int n, ll *ai, ll *mi) {
  ll c = ai[1], p = mi[1], x, y, g;
  rep(i, 2, n) {
    exgcd(p, mi[i], x, y, g);
    if((ai[i] - c) % g) return -1;
    ll t = mi[i] / g;
    c = (mul(mul(x, (ai[i] - c) / g, t), p, t * p) + c) % (t * p);
    p *= t;
  }
  return c <= 0 ? c + p : c;
}
int main() {
  scanf("%lld%lld%d", &n, &m, &k);
  ll z = 1;
  rep(i, 1, k) {
    scanf("%lld", a + i);
    z = lcm(z, a[i]);
    if(z > n) return puts("NO"), 0;
  }
  rep(i, 1, k) {
    ai[i] = (1 - i) % a[i];
    if(ai[i] < 0) ai[i] += a[i];
  }
  ll t = excrt(k, ai, a);
  if(!~t || t + k - 1 > m) return puts("NO"), 0;
  rep(i, 1, k) {
    if(gcd(t + i - 1, z) != a[i]) {
      puts("NO"); return 0;
    }
  }
  puts("YES");
  return 0;
}