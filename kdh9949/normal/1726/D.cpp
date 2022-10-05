#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  struct Edge { int x, y, i; };
  vector<Edge> e(m);
  for(int i = 0; i < m; ++i) {
    e[i].i = i;
    cin >> e[i].x >> e[i].y;
    if(e[i].x > e[i].y) swap(e[i].x, e[i].y);
  }

  vector<int> p(n + 1);
  const function<int(int)> f = [&](int x) {
    return p[x] = (x == p[x] ? x : f(p[x]));
  };
  const auto u = [&](int x, int y) {
    x = f(x); y = f(y);
    if(x == y) return 0;
    p[y] = x;
    return 1;
  };

  mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
  string ans;
  while(true) {
    shuffle(e.begin(), e.end(), mt);
    iota(p.begin(), p.end(), 0);
    ans = string(m, '0');
    vector<pair<int, int>> v;
    for(Edge &t : e) {
      if(!u(t.x, t.y)) {
        v.emplace_back(t.x, t.y);
        ans[t.i] = '1';
      }
    }
    sort(v.begin(), v.end());
    if(v.size() == 3 && v[0].first == v[1].first && v[1].second == v[2].second && v[0].second == v[2].first) continue;
    break;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}