#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int one = -1, zero = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') zero = i;
      if (s[i] == '1' && one == -1) one = i;
    }
    if (one == -1 || zero == -1 || one > zero)
      cout << s << endl;
    else
      cout << s.substr(0,one)+s.substr(zero) << endl;
  }
}