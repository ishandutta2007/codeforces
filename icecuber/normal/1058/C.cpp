#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int sum = 0; sum <= 1000; sum++) {
    int r = 0, c = 0, ok = 1;
    for (int i = 0; i < n; i++) {
      int d = s[i]-'0';
      if (r+d == sum) {
	c++;
	r = 0;
      } else if (r+d > sum) {
	ok = 0;
      } else {
	r += d;
      }
    }
    if (ok && c >= 2 && r == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}