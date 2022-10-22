#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int B = 700;
const int nax = 500001;
int a[nax];
int cache[B][B];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      a[x] += y;
      for (int i = 1; i < B; i++)
	cache[i][x%i] += y;
    } else {
      int m, r;
      cin >> m >> r;
      if (m < B) {
	cout << cache[m][r] << '\n';
      } else {
	int ans = 0;
	for (int i = r; i < nax; i += m)
	  ans += a[i];
	cout << ans << endl;
      }
    }
  }
}