#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll mod = 1e9+9;
  ll mul = 1, v = 1;
  ll ans = 2;
  for (int i = 2; i < n; i += 2) {
    (ans += v*4) %= mod;
    mul = (mul*2+3)%mod;
    (v *= mul) %= mod;
  }
  ans = (ans*ans+1)*2%mod;
  cout << ans << endl;
}