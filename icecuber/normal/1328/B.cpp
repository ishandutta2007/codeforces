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
    k--;
    for (int i = n-2; i >= 0; i--) {
      if (k < n-1-i) {
	int j = n-1-k;
	string out(n,'a');
	out[i] = 'b';
	out[j] = 'b';
	cout << out << endl;
	break;
      }
      k -= n-1-i;
    }
  }
}