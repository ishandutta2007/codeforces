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
    map<char, int> cnt;
    for (char c : s)
      cnt[c]++;
    int m;
    cin >> m;
    vector<int> b(m);
    for (int&v : b) cin >> v;
    string ans(m, '?');
    while (count(ans.begin(), ans.end(), '?')) {
      vector<int> put;
      for (int i = 0; i < m; i++) {
	if (b[i] == 0 && ans[i] == '?') {
	  put.push_back(i);
	}
      }
      char c = ' ';
      while (!cnt.count(c) || cnt[c] < (int)put.size()) {
	assert(cnt.size());
	if (cnt.count(c)) cnt.erase(c);
	c = cnt.rbegin()->first;
      }
      if (cnt.count(c)) cnt.erase(c);
      for (int i : put)
	ans[i] = c;
      for (int i : put) {
	for (int j = 0; j < m; j++) {
	  if (ans[j] == '?')
	    b[j] -= abs(i-j);
	}
      }
    }
    cout << ans << endl;
  }
}