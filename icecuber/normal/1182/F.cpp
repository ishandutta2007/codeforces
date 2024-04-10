#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll s, d, p, q;
    cin >> s >> d >> p >> q;
    d = d+1-s;
    ll B = 30000;
    map<ll,int> m;
    ll mod = 2*q;
    auto add = [&](int i) {
      ll v = ((i*B+s) %mod* 2*p %mod+mod)%mod;
      if (!m.count(v))
	m[v] = i;
    };
    pair<ll,ll> ans(1e18,-1);
    for (int i = 0; i*B+B-1 < d; i++) add(i);
    for (int i = min(B,d)-1; i >= 0; i--) {
      if (d/B*B+i == d-1) add(d/B);
      ll v = 2*p*i %mod;
      for (ll t : {q,q*3}) {
	auto it = m.upper_bound(t-v);
	if (it != m.end())
	  ans = min(ans, {abs(it->first+v-t),it->second*B+i+s});
	if (it != m.begin())
	  ans = min(ans, {abs(prev(it)->first+v-t),prev(it)->second*B+i+s});
      }
    }
    cout << ans.second << endl;
  }
}