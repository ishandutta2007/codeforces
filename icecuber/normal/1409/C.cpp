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
    pair<int,vector<int>> best = {(int)2e9, {}};
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
	if ((y-x)%(j-i)) continue;
	vector<int> a(n);
	ll A = (y-x)/(j-i);
	ll B = x-A*i;
	if (B <= 0) continue;
	for (int k = 0; k < n; k++) {
	  //a[i] = x;
	  //a[j] = y;
	  a[k] = A*k+B;
	}
	best = min(best, make_pair(a.back(), a));
      }
    }
    for (int v : best.second)
      cout << v << ' ';
    cout << endl;
  }
}