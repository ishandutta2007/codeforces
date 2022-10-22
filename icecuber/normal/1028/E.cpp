#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  int up = -1, nonzeros = 0;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (b[i] < b[(i+1)%n]) up = (i+1)%n;
    nonzeros += !!b[i];
  }
  if (!nonzeros) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << "1 ";
    cout << endl;
    return 0;
  }
  if (up == -1) {
    cout << "NO" << endl;
    return 0;
  }
  a[up] = b[up];
  for (int i = 1; i < n; i++) {
    ll last = a[up];
    if (--up == -1) up += n;
    ll mi = b[(up+n-1)%n]+1;
    ll k = max((mi-b[up]+last-1)/last,0ll);
    a[up] = b[up]+k*last;
  }
  for (int i = 0; i < n; i++)
    assert(a[i]%a[(i+1)%n] == b[i]);
  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
}