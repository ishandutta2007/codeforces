#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int x;
    cin >> s >> x;
    int n = s.size();
    string ans(n,'1');
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
	if (i >= x) ans[i-x] = '0';
	if (i+x< n) ans[i+x] = '0';
      }
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
      char c = '0';
      if (i >= x && ans[i-x] == '1') c = '1';
      if (i+x< n && ans[i+x] == '1') c = '1';
      ok &= (s[i] == c);
    }
    if (!ok) cout << -1 << endl;
    else cout << ans << endl;
  }
}