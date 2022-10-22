#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
    int m, ma = 0;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      ma = max(ma, a);
    }
    v.push_back({ma,m});
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (auto p : v)
    ans += 1ll*(v[0].first-p.first)*p.second;
  cout << ans << endl;
}