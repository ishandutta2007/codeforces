#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    int a_ = a+1;
    if ((a_&-a_) == a_) {
      int found = 0;
      for (ll i = 2; i*i <= a; i++) {
	if (a%i == 0) {
	  cout << a/i << endl;
	  found = 1;
	  break;
	}
      }
      if (!found) cout << 1 << endl;
    } else {
      int i = 0;
      while (a>>i) i++;
      cout << (1<<i)-1 << endl;
    }
  }
}