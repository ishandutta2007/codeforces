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
  vint a, d;
  int sz;

  void i(int n) {
    for(sz = 1; sz < n; sz *= 2);
    cerr << sz << endl;
    a = vint(sz, -1);
    d = vint(2 * sz);
    for(int i = sz; i < 2 * sz; i++) d[i] = i - sz;
    for(int i = sz - 1; i; i--) d[i] = d[2 * i];
  }

  void u(int x, int v) {
    a[x] = v;
    for(x = (x + sz) / 2; x; x /= 2) {
      d[x] = (a[d[2 * x]] > a[d[2 * x + 1]] ? d[2 * x] : d[2 * x + 1]);
    }
  }

  int g(int s, int e) {
    int r = s;
    for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
      if(s & 1) { if(a[r] < a[d[s]]) r = d[s]; s++; }
      if(~e & 1) { if(a[r] < a[d[e]]) r = d[e]; e--; }
    }
    return r;
  }
} S;

void solve() {
  int n, k;
  cin >> n >> k;

  vint a(n), p(n + 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }

  S.i(n);
  vint b(k);
  for(int i = 0; i < k; i++) {
    cin >> b[i];
    S.u(p[b[i]], i);
  }

  const static ll M = 998244353;
  function<ll(int, int)> f = [&](int s, int e) {
    int t = S.g(s, e);
    if(S.a[t] < 0) return 1LL;
    ll r = 1, c = 0;
    if(s < t) { r *= f(s, t - 1); c++; }
    if(t < e) { r *= f(t + 1, e); c++; }
    return r * c % M;
  };
  cout << f(0, n - 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}