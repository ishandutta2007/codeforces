#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int allequal = 1, pa = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != a[0]) allequal = 0;
      if (a[i] == a[(i+1)%n]) pa = i;
    }
    if (allequal) {
      cout << 1 << endl;
      for (int i = 0; i < n; i++)
	cout << 1 << ' ';
      cout << endl;
    } else {
      if (n%2 == 0 || pa != -1) {
	if (n%2 == 0) pa = -1;
	cout << 2 << endl;
	int col = 1;
	for (int i = 0; i < n; i++) {
	  cout << col << ' ';
	  if (i != pa) col = 3-col;
	}
	cout << endl;
      } else {
	cout << 3 << endl;
	cout << 3 << ' ';
	for (int i = 1; i < n; i++)
	  cout << i%2+1 << ' ';
	cout << endl;
      }
    }
  }
}