#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i <= s.size(); i++) {
    int m = 1;
    for (int j = 0; j < s.size(); j++) {
      if (j < i)
	m *= s[j]-'0';
      else if (j == i)
	m *= s[j]-'1' + (j == 0 && s[0] == '1');
      else
	m *= 9;
    }
    ans = max(ans, m);
  }
  cout << ans << endl;
}