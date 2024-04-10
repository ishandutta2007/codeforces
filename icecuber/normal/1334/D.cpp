#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    ll done = 0, len = n*2-2;
    for (ll i = l; i < r; i++) {
      if (i == n*(n-1)) {
	cout << 1 << ' ';
	continue;
      }
      //cout << done << ' ' << i << ' ' << len << endl;
      while (done+len <= i) {
	done += len;
	len -= 2;
	assert(len);
      }
      if ((i-done)%2) cout << n-len/2+1+(i-done)/2 << ' ';
      else cout << n-len/2 << ' ';
    }
    cout << endl;
  }
}