#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int last[2][2] = {{-1,-1},{-1,-1}};
    ll ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != '?') {
        last[i%2][s[i]-'0'] = i;
      }
      ans += i-min(max(last[0][0],last[1][1]),
                   max(last[1][0],last[0][1]));
    }
    cout << ans << endl;
  }
}