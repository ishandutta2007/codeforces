#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int b, p, f;
    cin >> b >> p >> f;
    int h, c;
    cin >> h >> c;
    int ans = 0;
    for (int x = 0; x <= p; x++)
      for (int y = 0; y <= f; y++)
	if (2*(x+y) <= b)
	  ans = max(ans, h*x+y*c);
    cout << ans << endl;
  }
}