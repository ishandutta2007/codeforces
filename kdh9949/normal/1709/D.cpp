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
    vint d;
    int sz;
    void i(vint v) {
      int n = int(v.size()) - 1;
      for(sz = 1; sz <= n; sz *= 2);
      d = vint(2 * sz);
      for(int i = 1; i <= n; i++) d[i + sz] = v[i];
      for(int i = sz - 1; i; i--) d[i] = max(d[2 * i], d[2 * i + 1]);
    }
    int g(int s, int e) {
      int r = 0;
      for(s += sz, e += sz; s <= e; s /= 2, e /= 2) {
        if(s & 1) r = max(r, d[s++]);
        if(~e & 1) r = max(r, d[e--]);
      }
      return r;
    }
  } S;

  auto solve = [&]() {
    ints(n, m);
    vint a(m + 1);
    for(int i = 1; i <= m; i++) cin >> a[i];
    S.i(a);
    ints(q);
    while(q--) {
      ints(sy, sx, ey, ex, k);
      if((sx - ex) % k || (sy - ey) % k) { cout << "NO\n"; continue; }
      if(sx > ex) { swap(sx, ex); swap(sy, ey); } 
      int h = sy + (n - sy) / k * k;
      cout << (S.g(sx, ex) < h ? "YES\n" : "NO\n");
    }
  };

  //ints(t);
  int t = 1;
  while(t--) solve();

  return 0;
}