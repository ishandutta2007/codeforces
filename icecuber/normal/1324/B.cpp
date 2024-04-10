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
    int ok = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+2; j < n; j++) {
	if (a[i] == a[j]) ok = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}