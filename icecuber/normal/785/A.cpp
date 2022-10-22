#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  while (n--) {
    string s;
    cin >> s;
    if (s[0] == 'I') ans += 20;
    else if (s[0] == 'T') ans += 4;
    else if (s[0] == 'C') ans += 6;
    else if (s[0] == 'D') ans += 12;
    else if (s[0] == 'O') ans += 8;
  }
  cout << ans << endl;
}