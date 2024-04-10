#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 100001;
int mu[m];
int isprime[m];

ll mod = 1e9+7;
ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll ans[m];
vector<pair<int,int>> mu_list;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < m; i++) isprime[i] = mu[i] = 1;
  mu[1] = 1;
  for (int i = 1; i < m; i++) {
    if (!isprime[i]) continue;
    for (int j = i; j < m; j += i)
      mu[j] *= -1, isprime[j] = 0;
    for (ll j = 1LL*i*i; j < m; j += 1LL*i*i)
      mu[j] = 0;
  }
  for (int i = 1; i < m; i++)
    if (mu[i]) mu_list.emplace_back(i,mu[i]);

  int n;
  cin >> n;
  ll final_ans = 0;
  for (int a = 2; a <= n; a++) {
    ll sum_w = 0;
    /*ll sum_w_slow = 0;
    for (int i = 2; i <= n; i++)
    (sum_w_slow += ans[__gcd(i,a)]) %= mod;*/

    for (int b = 2; b*b <= a; b++) {
      if (a%b) continue;
      for (ll div : {b, a/b}) {
	ll w = 0;
	ll ad = a/div;
	for (ll i = 1; i*i <= ad; i++) {
	  if (ad%i) continue;
	  for (ll div2 : {i, ad/i}) {
	    w += n/(div2*div) * mu[div2];
	    if (div2*i == ad) break;
	  }
	}
	//cout << a << ' ' << div << ' ' << w << endl;
	(sum_w += w*ans[div]) %= mod;
	if (div == a/b) break;
      }
    }
    //cout << sum_w_slow << ' '<< sum_w <<endl;

    ans[a] = inv(n-n/a)*(n+sum_w)%mod;
    final_ans += ans[a];
  }
  final_ans = final_ans%mod*inv(n)+1;
  cout << (final_ans%mod+mod)%mod << endl;
}