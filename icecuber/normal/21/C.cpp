#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum%3) {
    cout << 0 << endl;
    return 0;
  }
  sum /= 3;
  int acc = 0;
  int ones = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    acc += a[i];
    if (acc == 2*sum && i != n-1)
      ans += ones;
    if (acc == sum) ones++;
  }
  cout << ans << endl;
}