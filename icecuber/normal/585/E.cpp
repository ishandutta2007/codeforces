#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e7+10;
int phi[nax], factor[nax];

ll mod = 1e9+7;
ll pow2[500001];

int dp[nax], dp2[nax];
int main() {
  fill_n(phi, nax, 1);
  fill_n(factor, nax, 1);
  for (int i = 2; i < nax; i++) {
    if (factor[i] != 1) continue;
    for (int j = i; j < nax; j += i)
      factor[j] = i, phi[j] *= -1;
    ll i2 = (ll)i*i;
    for (ll j = i2; j < nax; j += i2)
      phi[j] = 0;
  }

  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) {
    cin >> v;
    dp[v]++;
  }
  for (int i = 2; i < nax; i++) {
    if (factor[i] != i) continue;
    for (int j = (nax-1)/i; j; j--) {
      dp[j] += dp[j*i];
    }
  }
  assert(dp[1] == n);

  copy_n(dp, nax, dp2);

  pow2[0] = 1;
  for (int i = 0; i < n; i++) {
    pow2[i+1] = pow2[i]*2;
    if (pow2[i+1] >= mod)
      pow2[i+1] -= mod;
  }
  for (int i = 2; i < nax; i++) {
    dp[i] = pow2[dp[i]]-1;
  }
  for (int i = 2; i < nax; i++) {
    if (factor[i] != i) continue;
    for (int j = (nax-1)/i; j; j--) {
      if (phi[j] && phi[j*i]) {
	dp[j] -= dp[j*i];
	if (dp[j] < 0)
	  dp[j] += mod;
      }
    }
  }


  for (int i = 2; i < nax; i++) {
    if (factor[i] != i) continue;
    for (int j = (nax-1)/i; j; j--) {
      if (phi[j] && phi[j*i]) {
	//if (dp2[j*i] && dp2[j]) cout << dp2[6] << ' ' << j*i << ' ' << j << endl;
	dp2[j*i] -= dp2[j];
	if (dp2[j*i] < 0)
	  dp2[j*i] += mod;
      }
    }
  }

  ll ans = 0;
  for (int i = 2; i < nax; i++) {
    if (!phi[i]) continue;
    /*int c = 0;
    for (int v : a)
    if (__gcd(i,v) == 1) c++;*/
    ll c = dp2[i]*phi[i];
    //if (dp[i]) cout << i << ' ' << dp[i] << ' ' << c << endl;
    (ans += (ll)dp[i]*c) %= mod;
  }
  cout << (ans+mod)%mod << endl;
}