#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string source, target;
    cin >> source >> target;
    vector<int> pos[26];
    for (int i = 0; i < source.size(); i++) {
      pos[source[i]-'a'].push_back(i);
    }
    int ans = 1, curi = 0;
    for (char c : target) {
      auto&p = pos[c-'a'];
      if (p.empty()) goto fail;
      auto it = lower_bound(p.begin(), p.end(), curi);
      if (it == p.end()) it = p.begin(), ans++;
      curi = *it+1;
    }
    cout << ans << endl;
    continue;
  fail:
    cout << -1 << endl;
  }
}