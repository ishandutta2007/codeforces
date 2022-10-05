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
    ints(x);
    ints(a, b, c);
    int cnt = 10;
    while(a + b + c) {
      if(x == 1) { x = a; a = 0; }
      else if(x == 2) { x = b; b = 0; }
      else if(x == 3) { x = c; c = 0; }
      cnt--;
      if(cnt == 0) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  };

  ints(t);
  while(t--) solve();

  return 0;
}