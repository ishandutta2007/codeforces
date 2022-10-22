#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n), acc(n+1,0);
  for (ll&i : a) cin >> i;
  for (int i = 0; i < n; i++)
    acc[i+1] = acc[i]+a[i];
  ll ans = 0, left = 0;
  for (int i = n-1; i >= 0; i--) {
    if (a[i]/2+left >= a[i]%2+acc[i]) {
      //acc[i]+a[i]-k*2 >= left+k
      ll k = (acc[i]+a[i]-left)/3;
      ans += k;
      break;
    } else {
      left += a[i]/2;
      ans += a[i]/2;
      if (a[i]%2 && left) left--;
    }
    //cerr << ans << ' ' << left << endl;
  }
  //cerr << endl;
  cout << ans << endl;
}