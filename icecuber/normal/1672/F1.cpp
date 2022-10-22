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
    vector<int> a(n);
    map<int,vector<int>> group;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      group[a[i]].push_back(i);
    }
    vector<int> b(n);
    while (group.size()) {
      vector<int> cycle, rem;
      for (auto&[x,v] : group) {
        cycle.push_back(v.back());
        v.pop_back();
        if (v.empty()) rem.push_back(x);
      }
      int m = cycle.size();
      for (int i = 0; i < m; i++) {
        b[cycle[i]] = a[cycle[(i+1)%m]];
      }
      for (int x : rem) group.erase(x);
    }
    for (int x : b) cout << x << ' ';
    cout << endl;
  }
}