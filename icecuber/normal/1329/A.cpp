#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> mi(m+1),ma(m+1),l(m);
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> l[i];
    sum += l[i];
    if (i+l[i] > n) {
      cout << -1 << endl;
      return 0;
    }
    mi[i+1] = mi[i]+1;
    ma[i+1] = ma[i]+l[i];
  }
  if (sum < n) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < m; i++) {
    //p >= mi[i];
    //p <= ma[i];
    ll p = max(n+ma[i]-sum, mi[i]);
    cout << p+1 << ' ';
  }
  cout << endl;
}