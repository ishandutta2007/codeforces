#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5+10;
ll a[nax], p[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i+1] = p[i]+a[i];
  }
  ll ans = 0;
  for (int x = 0; x < m; x++) {
    ll mi[10] = {};
    fill_n(mi, m, 1e18);
    for (int r = 0; r <= n; r++) {
      ll v = m*p[r]-k*(r+x);
      mi[(r-x+m)%m] = min(mi[(r-x+m)%m], m*p[r]-k*r);
      ans = max(ans, (v-mi[r%m])/m);
    }
  }
  cout << ans << endl;
}