#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
const int fnax = 1e6+10;
ll fac[fnax], ifac[fnax], inv[fnax];


ll num_swaps_less(string&x, string&bound) {
  ll ans = 0;
  int c[26] = {};
  for (char i : x) c[i-'a']++;
  for (int i = 0; i < bound.size(); i++) {
    int bi = bound[i]-'a';

    int sum = 0;
    ll part = 1;
    for (int i = 0; i < 26; i++) {
      sum += c[i];
      part = part*ifac[c[i]]%mod;
    }
    sum--;
    part = part*fac[sum]%mod;

    for (int j = 0; j < bi; j++) {
      if (c[j]) {
	(ans += part*fac[c[j]]%mod*ifac[c[j]-1]) %= mod;
      }
    }
    if (!c[bi]) break;
    c[bi]--;
  }
  return ans;
}

int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < fnax; i++) {
    inv[i] = i == 1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }

  ios::sync_with_stdio(0); cin.tie(0);
  string a, b;
  cin >> a >> b;
  string c = a;
  cout << ((num_swaps_less(c, b)-num_swaps_less(c, a)-1)%mod+mod)%mod << endl;
}