#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+5;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> y(nax);
  vector<array<int,2>> a(n), b(m);
  for (auto&[u,v] : a) cin >> u >> v;
  for (auto&[u,v] : b) cin >> u >> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = b[j][0]-a[i][0];
      if (x >= 0) y[x] = max(y[x], b[j][1]+1-a[i][1]);
    }
  }
  int ans = 1e9;
  for (int i = nax-2; i >= 0; i--) {
    y[i] = max(y[i], y[i+1]);
    ans = min(ans, i+y[i]);
  }
  cout << ans << endl;
}