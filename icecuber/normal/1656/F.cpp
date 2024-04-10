#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    sort(a.begin(), a.end());
    vector<ll> acc(n+1);
    for (int i = 0; i < n; i++) 
      acc[i+1] = acc[i]+a[i];
    
    auto f = [&](ll t) {
      int k = lower_bound(a.begin(), a.end(), -t)-a.begin(); //a[k]+t >= 0
      return (a[0]+t)*(acc[n]-acc[k]+(n-k)*t)+(a[n-1]+t)*(acc[k]-acc[0]+k*t)-(a[0]+t)*(a[n-1]+t)-(n-1)*t*t;
    };
    if (acc[n]-acc[1] + a[0]*(n-1) > 0 || acc[n-1]-acc[0] + a[n-1]*(n-1) < 0) {
      cout << "INF" << endl;
      continue;
    }
    ll ans = f(0);
    for (ll t : a)
      ans = max(ans, f(-t));
    cout << ans << endl;
  }
}