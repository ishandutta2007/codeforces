#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> x;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    x.push_back(p);
  }
  sort(x.begin(), x.end());
  for (ll d = 1; d < (1ll<<31); d *= 2) {
    for (int i = 0; i < n; i++) {
      if (binary_search(x.begin(), x.end(), x[i]-d) &&
	  binary_search(x.begin(), x.end(), x[i]+d)) {
	cout << 3 << endl;
	cout << x[i]-d << ' ' << x[i] << ' ' << x[i]+d << endl;
	return 0;
      }
    }
  }
  for (ll d = 1; d < (1ll<<31); d *= 2) {
    for (int i = 0; i < n; i++) {
      if (binary_search(x.begin(), x.end(), x[i]-d)) {
	cout << 2 << endl;
	cout << x[i]-d << ' ' << x[i] << endl;
	return 0;
      }
    }
  }
  cout << 1 << endl;
  cout << x[0] << endl;
}