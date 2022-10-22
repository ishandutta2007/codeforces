#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main() {
  ll n;
  cin >> n;
  ll fac = 1;
  ll ans = 0;
  for (int i = n; i; i--) {
    fac = (fac*i)%mod;
    ans -= fac;
  }
  ans = ((ans+fac*(n+1))%mod+mod)%mod;
  cout << ans << endl;
}