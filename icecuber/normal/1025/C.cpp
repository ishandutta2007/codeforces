#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  s += s;
  int ans = 0, streak = 0;
  char last = ' ';
  for (char c : s) {
    ans = max(ans, streak);
    if (c == last) streak = 1;
    else streak++;
    last = c;
  }
  cout << min(ans, int(s.size())/2) << endl;
}