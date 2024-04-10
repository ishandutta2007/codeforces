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
    int f = (k%n != 0)*2;
    vector<vector<int>> ans(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (k) {
	  ans[j][(i+j)%n] = 1;
	  k--;
	}
      }
    }
    cout << f << endl;
    for (auto v : ans) {
      for (int i : v) cout << i;
      cout << endl;
    }
  }
}