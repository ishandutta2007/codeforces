#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string need = "abacaba", ans;
    for (int i = 0; i+(int)need.size() <= n; i++) {
      string got;
      for (int j = 0; j < n; j++) {
	if (s[j] == '?') {
	  got += (j >= i && j < i+(int)need.size() ? need[j-i] : 'z');
	} else
	  got += s[j];
      }
      int cnt = 0;
      for (int j = 0; j+(int)need.size() <= n; j++) {
	cnt += (got.substr(j, need.size()) == need);
      }
      if (cnt == 1)
	ans = got;
    }
    if (ans.empty()) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      cout << ans << endl;
    }
  }
}