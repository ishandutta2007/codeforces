#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll lcm = 1;
    int ok = 1;
    set<int> dset;
    for (int i = 0; i < n; i++) {
      ll d;
      cin >> d;
      dset.insert(d);
      if (ok) {
	ll g = __gcd(d, lcm);
	lcm *= d/g;
	if (lcm > 1e12) ok = 0;
      }
    }
    if (ok) {
      if (*dset.rbegin() == lcm)
	lcm *= *dset.begin();
      int divisors = 0;
      for (ll i = 2; i*i <= lcm; i++)
	if (lcm%i == 0) divisors += 1+(i*i!=lcm);
      //cout << lcm << ' '<< divisors << ' '<< n << endl;
      if (divisors != n) ok = 0;
    }
    cout << (ok ? lcm : -1) << endl;
  }
}