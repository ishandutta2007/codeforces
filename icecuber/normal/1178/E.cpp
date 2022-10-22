#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int a = 0, b = s.size()-1;
  string ans;
  while (a < b) {
    if (s[a] == s[b]) {
      ans += s[a];
      a++, b--;
    } else if (a+1 < b-1) {
      if (s[a+1] == s[b]) {
	ans += s[a+1];
	a += 2;
	b--;
      } else if (s[a] == s[b-1]) {
	ans += s[a];
	a++;
	b -= 2;
      } else if (s[a+1] == s[b-1]) {
	ans += s[a+1];
	a += 2;
	b -= 2;
      } else assert(0);
    } else break;
  }
  string start = ans;
  reverse(ans.begin(), ans.end());
  if (a <= b) start += s[a];
  cout << start+ans << endl;
}