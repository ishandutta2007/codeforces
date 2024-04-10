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
    int a = 0;
    while (n%2 == 0) a++, n /= 2;
    int win;
    if (n == 1) {
      win = (a == 1);
    } else {
      int isprime = 1;
      for (int i = 2; i*i <= n; i++) {
	if (n%i == 0) {
	  isprime = 0;
	  break;
	}
      }
      if (isprime) {
	win = (a != 1);
      } else {
	win = 1;
      }
    }
    cout << (win ? "Ashishgup" : "FastestFinger") << endl;
  }
}