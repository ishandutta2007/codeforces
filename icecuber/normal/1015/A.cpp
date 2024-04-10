#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> ok(m+1, 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; j++)
      ok[j] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans += ok[i];
  cout << ans << endl;
  for (int i = 1; i <= m; i++)
    if (ok[i]) cout << i << ' ';
  cout << endl;
}