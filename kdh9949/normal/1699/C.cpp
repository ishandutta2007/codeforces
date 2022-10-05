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

  ints(t);
  while(t--) {
    ints(n);
    vint p(n), q(n);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
      q[p[i]] = i;
    }
    ll ans = 1;
    constexpr ll M = ll(1e9) + 7;
    int l = q[0], r = q[0];
    for(int i = 0; i < n; i++) {
      int pl = l, pr = r;
      l = min(l, q[i]);
      r = max(r, q[i]);
      if(l == pl && r == pr) ans *= (r - l + 1 - i);
      ans %= M;
    }
    cout << ans << '\n';
  }

  return 0;
}