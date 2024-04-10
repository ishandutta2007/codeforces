#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  map<char,int> count;
  for (char c : s) count[c]++;
  string ans;
  int lefts = (count['?']-count['(']+count[')'])/2;
  for (char c : s) {
    if (c == '?') {
      ans += lefts > 0 ? '(' : ')';
      lefts--;
    } else ans += c;
  }
  int acc = 0;
  for (int i = 0; i < n; i++) {
    acc += (ans[i] == '(')-(ans[i] == ')');
    int ok = 1;
    if (i == n-1) {
      if (acc) ok = 0;
    } else
      if (acc <= 0) ok = 0;
    if (!ok) {
      cout << ":(" << endl;
      return 0;
    }
  }
  cout << ans << endl;
}