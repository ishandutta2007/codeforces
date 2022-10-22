#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int started = 0, ended = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'a' && !ended) {
      started = 1;
      s[i]--;
    } else if (started) {
      ended = 1;
    }
  }
  if (!started) s[s.size()-1] = 'z';
  cout << s << endl;
}