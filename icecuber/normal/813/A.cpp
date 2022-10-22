#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  int m;
  cin >> m;
  int ans = 1e9;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (r >= sum) ans = min(ans, max(sum,l));
  }
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
}