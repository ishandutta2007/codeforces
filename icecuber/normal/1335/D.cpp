#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 9; i++) {
      string s;
      cin >> s;
      for (char c : s)
	cout << (c == '1' ? '2' : c);
      cout << endl;
    }
  }
}