#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n*2);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  ll ans = (a[n-1]-a[0])*1ll * (a[n*2-1]-a[n]);
  for (int i = 0; i < n; i++) {
    ans = min(ans, ll(a[i+n-1]-a[i])*(a[n*2-1]-a[0]));
  }
  cout << ans << endl;
}