#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> A = {{2,4,1,3},
			 {2,4,1,3,5},
			 {1,4,2,5,3,6},
			 {1,5,2,6,3,7,4}};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << -1 << endl;
    } else {
      int base = 0;
      while (n >= 8) {
	for (int i = 0; i < 4; i++) cout << A[4-4][i]+base << ' ';
	n -= 4;
	base += 4;
      }
      for (int i = 0; i < n; i++) cout << A[n-4][i]+base << ' ';
      cout << endl;
    }
  }
}