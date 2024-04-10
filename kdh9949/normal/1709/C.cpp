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
    strs(s);
    string t = s;
    int n = int(s.length()) / 2;
    int oc = n - count(all(s), '(');
    int cc = n - count(all(s), ')');
    int ci = -1, cj = -1;
    for(int i = 0, j = 0; i < 2 * n; i++) if(t[i] == '?') {
      if(j < oc) {
        t[i] = '('; 
        j++;
        if(j == oc) ci = i;
      }
      else {
        if(cj < 0) cj = i;
        t[i] = ')';
      }
    }
    if(ci < 0 || cj < 0) { cout << "YES\n"; return; }
    swap(t[ci], t[cj]);
    for(int i = 0, j = 0; i < 2 * n; i++) {
      if(t[i] == '(') j++;
      else j--;
      if(j < 0) { cout << "YES\n"; return; }
    }
    cout << "NO\n";
  };

  ints(t);
  //int t = 1;
  while(t--) solve();

  return 0;
}