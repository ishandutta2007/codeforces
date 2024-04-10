#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> node(n);
    vector<int> left(n);

    int goods = 0;
    set<int> cur;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      while (k--) {
        int a;
        cin >> a;
        a--;
        node[a].push_back(i);
        left[i]++;
      }
      if (!left[i]) {
        cur.insert(i);
      }
    }

    int ans = 0;
    while (cur.size() && goods < n) {
      ans++;
      set<int> nxt;
      auto it = cur.begin();
      while (it != cur.end()) {
        goods++;
        for (int i : node[*it]) {
          if (!--left[i]) {
            if (i < *it) nxt.insert(i);
            else cur.insert(i);
          }
        }
        ++it;
      }
      cur = nxt;
    }
    if (goods < n) cout << -1 << endl;
    else cout << ans << endl;
  }
}