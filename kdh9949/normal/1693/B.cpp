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
    vector<vint> e(n + 1);
    for(int i = 2; i <= n; i++) { ints(x); e[x].push_back(i); }
    vpii a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

    int ans = 0;
    const function<int(int)> f = [&](int x) {
      ll r = 0;
      for(int i : e[x]) r += f(i);
      if(r < a[x].x) { ans++; r = a[x].y; }
      return int(min(r, ll(a[x].y)));
    };
    f(1);
  
    cout << ans << '\n';
  }
}