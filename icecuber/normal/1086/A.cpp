#include <bits/stdc++.h>
using namespace std;

int main() {
  int x[3], y[3], x2[3], y2[3];
  int minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
    x2[i] = x[i];
    y2[i] = y[i];
  }
  sort(x2, x2+3);
  sort(y2, y2+3);
  int mx = x2[1], my = y2[1];
  set<pair<int, int>> ans;
  for (int k = 0; k < 3; k++) {
    for (int i = min(y[k], my); i <= max(y[k], my); i++)
      ans.insert(make_pair(mx,i));
    for (int j = min(x[k], mx); j <= max(x[k], mx); j++)
      ans.insert(make_pair(j,y[k]));
  }
  cout << ans.size() << endl;
  for (auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}