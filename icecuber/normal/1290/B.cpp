#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int acc[200005][26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < 26; j++) {
      acc[i+1][j] = acc[i][j] + (s[i] == 'a'+j);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    int c = 0;
    for (int j = 0; j < 26; j++) {
      if (acc[r][j]-acc[l][j]) c++;
    }
    cout << ((c == 1 && r-l > 1) || (c == 2 && s[l] == s[r-1]) ? "No" : "Yes") << '\n';
  }
}