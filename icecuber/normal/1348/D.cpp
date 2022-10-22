#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    vector<ll> ans;
    auto add = [&](vector<ll>&cand) {
      if (ans.empty() || cand.size() < ans.size())
	ans = cand;
    };
    for (int d = 0; (1ll<<d+1)-1 <= k; d++) {
      ll base = (1ll<<d+1)-1;
      vector<ll> cand;
      for (int i = 0; i < d; i++)
	cand.push_back(1ll<<i);
      ll n = 1ll<<d;
      ll t = k-base;
      if (t == 0) {
	add(cand);
      } else if (t >= n && t <= n*2) {
	cand.push_back(t-n);
	add(cand);
      } else if (t >= n*2 && t <= n*4) {
	//t-n*2 <= y <= t-n;
	//t/2 <= y <= t*2/3;
	ll y = min(t-n, t*2/3), x = t-y;
	assert(x >= n && x <= n*2);
	assert(y >= x && y <= x*2);
	cand.push_back(x-n);
	cand.push_back(y-x);
	add(cand);
      }
    }
    cout << ans.size() << endl;
    for (ll i : ans) cout << i << ' ';
    cout << endl;
  }
}