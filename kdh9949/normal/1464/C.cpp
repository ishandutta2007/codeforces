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

  ints(n);
  lls(k);
  string s;
  cin >> s;
  k -= (1 << (s.back() - 'a'));
  s.pop_back();
  n--;
  k += (1 << (s.back() - 'a'));
  s.pop_back();
  n--;

  vint c(26);
  for(int i = 0; i < n; i++) {
    c[s[i] - 'a']++;
    k += (1 << (s[i] - 'a'));
  }
  if((k & 1) || k < 0) { cout << "No\n"; return 0; }
  k /= 2;

  for(int i = 25; i >= 0; i--) {
    while(c[i]) {
      if(k < (1 << i)) break;
      c[i]--;
      k -= (1 << i);
    }
  }

  if(k == 0) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}