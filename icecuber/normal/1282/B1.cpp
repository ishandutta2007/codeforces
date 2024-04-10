#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    sort(a.begin(), a.end());

    int pass = 0, fail = n+1;
    while (fail-pass > 1) {
      int mid = pass+fail>>1;
      ll cost = 0;
      for (int i = 0; i < mid%k; i++)
	cost += a[i];
      for (int i = mid-1; i >= k-1; i -= k)
	cost += a[i];

      int midb = (mid+k-1)/k*k;
      if (midb <= n) {
	ll costb = 0;
	for (int i = midb-1; i >= k-1; i -= k)
	  costb += a[i];
	cost = min(cost, costb);
      }

      if (cost <= p) pass = mid;
      else fail = mid;
    }
    cout << pass << endl;
  }
}