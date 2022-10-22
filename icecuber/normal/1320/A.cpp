#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  map<int,ll> m;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    m[b[i]-i] += b[i];
  }
  ll ans = 0;
  for (auto [x,v] : m) ans = max(ans, v);
  cout << ans << endl;
}