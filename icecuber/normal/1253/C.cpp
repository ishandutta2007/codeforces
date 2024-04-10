#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), sum(m);
  for (ll&v : a) cin >> v;
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sum[i%m] += a[i];
    ans += sum[i%m];
    cout << ans << ' ';
  }
  cout << endl;
}