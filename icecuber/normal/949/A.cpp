#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  stack<int> ones, zeros;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (ones.size()) {
	int p = ones.top();
	ones.pop();
	ans[p].push_back(i);
	zeros.push(p);
      } else {
	int p = ans.size();
	ans.push_back({i});
	zeros.push(p);
      }
    } else {
      if (!zeros.size()) {
	cout << -1 << endl;
	return 0;
      }
      int p = zeros.top();
      zeros.pop();
      ans[p].push_back(i);
      ones.push(p);
    }
  }
  if (ones.size()) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v.size();
    for (int i : v)
      cout << ' ' << i+1;
    cout << '\n';
  }
}