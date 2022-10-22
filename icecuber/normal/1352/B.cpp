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
    if ((n-k)%2 == 0 && n >= k) {
      cout << "YES" << endl;
      for (int i = 0; i < k-1; i++)
	cout << 1 << ' ';
      cout << n-(k-1) << endl;
    } else if (n%2 == 0 && n >= k*2) {
      cout << "YES" << endl;
      for (int i = 0; i < k-1; i++)
	cout << 2 << ' ';
      cout << n-(k-1)*2 << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}