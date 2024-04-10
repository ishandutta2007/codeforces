#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll ma, mod;
    cin >> ma >> mod;
    ll ans = 1;
    for (int i = 0; i < 30; i++) {
      if ((1ll<<i)*2-1 <= ma) (ans *= (1ll<<i)+1) %= mod;
      else if ((1ll<<i) <= ma) (ans *= (ma+1-(1ll<<i))+1) %= mod;
    }
    cout << (ans+mod-1)%mod << endl;
  }
}