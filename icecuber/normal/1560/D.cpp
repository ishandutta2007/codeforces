#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ans = 20;
    for (ll t = 1; t < 1ll<<61; t *= 2) {
      string d = to_string(t);
      int overlap = 0;
      int j = 0;
      for (char c : d) {
        while (j < (int)s.size() && s[j] != c) j++;
        if (j < (int)s.size() && s[j] == c) j++, overlap++;
      }
      ans = min(ans, int(s.size()+d.size())-overlap*2);
    }
    cout << ans << endl;
  }
}