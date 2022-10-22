#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<int> x;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    x.insert(p);
  }
  queue<pair<int,int>> q;
  auto add = [&](int p, int d) {
    for (int i : {p-1,p+1}) {
      if (x.count(i)) continue;
      x.insert(i);
      q.emplace(i, d+1);
    }
  };
  set<int> x0 = x;
  for (int p : x0) add(p, 0);

  vector<int> y;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    assert(q.size());
    auto [p,d] = q.front();
    q.pop();
    ans += d;
    y.push_back(p);
    add(p, d);
  }
  cout << ans << endl;
  for (int i : y) cout << i << ' ';
  cout << endl;
}