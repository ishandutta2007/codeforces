#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  ll m = 15, n = s.size();
  ll ans = n*(n-1)/2;
  for (int l = 2; l <= m; l++) {
    for (int i = 0; i+l <= n; i++) {
      int ok = 0;
      for (int a = 0; a < l; a++)
	for (int b = a+2; b < l; b += 2)
	  if (s[a+i] == s[b+i] && s[(a+b>>1)+i] == s[a+i]) {
	    ok = 1;
	    goto next;
	  }
    next:
      ans += ok-1;
    }
  }
  cout << ans << endl;
}