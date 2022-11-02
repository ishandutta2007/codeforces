#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
inline int ls(int u) { return u << 1; }
inline int rs(int u) { return u << 1 | 1; }
const ll inf = 1e18;
const int maxn = 6e5 + 5, maxm = 1 << 21;
struct trip {
  ll a, b, c;
};
const trip zero = {-inf, -inf, -inf};
trip operator+(const trip &a, const trip &b) {
  return {max(a.a, b.a), max(a.b, b.b), max(a.c, b.c)};
}
int log[maxn];
ll q[maxn], p[maxn];
map<ll, ll> k;
ll x[maxn], y[maxn];
map<ll, int> pos;
int l[maxm], r[maxm];
trip v[maxm];
void build(int l_, int r_, int u = 1) {
  l[u] = l_;
  r[u] = r_;
  if (l_ == r_) {
    v[u] = {y[l_], y[l_] - x[l_], y[l_] + x[l_]};
    return;
  }
  int m_ = l_ + (r_ - l_) / 2;
  build(l_, m_, ls(u));
  build(m_ + 1, r_, rs(u));
  v[u] = v[ls(u)] + v[rs(u)];
}
trip query(int l_, int r_, int u = 1) {
  if (l[u] >= l_ && r[u] <= r_) return v[u];
  if (l[u] > r_ || r[u] < l_) return zero;
  return query(l_, r_, ls(u)) + query(l_, r_, rs(u));
}
int main() {
  log[1] = 0;
  for (int i = 2; i < maxn; i++) log[i] = log[i >> 1] + 1;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, lim;
    scanf("%d%d", &n, &lim);
    k.clear();
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld", &q[i], &p[i]);
      k[q[i] - p[i]]++;
      k[q[i]] -= 2;
      k[q[i] + p[i]]++;
    }
    int m = 0;
    ll sumk = 0, lasx = 0, lasy = 0;
    pos.clear();
    for (auto pr : k) {
      x[m] = pr.first;
      y[m] = lasy + sumk * (x[m] - lasx);
      sumk += pr.second;
      lasx = x[m];
      lasy = y[m];
      pos[x[m]] = m;
      m++;
    }
    // for (int i = 0; i < m; i++) cout << x[i] << ',' << y[i] << ' ';
    // cout << endl;
    build(0, m);
    for (int i = 0; i < n; i++) {
      int m1 = pos[q[i] - p[i]], m2 = pos[q[i]], m3 = pos[q[i] + p[i]];
      ll xx = x[m2];
      // printf("%d: %d %d %d %d %lld %lld\n", i, m1, m2, m3, lim, p[i], xx);
      ll resa = query(0, m1).a, resb = query(m1, m2).b, resc = query(m2, m3).c,
         resd = query(m3, m - 1).a;
      // printf("%lld %lld %lld %lld\n", resa, resb, resc, resd);
      // printf("in query: %d %d\n",0,m1);
      if (resa > lim) {
        putchar('0');
        continue;
      }
      // printf("in query: %d %d\n",m1,m2);
      if (resb > lim + p[i] - xx) {
        putchar('0');
        continue;
      }
      // printf("in query: %d %d\n",m2,m3);
      if (resc > lim + p[i] + xx) {
        putchar('0');
        continue;
      }
      // printf("in query: %d %d\n",m3,m-1);
      if (resd > lim) {
        putchar('0');
        continue;
      }
      putchar('1');
    }
    puts("");
  }
  return 0;
}