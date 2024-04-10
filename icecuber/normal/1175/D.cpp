#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  for (int i = n-2; i >= 0; i--)
    a[i] += a[i+1];
  sort(a.begin()+1, a.end());
  ll ans = 0;
  for (int i = n-k+1; i < n; i++)
    ans += a[i];
  cout << ans+a[0] << endl;
}