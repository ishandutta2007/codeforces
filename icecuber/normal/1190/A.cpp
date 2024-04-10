#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> p(m);
  for (ll&v : p) cin >> v;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ll e = (p[i]-i-1)/k*k+k;
    int j = i;
    ans++;
    while (j < m && p[j]-i-1 < e) j++;
    i = j-1;
  }
  cout << ans << endl;
}