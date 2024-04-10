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
    vector<int> a(n),b(n),c(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    for (int&v : c) cin >> v;
    cout << a[0] << ' ';
    int last = a[0];
    for (int i = 1; i < n; i++) {
      for (int x : {a[i],b[i],c[i]}) {
	if (x == a[0] || x == last) continue;
	cout << x << ' ';
	last = x;
	break;
      }
    }
    cout << endl;
  }
}