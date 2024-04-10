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

  auto solve = [&]() {
    ints(n, m);
    vll a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vll l(n + 1), r(n + 1);
    for(int i = 1; i < n; i++) {
      l[i] = l[i - 1] + max(0LL, a[i + 1] - a[i]);
      r[i] = r[i - 1] + max(0LL, a[i] - a[i + 1]);
    }
    while(m--) {
      ints(x, y);
      if(x < y) cout << (r[y - 1] - r[x - 1]) << '\n';
      else cout << (l[x - 1] - l[y - 1]) << '\n';
    }
  };

  //ints(t);
  int t = 1;
  while(t--) solve();

  return 0;
}