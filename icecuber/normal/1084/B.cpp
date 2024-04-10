#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, s;
  cin >> n >> s;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < s) {
    cout << -1 << endl;
    return 0;
  }
  sort(a,a+n);
  s -= (sum-a[0]*n);
  if (s > 0)
    a[0] -= (s+n-1)/n;
  cout << a[0] << endl;
}