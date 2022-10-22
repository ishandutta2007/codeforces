#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> left;
  for (int i = 0; i <= n; i++) left.insert(i);
  vector<set<int>> reach(n+1);
  set<int> sick;

  auto Update = [&](int r) {
    vector<int> rem;
    for (int i : reach[r]) {
      if (i <= r) rem.push_back(i);
      else break;
    }
    for (int i : rem) reach[r].erase(i);

    if (r == n || reach[r].empty()) return;

    int nxt = *next(left.find(r));
    int mi = *reach[r].begin();
    if (mi <= nxt) sick.insert(r);
  };

  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      if (x == 0) {
        vector<int> rem;
        for (auto it = left.lower_bound(l); it != left.end() && *it < r; ++it) {
          rem.push_back(*it);
        }
        r = *left.lower_bound(r);
        for (int i : rem) {
          left.erase(i);
          if (reach[i].size() > reach[r].size()) swap(reach[i], reach[r]);
          for (int v : reach[i])
            reach[r].insert(v);
          reach[i].clear();
        }
        Update(r);
        {
          auto it = left.lower_bound(r);
          if (it != left.begin()) {
            Update(*prev(it));
          }
        }
      } else {
        assert(x == 1);
        l = *left.lower_bound(l);
        reach[l].insert(r);
        Update(l);
      }
    } else {
      assert(t == 1);
      int j;
      cin >> j;
      j--;
      if (sick.count(j)) cout << "YES" << endl;
      else if (left.count(j)) cout << "N/A" << endl;
      else cout << "NO" << endl;
    }
  }
}