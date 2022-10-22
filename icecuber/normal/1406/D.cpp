#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll sum = a[0];
  for (int i = n-1; i >= 1; i--) {
    a[i] -= a[i-1];
    if (a[i] > 0) sum += a[i];
  }
  auto add = [&](int i, int x) {
    if (i == 0) {
      a[0] += x;
      sum += x;
    } else if (i < n) {
      if (a[i] > 0) sum -= a[i];
      a[i] += x;
      if (a[i] > 0) sum += a[i];
    }
  };
  cout << (sum+(sum%2 != 0))/2 << '\n';
  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    add(l, x);
    add(r,-x);
    cout << (sum+(sum%2 != 0))/2 << '\n';
  }
}