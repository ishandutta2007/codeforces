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
  vint a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vector<vint> e(n + 1);
  for(int i = 0; i < n - 1; i++) {
    ints(x, y);
    e[x].push_back(y);
    e[y].push_back(x);
  }

  using Info = pair<set<int>*, int>;
  vector<Info> d(n + 1, make_pair(nullptr, 0));
  int ans = 0;
  const function<void(int, int)> f = [&](int x, int y) {
    int mc = 0, mi = -1;
    for(int i : e[x]) if(i != y) {
      f(i, x);
      if(d[i].x != nullptr && int(d[i].x->size()) > mc) {
        mc = d[i].x->size();
        mi = i;
      }
    }
    int fck = 0;
    if(mc == 0) d[x].x = new set<int>();
    else d[x] = d[mi];
    for(int i : e[x]) if(i != y && i != mi && d[i].x != nullptr) {
      int V = d[i].y, W = d[x].y;
      for(int y : *d[i].x) if(d[x].x->count(a[x] ^ V ^ W ^ y))
        { fck = 1; break; }
      if(fck) break;
      for(int y : *d[i].x) d[x].x->insert(y ^ V ^ W);
      d[i].x->clear();
    }
    if(d[x].x->count(d[x].y ^ a[x])) fck = 1;
    if(fck) { ans++; d[x].x->clear(); d[x].x = nullptr; }
    else { d[x].x->insert(d[x].y); d[x].y ^= a[x]; }
  };
  f(1, 0);
  cout << ans << '\n';
  return 0;
}