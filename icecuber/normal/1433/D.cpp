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
    vector<int> a(n);
    set<int> s;
    for (int&v : a) cin >> v, s.insert(v);
    if (s.size() == 1) {
      cout << "NO" << endl;
      continue;
    }
    int x = 0;
    int y = 1;
    while (a[x] == a[y]) y++;
    cout << "YES" << endl;

    vector<pair<int,int>> ans;
    ans.push_back({x,y});
    for (int i = 0; i < n; i++) {
      if (i == x || i == y) continue;
      if (a[i] == a[x]) ans.push_back({i, y});
      else ans.push_back({i, x});
    }
    for (auto [u,v] : ans) cout << u+1 << ' ' << v+1 << endl;
  }
}