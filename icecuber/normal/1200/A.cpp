#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int taken[10] = {};
  while (n--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'L') {
      int i = 0;
      while (taken[i]) i++;
      taken[i] = 1;
    } else if (cmd == 'R') {
      int i = 9;
      while (taken[i]) i--;
      taken[i] = 1;
    } else {
      taken[cmd-'0'] = 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << taken[i];
  }
  cout << endl;
}