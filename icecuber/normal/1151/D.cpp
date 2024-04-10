#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100000], b[100000], d[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ans += b[i]*(n-1);
    d[i] = b[i]-a[i];
  }
  sort(d, d+n);
  for (int i = 0; i < n; i++) {
    ans -= d[i]*i;
  }
  cout << ans << endl;
}