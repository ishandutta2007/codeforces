#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> r;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
      if (sum%2 && k > 1) {
	r.push_back(i+1);
	k--;
	sum = 0;
      }
    }
    if (sum%2 == 0) {
      cout << "NO\n";
    } else {
      r.push_back(n);
      cout << "YES\n";
      for (int i : r)
	cout << i << ' ';
      cout << '\n';
    }
  }
}