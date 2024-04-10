#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  vector<ll> acc(n*2+1), free(n*2+1);
  for (int i = 0; i < n*2; i++) {
    acc[i+1] = acc[i]+a[i%n];
    free[i+1] = free[i]+!a[i%n];
  }
  ll ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      ll fa = (free[j]-free[i])*k, da = acc[j]-acc[i];
      ll fb = (free[i+n]-free[j])*k, db = acc[j]-acc[i+n];
      ll mi = max(da-fa,db-fb), ma = min(da+fa,db+fb);
      if (ma >= mi) {
        ans = max(ans, abs(ma)+1);
        ans = max(ans, abs(mi)+1);
      }
    }
  }
  cout << ans << endl;
}