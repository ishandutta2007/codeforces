// LUOGU_RID: 91282324
#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e5 + 10;
const int mod = 1e9 + 7, inv2 = (mod + 1) / 2;
struct P {
  ll x, y;
  P operator + (const P &b) { return {x + b.x, y + b.y}; }
  P operator - (const P &b) { return {x - b.x, y - b.y}; }
} a[N], s[N];
int n, bm[N], c[N];
ull b[N];
ull detu(P a, P b) {
  return (ull)a.x * b.y - (ull)a.y * b.x; 
}
int detmod(P a, P b) { //a in LL, b in int
  return (a.x % mod * b.y - a.y % mod * b.x) % mod; 
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%lld%lld", &a[i].x, &a[i].y);
  reverse(a + 1, a + n + 1);
  rep(i, 1, n) {
    s[i] = s[i - 1] + a[i];
    b[i] = b[i - 1] + detu(a[i - 1], a[i]);
    bm[i] = (bm[i - 1] + detmod(a[i - 1], a[i])) % mod;
    c[i] = (c[i - 1] + bm[i]) % mod;
  }
  ull tot = b[n] + detu(a[n], a[1]);
  int tm = tot % mod;
  // cerr << "tot " << tot << endl;
  int v = 2, ans = 0;
  rep(u, 1, n) {
    for(; v < n && b[v + 1] - b[u] + detu(a[v + 1], a[u]) <= tot / 2; v ++);
    // cerr << "v: " << v << endl;
    ans = (ans + (ll)c[v] - c[u] - (v - u) * (ll)bm[u] + detmod(s[v] - s[u], a[u])) % mod;
    ans = (ans + (ll)(n - v) * tm - ( c[n] - c[v] - (ll)(n - v) * bm[u] + detmod(s[n] - s[v], a[u]) )) % mod;
  }
  // cerr << "ans: " << ans << endl;
  ans = (tm * (n * (n - 3ll) / 2 % mod) % mod * inv2 % mod - ans) % mod;
  ans = ans * 2 % mod;
  ans = (ans + mod) % mod;
  printf("%d\n", ans);
  return 0;
}