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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (a[i][j] == '1' &&
	    i+1 < n && a[i+1][j] == '0' &&
	    j+1 < n && a[i][j+1] == '0')
	  ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}