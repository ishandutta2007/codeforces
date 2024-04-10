#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    cout << clamp(x+y-n+3, 1, n) << ' ' << clamp(x+y+1, 1, n) << endl;
  }
  /*
  int n = 10;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      vector<int> lx(n), ly(n);
      for (int i = 0; i < n; i++) lx[i] = ly[i] = i;
      lx.erase(lx.begin()+x);
      ly.erase(ly.begin()+y);
      int mi = 1e9, ma = -1;
      do {
	int rank = 1;
	for (int i = 0; i < n-1; i++) {
	  rank += (lx[i]+ly[i] <= x+y);
	}
	mi = min(mi, rank);
	ma = max(ma, rank);
      } while (next_permutation(lx.begin(), lx.end()));
      assert(mi == clamp(x+y-n+3, 1, n));
      assert(ma == clamp(x+y+1, 1, n));
      cout << ma << ' ';
    }
    cout << endl;
    }*/

}