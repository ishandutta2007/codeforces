#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      for (int k = j; k < n; k++)
	ans = max(ans, a[i]|a[j]|a[k]);
  cout << ans << endl;
}