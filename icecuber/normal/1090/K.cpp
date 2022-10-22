#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<pair<string, int>, vector<int>> ans;
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s >> t;
    int mask = 0;
    for (char c : t)
      mask |= 1<<(c-'a');
    int e = s.size();
    while (e && (mask>>(s[e-1]-'a')&1)) e--;
    ans[{s.substr(0,e),mask}].push_back(i+1);
  }
  cout << ans.size() << '\n';
  for (auto&p : ans) {
    cout << p.second.size();
    for (int i : p.second)
      cout << ' ' << i;
    cout << '\n';
  }
}