#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    ans += (i+1)*(a-1)+1;
  }
  cout << ans << endl;
}