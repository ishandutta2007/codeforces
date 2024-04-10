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
    vector<int> ans;
    for (int i = 0; i+5 <= n; i++) {
      if (s.substr(i, 5) == "twone") {
	s[i+2] = '!';
	ans.push_back(i+2);
      }
    }
    for (int i = 0; i+3 <= n; i++) {
      if (s.substr(i, 3) == "two") {
	s[i+1] = '!';
	ans.push_back(i+1);
      }
    }
    for (int i = 0; i+3 <= n; i++) {
      if (s.substr(i, 3) == "one") {
	s[i+1] = '!';
	ans.push_back(i+1);
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}