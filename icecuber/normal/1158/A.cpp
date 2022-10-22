#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> b(n), g(m);
  for (int&v : b) cin >> v;
  for (int&v : g) cin >> v;
  sort(b.begin(), b.end());
  sort(g.begin(), g.end());
  if (g[0] < b.back()) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = g[0] == b.back() ? 0 : b[n-1]-b[n-2];
  for (int i = 0; i < n-1; i++) ans += 1ll*m*b[i];
  for (int i = 0; i < m; i++) ans += g[i];
  cout << ans << endl;
}