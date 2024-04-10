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
  cin.tie(0)->sync_with_stdio(0);

  ints(t);
  while(t--) {
    ints(n, m);
    vint a(m + 1);
    while(n--) { ints(x); a[x] = 1; }
    
    vint d(m + 1);
    iota(all(d), 0);
    vint c = a;
    int mx = m; while(!c[mx]) mx--;
    int bnd = int(find(all(a), 1) - a.begin());
    
    int ans = m - bnd;
    for(int mn = m; mn >= 2; mn--) {
      for(int i = mn; ll(mn) * i <= m; i++) {
        if(a[mn * i]) c[d[mn * i]]--;
        d[mn * i] = min(d[mn * i], d[i]);
        if(a[mn * i]) c[d[mn * i]]++;
        while(!c[mx]) mx--;
      }
      if(mn <= bnd) ans = min(ans, mx - mn);
    }
    ans = min(ans, mx - 1);
    cout << ans << '\n';
  }

  return 0;
}