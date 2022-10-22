#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int friends, days;
    cin >> friends >> days;
    vector<int> ans(days, -1);

    int failed = 0;
    int lim = (days+1)/2;
    vector<int> used(friends);
    vector<vector<int>> node(days);
    for (int i = 0; i < days; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int f;
        cin >> f;
        f--;
        node[i].push_back(f);
      }
      if (k == 1) {
        ans[i] = node[i][0];
        if (++used[ans[i]] > lim) failed = 1;
      }
    }

    for (int i = 0; i < days; i++) {
      if (ans[i] != -1) continue;
      int found = 0;
      for (int f : node[i]) {
        if (used[f] == lim) continue;
        found = 1;
        used[f]++;
        ans[i] = f;
        break;
      }
      if (!found) failed = 1;
    }
    if (failed) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    for (int i : ans) cout << i+1 << ' ';
    cout << endl;
  }
}