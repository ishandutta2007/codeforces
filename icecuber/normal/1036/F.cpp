#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 64;
int mu[m], isprime[m];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  mu[1] = 1;
  for (int i = 2; i < m; i++) isprime[i] = 1, mu[i] = 1;
  for (int i = 2; i < m; i++) {
    if (!isprime[i]) continue;
    for (int j = i; j < m; j += i)
      isprime[j] = 0, mu[j] *= -1;
    for (int j = i*i; j < m; j += i*i)
      mu[j] = 0;
  }
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i < m; i++) {
      //cout << mu[i] << endl;
      if (!mu[i]) continue;
      ll root = pow(n,1./i);
      while (powl(root+1,i) <= n) root++;
      while (powl(root,i) > n) root--;
      //cout << root << ' ' << i << ' ' << n << endl;
      ans += (root-1)*mu[i];
    }
    cout << ans << endl;
  }
}