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

  ints(n);
  vll a(n);
  for(ll &x : a) cin >> x;

  auto has_int = [&](ll a, ll b, ll c, ll d) {
    return min(b, d) >= max(a, c);
  };

  for(ll s = 1; ; s++) {
    if(s * s + s < a[0]) continue;
    pll seg(max(a[0], s * s), s * s + s);
    int ci = 0;
    ll t = s;
    while(seg.x <= seg.y) {
      ci = int(upper_bound(ci + 1 + all(a), t * t + t - seg.x + a[0]) - a.begin() - 1);
      //while(ci < n - 1 && a[ci + 1] - a[ci] <= t && a[ci + 1] - a[0] + seg.x <= t * t + t) ci++;
      if(ci == n - 1) {
        seg.y = min(seg.y, t * t + t - a[ci] + a[0]);
        break;
      }
      if((ci < n - 1 && a[ci + 1] - a[ci] <= t) || t * t + t < a[ci] - a[0] + seg.x) { seg.y = -1; break; }
      seg.y = min(seg.y, t * t + t - a[ci] + a[0]);
      while(t * t + t < seg.x + a[ci + 1] - a[0]) t++;
      if(!has_int(t * t, t * t + t, seg.x + a[ci + 1] - a[0], seg.y + a[ci + 1] - a[0])) { seg.y = -1; break; }
      seg.x = max(seg.x, t * t - a[ci + 1] + a[0]);
      seg.y = min(seg.y, t * t + t - a[ci + 1] + a[0]);
      ci++;
    }
    if(seg.x <= seg.y) { cout << (seg.x - a[0]) << '\n'; return 0; }
  }

}