#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mycount(ll n, ll p) {
  ll ans = 0;
  while (n) {
    n /= p;
    ans += n;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, b;
  cin >> n >> b;
  map<ll,ll> count;
  for (ll i = 2; i*i <= b; i++)
    while (b%i==0) count[i]++, b /= i;
  if (b > 1) count[b]++;
  ll ans = 2e18;
  for (auto p : count)
    ans = min(ans, mycount(n,p.first)/p.second);
  cout << ans << endl;
}