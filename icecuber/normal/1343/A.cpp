#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    for (int k = 2; ; k++) {
      ll sumk = ((1ll<<k)-1);
      if (n%sumk == 0) {
	cout << n/sumk << endl;
	break;
      }
    }
  }
}