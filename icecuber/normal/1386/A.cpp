#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll base(ll n) {
  ll r = 0;
  ll pass = n, fail = 0;
  ll cur = 0, sign = 1;
  while (pass-fail > 1) {
    ll mid = (pass+fail)/2;
    cur += mid*sign;
    r = min(r, cur);
    sign *= -1;
    fail = mid;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;// = 10000;
  cin >> t;
  //mt19937_64 mrand(0);
  while (t--) {
    ll n;// = 100;//mrand()%ll(1e18)+1;
    cin >> n;
    //ll c = mrand()%n+1;

    /*ll last = -8e18;
      int queries = 0;
      set<ll> seen;*/
    auto query = [&](ll v) {
      cout << "? " << v << endl;
      int ans;
      cin >> ans;
      return ans;

      /*assert(seen.insert(v).second);
      assert(++queries <= 64);
      assert(v >= 1 && v <= n);
      ll ret = 0;
      if (last != -8e18)
	ret = abs(v-last) >= c;
      last = v;
      return ret;*/
    };

    ll pass = n, fail = 0;
    ll cur = 1-base(n);
    query(cur);
    ll sign = 1;
    while (pass-fail > 1) {
      ll mid = (pass+fail)/2;
      cur += mid * sign;
      sign *= -1;
      if (query(cur)) pass = mid;
      else fail = mid;
    }
    //assert(pass == c);
    cout << "= " << pass << endl;
  }
}