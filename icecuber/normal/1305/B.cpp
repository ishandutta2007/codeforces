#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int l = 0, r = s.size()-1;
  vector<int> ans;
  while (l < r) {
    if (s[l] == ')') l++;
    else if (s[r] == '(') r--;
    else {
      ans.push_back(l++);
      ans.push_back(r--);
    }
  }
  if (ans.empty()) {
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << endl;
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i+1 << ' ';
  cout << endl;
}