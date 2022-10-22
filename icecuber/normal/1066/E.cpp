#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
int prefix[200001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  string a, b;
  cin >> na >> nb >> a >> b;
  for (int i = 0; i < nb; i++)
    prefix[i+1] = prefix[i]+(b[i]-'0');
  ll ans = 0, m = 1;
  for (int i = na-1; i >= 0; i--) {
    int j = nb-na+i+1;
    if (j > 0 && a[i]=='1')
      ans = (ans+prefix[j]*m)%mod;
    m = (m*2)%mod;
  }
  cout << ans << endl;
}