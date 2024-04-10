#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    if (sa != sb) {
      cout << -1 << endl;
      continue;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = 0; j < n; j++)
	if (k < n && a[j] == b[k]) k++;
      ans = min(ans, n-k+i);
    }
    cout << ans << endl;
  }
}