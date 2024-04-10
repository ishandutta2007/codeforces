#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll t, n, a, b, k;
  cin >> t >> n >> a >> b >> k;
  ll na = (n+1)/2, nb = n/2;
  ll ans = (na*a+nb*b)/k;
  if (k > na) ans = min(ans, nb*b/(k-na));
  if (k > nb) ans = min(ans, na*a/(k-nb));
  ans = min(ans, t);
  if (k > n) ans = 0;
  cout << ans << endl;
}