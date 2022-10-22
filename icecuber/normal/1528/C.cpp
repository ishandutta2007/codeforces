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
    vector<vector<int>> childa(n), childb(n);
    for (int k : {0,1}) {
      auto&child = k ? childb : childa;
      for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        child[p].push_back(i);
      }
    }
    vector<array<int,2>> inv(n);
    int end = 0;
    function<void(int)> dfs1 = [&](int p) {
      inv[p][0] = end++;
      for (int i : childb[p]) {
        dfs1(i);
      }
      inv[p][1] = end;
    };
    dfs1(0);

    set<array<int,2>> cur;
    int ans = 0;
    function<void(int)> dfs2 = [&](int p) {
      //delete intersecting with inv[p]
      vector<array<int,2>> removed;
      while (1) {
        auto it = cur.lower_bound(array<int,2>{inv[p][1], -(int)1e9});
        if (it == cur.begin()) break;
        auto rm = *prev(it);
        if (rm[1] > inv[p][0] && rm[0] < inv[p][1]) {
          removed.push_back(rm);
          cur.erase(rm);
        } else break;
      }
      //add inv[p]
      cur.insert(inv[p]);
      ans = max(ans, (int)cur.size());
      for (int i : childa[p]) {
        dfs2(i);
      }
      cur.erase(inv[p]);
      for (auto i : removed) cur.insert(i);
    };
    dfs2(0);
    cout << ans << endl;
  }
}