#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x, y, l, r;
  cin >> x >> y >> l >> r;
  vector<ll> unlucky;

  for (ld xa = 1; xa <= r; xa *= x) {
    for (ld yb = 1; xa+yb <= r; yb *= y) {
      if (xa+yb >= l)
	unlucky.push_back(xa+yb);
    }
  }
  unlucky.push_back(l-1);
  unlucky.push_back(r+1);
  sort(unlucky.begin(), unlucky.end());
  ll prev = l-1, ans = 0;
  for (ll v : unlucky) {
    ans = max(ans, v-prev-1);
    prev = v;
  }
  cout << ans << endl;
}