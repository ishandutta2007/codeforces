#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(m, -n/m);
  vector<vector<pair<int,int>>> as(m);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    as[a%m].emplace_back(i, a);
    c[a%m]++;
  }
  int j = 0;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    while (c[i] > 0) {
      while (c[j] >= 0) j = (j+1)%m;
      int need = (j-i+n)%m;
      ans += need;
      auto [p, v] = as[i].back();
      as[i].pop_back();
      as[j].emplace_back(p, v+need);
      c[i]--;
      c[j]++;
    }
    if (i == j) j = (j+1)%m;
  }
  cout << ans << endl;
  vector<int> rec(n);
  for (int i = 0; i < m; i++) {
    for (auto [p, v] : as[i])
      rec[p] = v;
  }
  /*fill_n(c.begin(), m, -n/m);
  for (int i : rec) c[i%m]++;
  for (int i : c) assert(!i);*/
  for (int i : rec) cout << i << ' ';
  cout << endl;
}