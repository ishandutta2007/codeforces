#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> node[26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) node[i].clear();
    for (int i = 0; i+1 < s.size(); i++) {
      int a = s[i]-'a', b = s[i+1]-'a';
      node[a].insert(b);
      node[b].insert(a);
    }
    string ans;
    int ok = 1;
    for (int i = 0; i < 26; i++) {
      int sz = node[i].size();
      if (sz == 0) {
	ans += string(1, i+'a');
      } else if (sz > 2) ok = 0;
    }
    vector<int> done(26);
    function<void(int)> dfs = [&](int p) {
      if (done[p]++) return;
      ans += string(1, p+'a');
      for (int i : node[p]) {
	dfs(i);
      }
    };
    if (ok) {
      for (int i = 0; i < 26; i++) {
	if (node[i].size() == 1 && !done[i]) dfs(i);
      }
    }
    if (ans.size() == 26) cout << "YES" << endl << ans << endl;
    else cout << "NO" << endl;
  }
}