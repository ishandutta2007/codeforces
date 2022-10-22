#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

ll a[300000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  ll ans = 0;
  for (int i = 0; i < n/2; i++) {
    ll s = a[i]+a[n-1-i];
    ans += s*s;
  }
  cout << ans << endl;
}