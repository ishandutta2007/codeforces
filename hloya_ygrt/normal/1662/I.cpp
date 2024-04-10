#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  std::vector<pair<int, int>> ev;
  for (int i = 0; i < n; i++) {
    int y = i * 100;
    int v = lower_bound(x.begin(), x.end(), y) - x.begin();
    int d = std::numeric_limits<int>::max();
    if (v < m && std::abs(x[v] - y) < d) {
      d = std::abs(x[v] - y);
    }
    v--;
    if (v >= 0 && std::abs(x[v] - y) < d) {
      d = std::abs(x[v] - y);
    }
    if (d > 0) {
      ev.emplace_back(y - d, p[i]);
      ev.emplace_back(y + d, -p[i]);
    }
  }
  sort(ev.begin(), ev.end());
  int64_t bal = 0;
  int64_t ans = 0;
  for (int i = 0; i < ev.size(); i++) {
    bal += ev[i].second;
    ans = max(ans, bal);
  }
  cout << ans << "\n";
}


signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  int t;
    solve();
  return 0;
}