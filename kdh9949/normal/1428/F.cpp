#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

struct Seg {
  int sz;
  vll d, l;

  void ini(int n) {
    sz = 1;
    while(sz <= n) sz *= 2;
    d = vll(2 * sz);
    l = vll(2 * sz);

    for(int i = sz; i < sz + n; i++) d[i] = n;
    for(int i = sz - 1; i >= 1; i--) d[i] = d[2 * i] + d[2 * i + 1];
  };

  void spr(int x, int p, int q) {
    int m = (p + q) / 2;
    d[2 * x] += (m - p + 1) * l[x];
    l[2 * x] += l[x];
    d[2 * x + 1] += (q - m) * l[x];
    l[2 * x + 1] += l[x];
    l[x] = 0;
  }

  void u(int s, int e, ll v, int x, int p, int q) {
    if(e < p || q < s) return;
    if(s <= p && q <= e) {
      d[x] += (q - p + 1) * v;
      l[x] += v;
      return;
    }
    spr(x, p, q);
    int m = (p + q) / 2;
    u(s, e, v, 2 * x, p, m);
    u(s, e, v, 2 * x + 1, m + 1, q);
    d[x] = d[2 * x] + d[2 * x + 1];
  }

  ll g(int s, int e, int x, int p, int q) {
    if(e < p || q < s) return 0LL;
    if(s <= p && q <= e) return d[x];
    spr(x, p, q);
    int m = (p + q) / 2;
    return g(s, e, 2 * x, p, m) + g(s, e, 2 * x + 1, m + 1, q);
  }

  ll g(int s, int e) { return g(s, e, 1, 1, sz); }
  
  void u(int s, int e, ll v) { u(s, e, v, 1, 1, sz); }

} S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  S.ini(n);
  ll cs = 0, ans = 0;
  int cp = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '0') { ans += cs; cp = 0; continue; }
    cp++;
    ll cur = S.g(cp, cp);
    if(cp > 1) S.u(1, cp - 1, -1);
    S.u(cp, cp, (i + cp - 1) - cur);
    cs = 1LL * n * n - S.d[1];
    ans += cs;
  }

  cout << ans << '\n';
  return 0;
}