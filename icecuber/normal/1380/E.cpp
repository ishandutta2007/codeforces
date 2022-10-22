#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> t(m);
  int ans = n-1;
  auto take = [&](int i, int j) {
    ans += t[j].count(i-1);
    ans += t[j].count(i+1);
    t[j].erase(i);
  };
  auto put = [&](int i, int j) {
    ans -= t[j].count(i-1);
    ans -= t[j].count(i+1);
    t[j].insert(i);
  };
  for (int i = 0; i < n; i++) {
    int ti;
    cin >> ti;
    ti--;
    put(i, ti);
  }
  for (int it = 0; it < m-1; it++) {
    cout << ans << endl;
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (t[a].size() < t[b].size())
      swap(t[a], t[b]);
    auto cp = t[b];
    for (int i : cp) {
      take(i, b);
      put(i, a);
    }
  }
  cout << ans << endl;
}