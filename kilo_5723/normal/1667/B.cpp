#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 2e6 + 5;
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
ll pos[maxn], neg[maxn];
ll l[maxn], r[maxn];
ll a[maxn], b[maxn];
void build(int u, int _l, int _r) {
  l[u] = b[_l];
  r[u] = b[_r - 1];
  // printf("%d %lld %lld\n",u,l[u],r[u]);
  pos[u] = -inf;
  neg[u] = -inf;
  if (_r - _l <= 1) return;
  int _m = (_l + _r) / 2;
  build(ls(u), _l, _m);
  build(rs(u), _m, _r);
}
void modify(int u, ll p, ll v1, ll v2) {
  if (l[u] > p || r[u] < p) return;
  pos[u] = max(pos[u], v1);
  neg[u] = max(neg[u], v2);
  if (l[u] == r[u]) return;
  modify(ls(u), p, v1, v2);
  modify(rs(u), p, v1, v2);
}
ll query1(int u, ll _l, ll _r) {
  if (l[u] > _r || r[u] < _l) return -inf;
  if (l[u] >= _l && r[u] <= _r) return pos[u];
  return max(query1(ls(u), _l, _r), query1(rs(u), _l, _r));
}
ll query2(int u, ll _l, ll _r) {
  if (l[u] > _r || r[u] < _l) return -inf;
  if (l[u] >= _l && r[u] <= _r) return neg[u];
  return max(query2(ls(u), _l, _r), query2(rs(u), _l, _r));
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i] += a[i - 1];
    }
    for (int i = 0; i <= n; i++) b[i] = a[i];
    sort(b, b + n + 1);
    int m = unique(b, b + n + 1) - b;
    build(1, 0, m);
    map<ll, ll> eaq;
    eaq[0] = 0;
    modify(1, 0, 0, 0);
    for (int i = 1; i <= n; i++) {
      ll ans = -inf;
      if (eaq.count(a[i])) ans = eaq[a[i]];
      ans = max(ans, query1(1, -inf, a[i] - 1) + i);
      ans = max(ans, query2(1, a[i] + 1, inf) - i);
      if (eaq.count(a[i]))
        eaq[a[i]] = max(eaq[a[i]], ans);
      else
        eaq[a[i]] = ans;
      modify(1, a[i], ans - i, ans + i);
      if (i == n) printf("%lld\n", ans);
    }
  }
  return 0;
}