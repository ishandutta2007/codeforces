#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  set<int> p[26];
  for (int i = 0; i < s.size(); i++) {
    p[s[i]-'a'].insert(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      p[s[i]-'a'].erase(i);
      s[i] = c;
      p[s[i]-'a'].insert(i);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      int ans = 0;
      for (int i = 0; i < 26; i++) {
	auto it = p[i].lower_bound(l);
	if (it != p[i].end() && *it < r)
	    ans++;
      }
      cout << ans << '\n';
    }
  }
}