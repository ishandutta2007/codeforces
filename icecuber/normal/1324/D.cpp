#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int&v : a) cin >> v;
  for (int&v : b) cin >> v;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(a[i]-b[i]);
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += v.end()-upper_bound(v.begin(), v.end(), -v[i]) - (v[i] > 0);
  }
  cout << ans/2 << endl;
}