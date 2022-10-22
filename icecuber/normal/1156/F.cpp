#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
ll inv(ll a) {
  ll r = 1, p = mod-2;
  while (p) {
    if (p%2) r = r*a%mod;
    a = a*a%mod;
    p /= 2;
  }
  return r;
}

ll c[5000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    c[a]++;
  }
  vector<ll> dp(n, 0);
  for (int l = 1; l < n; l++) {
    vector<ll> dp2(n,0);
    ll acc = 0, il = inv(l);
    for (int i = n-1; i >= 0; i--) {
      dp2[i] = (acc+c[i]-1)*il%mod;
      (acc += c[i]*dp[i]) %= mod;
    }
    swap(dp, dp2);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    (ans += dp[i]*c[i]) %= mod;
  cout << (ans*inv(n)%mod+mod)%mod << endl;
}