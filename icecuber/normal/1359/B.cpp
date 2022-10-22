#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w, p1, p2;
    cin >> h >> w >> p1 >> p2;
    p2 = min(p2, p1*2);
    int ans = 0;
    for (int i = 0; i < h; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < w; j++) {
	if (row[j] == '.') {
	  if (j+1 < w && row[j+1] == '.') {
	    row[j+1] = '*';
	    ans += p2;
	  } else ans += p1;
	}
      }
    }
    cout << ans << endl;
  }
}