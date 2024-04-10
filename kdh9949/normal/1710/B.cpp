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
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  struct Seg {
    int sz;
    vll d;
    void i(int n) {
      for(sz = 1; sz < n; sz *= 2);
      d = vll(2 * sz, -ll(1e18));
    }
    void u(int x, ll v) {
      for(x += sz; x; x /= 2) d[x] = max(d[x], v);
    }
    ll g(int s, int e) {
      ll r = -ll(1e18);
      for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
        if(s & 1) r = max(r, d[s++]);
        if(~e& 1) r = max(r, d[e--]);
      }
      return r;
    }
  } S, P, M;

  auto solve = [&]() {
    ints(n);
    lls(h);
    vpll a(n);
    map<ll, ll> b;
    for(int i = 0; i < n; i++) {
      cin >> a[i].x >> a[i].y;
      b[a[i].x - a[i].y]++;
      b[a[i].x] -= 2;
      b[a[i].x + a[i].y]++;
    }
    ll cur = 0, slope = 0, px = -ll(1e18);
    vll xs, ys;
    for(auto &p : b) {
      cur += slope * (p.x - px);
      xs.push_back(p.x);
      ys.push_back(cur);
      px = p.x;
      slope += p.y;
    }
    int m = xs.size();
    S.i(m); P.i(m); M.i(m);
    for(int i = 0; i < m; i++) {
      S.u(i, ys[i]);
      P.u(i, ys[i] + xs[i]);
      M.u(i, ys[i] - xs[i]);
    }
    for(int i = 0; i < n; i++) {
      int A = int(lower_bound(all(xs), a[i].x - a[i].y) - xs.begin());
      int B = int(lower_bound(all(xs), a[i].x) - xs.begin());
      int C = int(lower_bound(all(xs), a[i].x + a[i].y) - xs.begin());
      int val = 1;
      if(S.g(0, A) > h || S.g(C, m - 1) > h) val = 0;
      else if(M.g(A, B) > h + a[i].y - a[i].x) val = 0;
      else if(P.g(B, C) > h + a[i].y + a[i].x) val = 0;
      cout << char('0' + val);
    }
    cout << '\n';
  };

  ints(t);
  while(t--) {
    solve();
  }

  return 0;
}