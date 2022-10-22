#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  //a+y = (x+y)*n;
  vector<array<ll,2>> x(n);
  for (int i = 0; i < n; i++) {
    ll sum = a[i]/n;
    x[i][1] = sum*n-a[i];
    x[i][0] = sum-x[i][1];
    assert(x[i][0]*n+x[i][1]*(n-1) == a[i]);
  }
  if (n-1) {
    cout << 1 << ' ' << n << endl;
    for (int i = 0; i < n-1; i++)
      cout << -x[i][0]*n << ' ';
    cout << 0 << ' ';
    cout << endl;
    cout << 1 << ' ' << n-1 << endl;
    for (int i = 0; i < n-1; i++)
      cout << -x[i][1]*(n-1) << ' ';
    cout << endl;
  } else {
    cout << n << ' ' << n << endl;
    cout << 0 << endl;
    cout << n << ' ' << n << endl;
    cout << 0 << endl;
  }
  cout << n << ' ' << n << endl;
  cout << -a[n-1] << endl;
}