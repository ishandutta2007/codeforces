#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h = 0, v = 0;
  string s;
  cin >> s;
  for (char c : s) {
    if (c == '1') {
      cout << 1 << ' ' << (v ? 1 : 3) << endl;
      v ^= 1;
    } else {
      cout << (h ? 1 : 3) << ' ' << 1 << endl;
      h ^= 1;
    }
  }
}