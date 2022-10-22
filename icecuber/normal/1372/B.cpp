#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll x = n;
    for (ll i = 2; i*i <= n; i++) {
      if (n%i == 0) {
	x = i;
	break;
      }
    }
    cout << (n/x) << ' ' << (x-1)*(n/x) << endl;
  }
}