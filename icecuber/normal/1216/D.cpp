#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int z = 0;
  for (int i = 1; i < n; i++) {
    z = __gcd(z,abs(a[i]-a[0]));
  }
  ll y = 0, ma = *max_element(a, a+n);
  for (int i = 0; i < n; i++) {
    y += (ma-a[i])/z;
  }
  cout << y << ' ' << z << endl;
}