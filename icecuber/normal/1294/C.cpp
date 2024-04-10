#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll m = n;
    vector<pair<int,int>> facs;
    for (int i = 2; i*i <= n; i++) {
      if (n%i == 0) {
	int c = 0;
	while (n%i == 0) {
	  c++;
	  n /= i;
	}
	facs.emplace_back(i, c);
      }
    }
    if (n > 1) facs.emplace_back(n, 1);
    int x = -1, y = -1;
    if (facs.size() == 1) {
      if (facs[0].second >= 6) {
	int p = facs[0].first;
	x = p, y = p*p;
      }
    } else if (facs.size() == 2) {
      auto [a, ca] = facs[0];
      auto [b, cb] = facs[1];
      if (ca > 2 || cb > 2 || ca == 2 && cb == 2) {
	x = a, y = b;
      }
    } else {
      x = facs[0].first;
      y = facs[1].first;
    }
    if (x == -1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << x << ' ' << y << ' ' << m/(x*y) << endl;
    }
  }
}