#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  ll low = -4e18, high = 2e9;
  ll lowf = 0, highf = 0;
  ll M = 1e6;
  for (int it = 0; it < 100; it++) {
    ll mid = (high+low)/2;
    ll midf = (highf+lowf)/2+(high+low)%2*(M/2);
    vector<ll> b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      ll pass = 0, fail = a[i]+1;
      while (fail-pass > 1) {
	ll m = (pass+fail)>>1;
	ll big = a[i]-m*m*3-mid;
	ll small = i-midf;
	big += small/M;
	small -= small/M;
	if (make_pair(big,small) >= make_pair(0ll,0ll)) pass = m;
	else fail = m;
      }
      b[i] = pass;
      sum += b[i];
    }
    if (sum == k) {
      for (ll v : b) cout << v << ' ';
      cout << endl;
      return 0;
    } else if (sum > k) low = mid, lowf = midf;
    else if (sum < k) high = mid, highf = midf;
    else assert(0);
    //cout << mid << ' ' << sum << ' ' << k << endl;
  }
  assert(0);
}