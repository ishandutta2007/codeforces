#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a,b);
  ll y = b-a;
  if (!y) {
    cout << 0 << endl;
    return 0;
  }

  ll lcm = 2e18, ans;
  for (ll k = 1; k*k <= y; k++) {
    if (y%k) continue;
    for (ll g : {k,y/k}) {
      ll x = ((a-1)/g+1)*g;
      ll v = (x+y)/g*x;
      if (v < lcm) {
	lcm = v;
	ans = x-a;
      }
    }
  }
  cout << ans << endl;
}