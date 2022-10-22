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
    string s;
    cin >> s;
    string a, b;
    int big = 0;
    for (char c : s) {
      int d = c-'0';
      if (big) {
	a += d+'0';
	b += '0';
      } else {
	if (d%2 == 0) {
	  a += d/2+'0';
	  b += d/2+'0';
	} else {
	  a += 0+'0';
	  b += 1+'0';
	  big = 1;
	}
      }
    }
    cout << b << endl;
    cout << a << endl;
  }
}