#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> acc = {0};
  for (int i = 0; i < (n+1)/2; i++) {
    ll a;
    cin >> a;
    acc.push_back(a+acc.back());
  }
  ll d;
  cin >> d;
  for (int i = 0; i < n/2; i++) {
    acc.push_back(d+acc.back());
  }
  vector<ll> a(n+1);
  for (int i = 0; i <= n; i++) {
    int m = (n+1)/2;
    a[i] = acc[i]-acc[m]+d*(m-i);
  }
  vector<ll> ma(n+2);
  ma[0] = a[0];
  for (int i = 1; i <= n; i++) {
    ma[i] = max(ma[i-1], a[i]);
  }
  for (int k = n/2+1; k <= n; k++) {
    int ok = !(k*d <= ma[n-k]);
    /*for (int i = 0; i+k <= n; i++) {
      assert(i+k >= (n+1)/2);
      int m = (n+1)/2;
      assert(acc[i+k] == acc[m]+(i+k-m)*d);
      //if (acc[i+k] <= acc[i]) ok = 0;
      if (k*d <= a[i]) ok = 0;
      }*/
    if (ok) {
      cout << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}