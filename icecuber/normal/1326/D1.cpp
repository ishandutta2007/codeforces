#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef unsigned long long ull;
const int nax = 1e6+10;
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
const ull base = 137, mod = mrand()%(int(1e8))+1e9;

ull hpow[nax], ha[nax], hb[nax];

// a * b % mod, for a * b > 2^63
ull mul(ull a, ull b) {
  return a*b%mod;
  /*long long r = a*b-ull((long double)a*b/mod)*mod;
  while (r < 0) r += mod;
  while (r >= mod) r -= mod;
  return r;*/
}

ull getHash(ull*h, int i, int sz) {
  return (h[i+sz]-mul(hpow[sz], h[i])+mod)%mod;
}

int main() {
  hpow[0] = 1;
  for (int i = 1; i < nax; i++)
    hpow[i] = mul(hpow[i-1], base);

  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = 0, r = s.size()-1;
    string t;
    while (r > l && s[l] == s[r]) {
      t += s[l];
      l++, r--;
    }
    string rev = t;
    reverse(rev.begin(), rev.end());

    s = s.substr(l,r-l+1);

    int n = s.size();
    for (int i = 0; i < n; i++) {
      ha[i+1] = (mul(ha[i], base)+s[i])%mod;
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      hb[i+1] = (mul(hb[i], base)+s[i])%mod;
    }
    reverse(s.begin(), s.end());
    //cout <<  s << endl;
    //continue;
    for (int i = n; i >= 0; i--) {
      if (getHash(ha, 0, i) == getHash(hb, n-i, i)) {
	cout << t+s.substr(0, i)+rev << '\n';
	break;
      }
      if (getHash(hb, 0, i) == getHash(ha, n-i, i)) {
	cout << t+s.substr(n-i, i)+rev << '\n';
	break;
      }
    }
  }
}