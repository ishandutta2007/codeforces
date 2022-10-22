#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int first = 1e9, last = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= x;
      if (a[i]) {
	first = min(first, i);
	last = max(last, i);
      }
      sum = (sum+a[i])%x;
    }
    if (last == -1) {
      cout << -1 << endl;
    } else if (sum) {
      cout << n << endl;
    } else {
      cout << max(n-first-1, last) << endl;
    }
  }
}