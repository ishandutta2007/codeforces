#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, p, k;
  cin >> n >> p >> k;
  map<ll,ll> count;
  while (n--) {
    ll a;
    cin >> a;
    count[((a*a%p*a%p*a%p-k*a)%p+p)%p]++;
  }
  ll ans = 0;
  for (auto p : count)
    ans += p.second*(p.second-1)/2;
  cout << ans << endl;
}