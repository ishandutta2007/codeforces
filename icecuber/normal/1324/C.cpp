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
    int n = s.size();
    s += "R";
    int ans = 0, last = -1;
    for (int i = 0; i <= n; i++) {
      if (s[i] == 'R') {
	ans = max(ans, i-last);
	last = i;
      }
    }
    cout << ans << endl;
  }
}