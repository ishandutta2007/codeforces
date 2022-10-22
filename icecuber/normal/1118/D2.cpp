#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a+n, greater<ll>());
  if (sum < m) {
    cout << -1 << endl;
    return 0;
  }
  ll fail = 0, pass = n;
  while (pass-fail > 1) {
    ll mid = pass+fail>>1;
    ll wrote = 0;
    for (int i = 0; i < n; i++) {
      wrote += max(a[i]-i/mid, 0ll);
    }
    if (wrote >= m) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}