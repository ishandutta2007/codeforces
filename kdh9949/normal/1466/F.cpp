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

  ints(n, m);

  vint p(m + 1);
  iota(all(p), 0);
  function<int(int)> f = [&](int x) { return p[x] = (x == p[x] ? x : f(p[x])); };
  vint chk(m + 1);

  function<int(int, int)> ins = [&](int a, int b) {
    if(b != 0) {
      a = f(a);
      b = f(b);
      if(a == b) return 0;
      if(chk[a] && chk[b]) return 0;
      if(chk[b]) return ins(a, 0);
      if(chk[a]) return ins(b, 0);
      if(a > b) swap(a, b);
      p[a] = b;
      return 1;
    }
    else {
      a = f(a);
      if(chk[a]) return 0;
      chk[a] = 1;
      return 1;
    }
  };

  vint ans;
  for(int i = 1; i <= n; i++) {
    ints(k);
    int a = 0, b = 0;
    if(k == 1) cin >> a;
    else cin >> a >> b;
    if(ins(a, b)) ans.push_back(i);
  }

  int r = 1;
  const static int M = int(1e9) + 7;
  for(int i = 0; i < ans.size(); i++) r = r * 2 % M;
  cout << r << ' ' << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}