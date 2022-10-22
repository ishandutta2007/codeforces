#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  ll mod = 1e9+7;
  int l = int(log2(n))+1;
  vector<vector<int>> v(1);
  for (int i = 0; i < l; i++)
    v[0].push_back(1<<i);
  if ((3<<l-2) <= n) {
    for (int i = 0; i < l-1; i++) {
      v.push_back({});
      int k = 1;
      for (int j = 0; j < l; j++) {
	v.back().push_back(k);
	k *= j==i ? 3 : 2;
      }
    }
  }
  ll tot = 0;
  for (auto v : v) {
    reverse(v.begin(), v.end());
    vector<int> c;
    ll sofar = 0;
    for (int i : v) {
      c.push_back(n/i-sofar);
      sofar = n/i;
    }
    assert(c[0] == 1);
    assert(c.size() == l);
    ll ans = 1;
    for (int i = 0; i < l; i++)
      (ans *= c[i]) %= mod;
    ll places = 1;
    for (int i = l-1; i >= 0; i--) {
      for (int j = 0; j < c[i]-1; j++) {
	(ans *= places++) %= mod;
      }
      places++;
    }
    assert(places == n+1);
    //cout << ans << endl;
    (tot += ans) %= mod;
  }
  cout << tot << endl;
}