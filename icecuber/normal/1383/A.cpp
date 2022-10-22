#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int need[20][20] = {};
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) ok = 0;
      if (a[i] != b[i])
	need[a[i]-'a'][b[i]-'a'] = 1;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      int has = -1;
      for (int j = 0; j < 20; j++) {
	if (need[i][j]) {
	  if (has != -1) need[has][j] = 1;
	  else has = j, ans++;
	}
      }
    }
    cout << ans << endl;
  }
}