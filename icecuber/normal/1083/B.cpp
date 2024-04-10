#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  string a, b;
  cin >> a >> b;
  ll va = 0, vb = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    va = va*2+a[i]-'0';
    vb = vb*2+b[i]-'0';
    ll d = 1+vb-va;
    if (d >= k) {
      ans += (n-i)*k;
      break;
    }
    ans += d;
  }
  cout << ans << endl;
}