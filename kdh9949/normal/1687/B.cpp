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
  //ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(n, m);
  vpii v;
  for(int i = 0; i < m; i++) {
    string s(m, '0');
    s[i] = '1';
    cout << "? " << s << endl;
    ints(x);
    v.emplace_back(x, i);
  }
  sort(all(v));
  string s(m, '0');
  int ans = 0, lst = 0;
  for(pii p : v) {
    s[p.y] = '1';
    cout << "? " << s << endl;
    ints(cur);
    if(cur - lst == p.x) ans += p.x;
    lst = cur;
  }
  cout << "! " << ans << endl;
  return 0;
}