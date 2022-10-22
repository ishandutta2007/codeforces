#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int a = 0, b = s.size()-1;
  while (1) {
    if (a == b) {
      cout << 0 << endl;
      return 0;
    }
    char ca = s[a], cb = s[b];
    int a0 = a, b0 = b;
    while (a <= b && s[a] == ca) a++;
    while (a <= b && s[b] == cb) b--;
    if (ca != cb || a-a0+b0-b < 3 && a <= b) {
      cout << 0 << endl;
      return 0;
    }
    if (a > b) {
      cout << b0-a0+2 << endl;
      return 0;
    }
  }
}