#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string goal = "CODEFORCES";
  string s;
  cin >> s;
  int ok = 0;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; i+j <= s.size(); j++) {
      if (s.substr(0,i)+s.substr(i+j,s.size()-(i+j)) == goal)
	ok = 1;
    }
  cout << (ok ? "YES" : "NO") << endl;
}