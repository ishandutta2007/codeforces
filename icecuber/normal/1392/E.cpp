#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i%2 == 0)
	cout << (1ll<<i+j) << ' ';
      else
	cout << 0 << ' ';
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    ll sum;
    cin >> sum;
    vector<int> v;
    for (int i = 0; i < 60; i++) {
      if (sum>>i&1) {
	v.push_back(i);
      }
    }
    vector<pair<int,int>> path;
    int r = 0, c = -1;
    for (int i : v) {
      if (i == r+c+1) path.emplace_back(r,++c);
      else {
	path.emplace_back(++r,c);
	while (r+1+c < i) path.emplace_back(r,++c);
	path.emplace_back(++r,c);
      }
    }
    if (r < n-1) {
      path.emplace_back(++r,c);
      while (c < n-1) path.emplace_back(r,++c);
    }
    for (auto [x,y] : path) cout << x+1 << ' ' << y+1 << endl;
  }
}