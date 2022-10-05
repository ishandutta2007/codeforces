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

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ints(t);

  while(t--) {
    ints(n, m);
    vector<vint> e(n + 1);
    int ans = 0;
    for(int i = 0; i < m; i++) {
      ints(x, y);
      if(x == y) continue;  
      e[x].push_back(y);
      e[y].push_back(x);
      ans++;
    }
    vint v(n + 1);
    function<int(int, int)> f = [&](int x, int y) {
      v[x] = 1;
      int r = 0;
      for(int i : e[x]) if(i != y) {
        if(v[i]) r = 1;
        else r |= f(i, x);
      }
      return r;
    };
    for(int i = 1; i <= n; i++) if(!v[i]) ans += f(i, 0);
    writeln(ans);
  }

  return 0;
}