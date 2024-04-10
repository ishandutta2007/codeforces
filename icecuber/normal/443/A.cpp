#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  getline(cin, s);
  int has[26] = {};
  for (char c : s) {
    int i = c-'a';
    if (i >= 0 && i < 26)
      has[i]++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
    ans += !!has[i];
  cout << ans << endl;
}