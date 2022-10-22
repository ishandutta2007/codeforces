#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(a.begin(), a.end(), mrand);
  const int nax = 1e6;
  vector<int> isprime(nax, 1);
  vector<ll> prime;
  for (int p = 2; p < nax; p++) {
    if (!isprime[p]) continue;
    prime.push_back(p);
    for (int j = p*2; j < nax; j += p)
      isprime[j] = 0;
  }

  vector<ll> cands;
  for (int i = 0; i < n && i < 20; i++) {
    for (ll v : {a[i]-2,a[i]-1,a[i],a[i]+1,a[i]+2}) {
      if (v < 1) continue;
      for (ll p : prime) {
	if (v%p == 0) {
	  v /= p;
	  cands.push_back(p);
	  while (v%p == 0) v /= p;
	}
      }
      if (v > 1) cands.push_back(v);
    }
  }
  sort(cands.begin(), cands.end());
  cands.resize(unique(cands.begin(), cands.end())-cands.begin());
  ll ans = n;
  for (ll p : cands) {
    ll cost = 0;
    for (ll v : a) {
      if (v < p) cost += p-v;
      else {
	ll md = v%p;
	cost += min(md, p-md);
      }
      if (cost > ans) break;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}