#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> s(n);
  for (ll&i : s) cin >> i;
  sort(s.begin(), s.end());
  vector<ll> d(n, 1.1e18), acc(n+1,0);
  for (int i = 1; i < n; i++)
    d[i-1] = s[i]-s[i-1];
  sort(d.begin(), d.end());
  for (int i = 1; i <= n; i++)
    acc[i] = acc[i-1]+d[i-1];

  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    r -= l-1;
    int i = lower_bound(d.begin(), d.end(), r)-d.begin();
    cout << acc[i]+(n-i)*r << endl;
  }
}