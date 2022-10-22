#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll ans = 0, a = (n+1)/2, b = n+1-a;
  while (m--) {
    ll x, d;
    cin >> x >> d;
    ans += n*x+max(d*n*(n-1)/2, d*(a*(a-1)/2+b*(b-1)/2));
  }
  cout << setprecision(20) << ans*1./n << endl;
}