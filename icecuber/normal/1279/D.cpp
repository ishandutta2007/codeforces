#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+10;
ll w[nax];

const ll mod = 998244353;
#define inv fast_pow
ll fast_pow(ll a, ll p = mod-2) {
  if (p == 0) return 1;
  ll root = fast_pow(a, p/2);
  return root * root % mod * (p%2 ? a : 1) % mod;
}
/*
ll inv(ll a) {
  ll p = mod-2;
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}
*/
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
      a[i][j]--;
      (w[a[i][j]] += inv(n)*inv(k)) %= mod;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int k = a[i].size();
    for (int j = 0; j < k; j++) {
      (ans += w[a[i][j]]*inv(n)) %= mod;
    }
  }
  cout << (ans%mod+mod)%mod << endl;
}