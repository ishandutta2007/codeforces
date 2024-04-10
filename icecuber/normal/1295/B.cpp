#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int acc = 0;
    string s;
    cin >> s;
    int tot = 0;
    for (char c : s) tot += (c == '0')*2-1;
    int ans = 0;
    for (char c : s) {
      if ((tot > 0 && x-acc >= 0 && (x-acc)%tot == 0) ||
	  (tot < 0 && x-acc <= 0 && (x-acc)%tot == 0) ||
	  tot == 0 && x-acc == 0) ans++;
      acc += (c == '0')*2-1;
    }
    if (acc == 0 && ans) cout << -1 << endl;
    else cout << ans << endl;
  }
}