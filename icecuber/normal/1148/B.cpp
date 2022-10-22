#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<ll> a(n),b(m);
  for (ll&v : a) cin >> v;
  for (ll&v : b) cin >> v;
  int j = 0;
  ll ans = -1;
  for (int i = 0; i <= k && i < n; i++) {
    while (j < m && b[j] < a[i]+ta) j++;
    if (j+(k-i) >= m || k >= n) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, b[j+(k-i)]+tb);
  }
  cout << ans << endl;
}