#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll mi = 1, ma = n >= 32 ? k : ((1ll<<(n-1)*2)-1)/3+1;
    if (ma >= k) {
      cout << "YES " << n-1 << endl;
      continue;
    }
    for (int a = 2; a <= n; a++) {
      mi += (1ll<<a)-1;
      ll path_squares = (2ll<<a)-1;
      ll ma = ((path_squares+(((1ll<<a*2)-path_squares)<<(n-a)*2))-1)/3;
      if (mi <= k && ma >= k) {
	cout << "YES " << n-a << endl;
	goto next;
      }
    }
    cout << "NO" << endl;
  next:;
  }
}