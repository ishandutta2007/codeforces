#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> s;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    s.insert({a,b});
    s.insert({b,a});
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (!s.count({i,j})) {
	cout << "YES" << endl;
	int c = 3;
	for (int k = 0; k < n; k++) {
	  if (k == i) cout << 1 << ' ';
	  else if (k == j) cout << 2 << ' ';
	  else cout << c++ << ' ';
	}
	cout << endl;
	c = 3;
	for (int k = 0; k < n; k++) {
	  if (k == i) cout << 1 << ' ';
	  else if (k == j) cout << 1 << ' ';
	  else cout << c++ << ' ';
	}
	cout << endl;
	return 0;
      }
  cout << "NO" << endl;
}