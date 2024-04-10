#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ons = count(s.begin(), s.end(), '1');
    int ans = ons;
    for (int i = 0; i < k; i++) {
      int acc = 0;
      int mi = 0, best = 0;
      int x = 0;
      for (int j = i; j < n; j += k) {
	acc += (s[j]-'0');
	x++;
	mi = min(mi, acc*2-x);
	best = min(best, mi-(acc*2-x));
      }
      ans = min(ans, best+acc+(ons-acc));
    }
    cout << ans << endl;
  }
}