#include <bits/stdc++.h>
using namespace std;

int main() {
  string table;
  string s[5];
  cin >> table;
  int ok = 0;
  for (int i = 0; i < 5; i++) {
    cin >> s[i];
    if (s[i][0] == table[0] || s[i][1] == table[1]) ok = 1;
  }
  cout << (ok ? "YES" : "NO") << endl;
}