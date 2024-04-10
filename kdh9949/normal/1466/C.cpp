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
    string s;
    cin >> s;
    auto select = [&](string t) {
      sort(all(t));
      t.erase(unique(all(t)), t.end());
      for(int i = 0; i < t.length(); i++) if(t[i] != 'a' + i) return char('a' + i);
      return char('a' + t.length());
    };
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
      if(i > 0 && s[i] == s[i - 1])
        { ans++; s[i] = select(s.substr(max(0, i - 2), 5)); }
      else if(i > 1 && s[i] == s[i - 2])
        { ans++; s[i] = select(s.substr(max(0, i - 2), 5)); }
    }
    writeln(ans);
  }

  return 0;
}