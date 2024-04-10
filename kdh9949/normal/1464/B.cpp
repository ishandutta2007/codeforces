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

  string s;
  cin >> s;
  lls(a, b);
  int n = s.length();

  ll cur = 0;
  vint t(n);
  for(int i = 0; i < n; i++) if(s[i] == '1') t[i] = 1;
  ll zc = 0, oc = 0;
  for(int i = 0; i < n; i++) {
    if(t[i]) {
      cur += a * zc;
      oc++;
    }
    else {
      cur += b * oc;
      zc++;
    }
  }

  ll ans = cur;
  if(a < b) { // 01 better
    ll pz = count(all(t), 0), po = count(all(t), 1);
    ll sz = 0, so = 0;
    for(int i = n - 1; i >= 0; i--) {
      (t[i] ? po : pz)--;
      if(s[i] == '?') {
        cur -= a * so + b * po;
        t[i] = 1;
        cur += a * pz + b * sz;
        ans = min(ans, cur);
      }
      (t[i] ? so : sz)++;
    }
  }
  else { // 10 better
    ll pz = 0, po = 0;
    ll sz = count(all(t), 0), so = count(all(t), 1);
    for(int i = 0; i < n; i++) {
      (t[i] ? so : sz)--;
      if(s[i] == '?') {
        cur -= a * so + b * po;
        t[i] = 1;
        cur += a * pz + b * sz;
        ans = min(ans, cur);
      }
      (t[i] ? po : pz)++;
    }
  }
  writeln(ans);
  return 0;
}