#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[3][10];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  while (cin >> s)
    c[(s[1]=='p')+(s[1]=='s')*2][s[0]-'0']++;
  int ans = 3;
  for (int a = 0; a < 3; a++) {
    int*b = c[a];
    for (int i = 1; i <= 9; i++)
      ans = min(ans, max(0,3-b[i]));
    for (int i = 1; i+2 <= 9; i++)
      ans = min(ans, 3-!!b[i]-!!b[i+1]-!!b[i+2]);
  }
  cout << ans << endl;
}