#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n[2], k[2];
  cin >> n[0] >> n[1] >> k[0] >> k[1];
  if (k[0] >= n[1] || k[1] >= n[0]) {
    cout << "No\n";
    return 0;
  }
  vector<int> v[2];
  for (int t = 0; t < 2; ++t) {
    v[t].resize(k[t]);
    for (auto& x : v[t]) {
      cin >> x;
      --x;
    }
    while ((int) v[t].size() < n[t ^ 1] - 1) {
      v[t].push_back(t ? n[0] : 0);
    }
  }
  vector<int> deg(n[0] + n[1]);
  for (int t = 0; t < 2; ++t) {
    for (int x : v[t]) {
      deg[x]++;
    }
    reverse(v[t].begin(), v[t].end());
  }
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < n[0] + n[1]; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  vector<pair<int, int>> es;
  for (int it = 0; it < n[0] + n[1] - 2; ++it) {
    int u = q.top();
    q.pop();
    int t = u < n[0];
    assert(!v[t].empty());
    int to = v[t].back();
    v[t].pop_back();
    es.emplace_back(u, to);
    if (--deg[to] == 0) {
      q.push(to);
    }
  }
  assert(q.size() == 2);
  {
    int u = q.top();
    q.pop();
    int v = q.top();
    q.pop();
    es.emplace_back(u, v);
  }
  cout << "Yes\n";
  for (auto [u, v] : es) {
    cout << u+1 << ' ' << v+1 << '\n';
  }
}