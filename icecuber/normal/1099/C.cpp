#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  int mi = 0, ma = 0, star = 0;
  for (char c : s) {
    if (c == '?') mi--;
    else if (c == '*') mi--, star = 1;
    else mi++,ma++;
  }
  if (mi <= k && ma+star*1e9 >= k) {
    if (star) {
      string ans;
      int done = 0;
      for (int i = 0; i < s.size(); i++) {
	if (i+1 < s.size() && (s[i+1] == '?' || s[i+1] == '*'));
	else if (s[i] == '*' && !done) {
	  for (int j = 0; j < k-mi; j++)
	    ans += s[i-1];
	  done = 1;
	} else if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
      }
      cout << ans << endl;
    } else {
      string ans;
      int cuts = ma-k;
      for (int i = 0; i < s.size(); i++) {
	if (i+1 < s.size() && s[i+1] == '?' && cuts) cuts--;
	else if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
      }
      cout << ans << endl;
    }
  } else {
    cout << "Impossible" << endl;
  }
}