#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  vector<ll> good, bad;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > m) bad.push_back(a);
    else good.push_back(a);
  }
  sort(good.rbegin(), good.rend());
  sort(bad.rbegin(), bad.rend());
  for (int i = 1; i < good.size(); i++) {
    good[i] += good[i-1];
  }
  for (int i = 1; i < bad.size(); i++) {
    bad[i] += bad[i-1];
  }
  ll ans = 0;
  for (int x = 0; x <= n; x++) {
    int y = (n-x+d)/(d+1);
    if (x > good.size() || y > bad.size()) continue;
    ans = max(ans, (x ? good[x-1] : 0)+(y ? bad[y-1] : 0));
  }
  cout << ans << endl;
}