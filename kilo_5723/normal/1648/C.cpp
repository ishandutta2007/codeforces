#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
int l[maxn * 4], r[maxn * 4], v[maxn * 4];
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return ls(u) | 1; }
void build(int u, int _l, int _r) {
  l[u] = _l;
  r[u] = _r;
  v[u] = 0;
  if (_l == _r) return;
  int m = (_l + _r) >> 1;
  build(ls(u), _l, m);
  build(rs(u), m + 1, _r);
}
void add(int u, int p, int _v) {
  if (l[u] > p || r[u] < p) return;
  v[u] = v[u] + _v;
  if (l[u] == r[u]) return;
  add(ls(u), p, _v);
  add(rs(u), p, _v);
}
int query(int u, int _l, int _r) {
  if (l[u] > _r || r[u] < _l) return 0;
  if (l[u] >= _l && r[u] <= _r) return v[u];
  return query(ls(u), _l, _r) + query(rs(u), _l, _r);
}
int a[maxn], b[maxn];
map<int, int> cnt;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll fact[maxn], _fact[maxn];
ll inv[maxn];
int main() {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++)
    inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  _fact[maxn - 1] = qpow(fact[maxn - 1], mod - 2);
  for (int i = maxn - 1; i; i--) _fact[i - 1] = _fact[i] * i % mod;
  ll n, m;
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  for (int i = m; i < n; i++) b[i] = 0;
  build(1, 0, maxn);
  for (int i = 0; i < n; i++) {
    add(1, a[i], 1);
    cnt[a[i]]++;
  }
  ll tot = fact[n];
  for (auto pr : cnt) {
    tot = tot * _fact[pr.second] % mod;
  }
  // printf("%lld\n",tot);
  ll ans = 0;
  int p = 0;
  while (p < n) {
    // printf("query : %d %d : %d\n",0,b[i]-1,query(1,0,b[i]-1));
    ans += tot * inv[n - p] % mod * query(1, 0, b[p] - 1) % mod;
    // printf("%lld %lld\n",tot,ans);
    if (!cnt[b[p]]) break;
    tot = tot * inv[n - p] % mod * cnt[b[p]] % mod;
    cnt[b[p]]--;
    add(1, b[p], -1);
    p++;
    // printf("add : %d %d\n",b[i],-1);
  }
  if (m > n && p == n) ans += tot;
  printf("%lld\n", ans % mod);
  return 0;
}